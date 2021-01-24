#!/bin/bash

echo [`date`] nandemo build start
g++ -std=c++2a -O2 -W -Wall --pedantic-errors main.cpp
./a.out

echo [`date`] nandemo build end