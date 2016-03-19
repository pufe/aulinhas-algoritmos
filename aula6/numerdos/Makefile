file=uiqui7
test: debug
	./$(file) < input | diff - output
debug:
	g++ $(file).cpp -o $(file) -g -std=gnu++11 -pedantic -Wall -Wno-long-long
