test: exec
	./exec < in | diff - out
exec: source.cpp
	g++ source.cpp -O2 -o exec -pedantic -std=c++11 -lm -Wall
