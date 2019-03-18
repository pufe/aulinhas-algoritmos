file=cometa2
test: debug
	./$(file).exe < input | diff - output
debug:
	g++ $(file).cpp -o $(file).exe -g -std=gnu++11 -pedantic -Wall -Wno-long-long
