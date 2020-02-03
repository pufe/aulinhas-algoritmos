SRC_FILES := $(wildcard *.cpp)
TEST_FILES := $(patsubst %.cpp,%.test,$(SRC_FILES))

all: $(TEST_FILES)

.SECONDARY:

%.exe: %.cpp
	g++ $< -o $@ -g -Wall -std=gnu++11

%.test: %.exe
	for i in $*.i*[^~]; do ./$< < $$i | diff - `echo $$i | sed s/\\\\.in/.out/`; done
	touch $@
