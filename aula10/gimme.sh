#!/bin/bash

for i in $@; do
    mkdir $i
    cp modelo.cpp $i/$i.cpp
    echo "file=$i" | cat - Makefile > $i/Makefile
    touch $i/input $i/output
done
