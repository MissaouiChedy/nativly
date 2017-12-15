defmodule NativlyTest do
  use ExUnit.Case
  doctest Nativly

  test "greets the world" do
    assert Nativly.hello() == :world
  end
end
