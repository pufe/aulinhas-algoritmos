t=1
while(true) do
	break if gets.chomp.to_i==0
	puts("Teste %d" % t)
	puts(eval(gets))
	puts
end
