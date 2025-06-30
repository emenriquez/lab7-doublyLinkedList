#!/bin/bash

# Simple script to compile and run the tests
echo "Compiling StudentList tests..."

# Compile the test file with the StudentList implementation
g++ -std=c++11 -o test_program simple_tests.cpp StudentList.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Running tests..."
    echo ""
    ./test_program
else
    echo "Compilation failed. Please check your code for errors."
    exit 1
fi
