#include <erl_nif.h>
#include <vector>

using namespace std;

double dot(const vector<double> &a, const vector<double> &b) 
{
    double result = 0.0d;
    for (long i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

int add (int a, int b)
{
    return a + b;
}

inline bool fillVector(ErlNifEnv* env, ERL_NIF_TERM listTerm, vector<double> &result) 
{
    unsigned int length = 0;
    
    if (!enif_get_list_length(env, listTerm, &length)) {
        return false;
    }

    double actualHead;
    ERL_NIF_TERM head;
    ERL_NIF_TERM tail;
    ERL_NIF_TERM currentList = listTerm;
    for (unsigned int i = 0; i < length; ++i) {
        if (!enif_get_list_cell(env, currentList, &head, &tail)) {
            return false;
        }
        currentList = tail;
        if (!enif_get_double(env, head, &actualHead)) {
            return false;
        }
        result.push_back(actualHead);
    }

    return true;
}

ERL_NIF_TERM dot_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    vector<double> a;
    vector<double> b;
    
    if (!fillVector(env, argv[0], a)) {
        return enif_make_badarg(env);
    }
    if (!fillVector(env, argv[1], b)) {
        return enif_make_badarg(env);
    }
    
    double result = dot(a, b);
    return enif_make_double(env, result);
}

ERL_NIF_TERM add_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    int a = 0;
    int b = 0;
    
    if (!enif_get_int(env, argv[0], &a)) {
        return enif_make_badarg(env);
    }
    if (!enif_get_int(env, argv[1], &b)) {
        return enif_make_badarg(env);
    }
    
    int result = add(a, b);
    return enif_make_int(env, result);
}

ErlNifFunc nif_funcs[] = 
{
    {"dot", 2, dot_nif},
    {"add", 2, add_nif},
};

ERL_NIF_INIT(Elixir.Nativly, nif_funcs, nullptr, nullptr, nullptr, nullptr);