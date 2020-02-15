test: exec
	./exec < in | diff - out
exec: source.cpp
	g++ source.cpp -o exec -pedantic -std=gnu++11 -Wall
