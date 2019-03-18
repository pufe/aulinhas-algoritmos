gets.to_i.times do
	m,n = gets.split.map(&:to_i)
	w = gets.downcase.split
	n.times do
		f = gets.downcase.split(/[: \n-]+/).map{|p| w.member?(p) ? p[0] : p[0].upcase}.join
		puts f[0]<'a' ? f : f[1..-1]
	end
	puts
end
