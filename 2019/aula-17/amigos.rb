def ack(m, n)
  if (m==0)
    n+1
  elsif (m==1)
    n+2
  elsif (m==2)
    2*n+3
  elsif (n==0)
    ack(m-1, 1)
  else
    x = ack(m-1, 1)
    n.times do
      x = ack(m-1, x)
    end
    x
  end
end
gets.chomp.to_i.times do
  puts(ack(*gets.split.map(&:to_i)))
end
