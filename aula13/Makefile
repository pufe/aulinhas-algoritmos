file=matricula_enterprise
debug: $(file).exe
	./$(file).exe < input | diff - output
$(file).exe: $(file).cpp
	g++ -o $(file).exe -g -ansi -pedantic -Wall -Wno-long-long $(file).cpp
