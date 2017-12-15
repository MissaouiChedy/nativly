defmodule Nativly do
  @on_load :load_nifs
  
  def load_nifs do
    :erlang.load_nif('./nativly', 0)
  end
  
  def dot(_a, _b) do
    raise "NIF dot/2 not implemented"
  end

  def rand_list(n) do
    0..n
    |> Enum.to_list()
    |> Enum.map(fn x -> x /1 end)
    |> Enum.shuffle()
  end

end
