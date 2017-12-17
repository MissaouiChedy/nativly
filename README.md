# Nativly

Small and simple elixir application demonstrating the usage of [Nifs] from Elixir, containing the examples from thei ["Using C++ from elixir with nifs"](http://blog.techdominator.com/article/using-cpp-elixir-nifs.html) blog post.

## Installation

In order to build the native C++ code you will need the following:
 - [g++](https://gcc.gnu.org/) compiler
 - The Erlang dev package which contains `<erl_nif.h>`

## Usage

Checkout the `lib/nativly.ex` file, it contains the nifs.
Checkout the `native_lib/nativly.cpp` file, it contains the actual native implementation of the nifs.
