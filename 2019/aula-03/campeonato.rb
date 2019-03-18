gets;l=gets.split.map(&:to_i);s=l.inject(:+)/2;l.each_with_index.inject(0){|a,(b,c)|puts c+1 if a+b==s;a+b}
