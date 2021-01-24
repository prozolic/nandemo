#!/bin/bash

echo [`date`] nandemo_test build start
g++ -std=c++2a -O2 -W -Wall --pedantic-errors -o test.out test.cpp
./test.out

echo [`date`] nandemo_test build end