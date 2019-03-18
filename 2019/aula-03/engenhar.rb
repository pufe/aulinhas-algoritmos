arr = (1..100).to_a
edges = arr.product(arr).select{|a,b| a<b}

def print_graph(edges)
  adj = {}
  edges.each do |a,b|
    adj[a] ||= []
    adj[a] << b
    adj[b] ||= []
    adj[b] << a
  end
  puts 100
  (1..100).each do |i|
    adj[i]||=[]
    puts "#{adj[i].size} #{adj[i].join(" ")}"
  end
end

def make_tests(cases, edges)
  puts cases.size
  cases.each do |s|
    print_graph(edges.sample(s))
  end
end

make_tests((3..20).map{|x|x*100}, edges)
