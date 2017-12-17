defmodule Nativly do
  @on_load :load_nifs
  
  def load_nifs do
    :erlang.load_nif('./nativly', 0)
  end
  
  def benchmark do
    n = 1_000_000
    a = vector(n)
    b = vector(n)

    {duration_ex, _} = :timer.tc(fn -> exdot(a, b) end)
    {duration_cpp, _} = :timer.tc(fn -> dot(a, b) end)
    
    IO.puts "For N = #{n}:"
    IO.puts "=============" 
    IO.puts "Elixir took #{duration_ex / 1_000_000}s"
    IO.puts "Native took #{duration_cpp / 1_000_000}s"
  end
  
  def dot(_a, _b) do
    raise "NIF dot/2 not implemented"
  end

  def exdot(a, b) do
    Enum.zip(a, b)
    |> Enum.map(fn {ea, eb} -> ea * eb end)
    |> Enum.reduce(&Kernel.+/2)
  end
  
  def add(_a, _b) do
    raise "NIF add/2 not implemented"
  end

  def vector(n) do
    0..n
    |> Enum.map(fn x -> x / 1 end)
    |> Enum.shuffle()
  end

  def rand_list(n) do
    0..n
    |> Enum.to_list()
    |> Enum.map(fn x -> x /1 end)
    |> Enum.shuffle()
  end
end
