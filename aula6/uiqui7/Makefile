file=uiqui7
test: debug
	./$(file) < input | diff - output
debug:
	g++ $(file).cpp -o $(file) -g -ansi -pedantic -Wall -Wno-long-long
