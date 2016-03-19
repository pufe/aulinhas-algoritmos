defmodule Chamada do
  def readline do
    IO.read(:line) |> String.strip
  end

  def main do
    [n,k] = (readline()
             |> String.split(" ")
             |> Enum.map(&(String.to_integer(&1))))
    IO.puts ((1..n)
             |> Enum.map(fn
               _ -> readline()
             end)
             |> Enum.sort(&(&1 < &2))
             |> Enum.at(k-1))
  end
end

Chamada.main()
