file=bit
debug: $(file).exe
	./$(file).exe < input | diff - output
$(file).exe: $(file).cpp
	g++ -o $(file).exe -g -std=gnu++11 -pedantic -Wall -Wno-long-long $(file).cpp
