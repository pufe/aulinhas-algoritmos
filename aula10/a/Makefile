file=a
test: $(file).exe
	./$(file).exe < input | diff - output

$(file).exe: $(file).cpp
	g++ -g -pedantic -std=gnu++11 -Wall -Wno-long-long -o$(file).exe $(file).cpp
