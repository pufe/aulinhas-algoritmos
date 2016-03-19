file=copa1
debug:
	g++ $(file).cpp -o $(file) -g -ansi -pedantic -Wall -Wno-long-long
	./$(file) < input | diff - output
