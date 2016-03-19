#!/bin/bash
mkdir $1
cp modelo.cpp $1/$1.cpp
echo "file=$1" > $1/Makefile
cat Makefile >> $1/Makefile
