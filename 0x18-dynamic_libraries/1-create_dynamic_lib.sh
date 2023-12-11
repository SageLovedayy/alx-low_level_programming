#!/bin/bash

#Compile source files to generate position-independent object files
gcc -c -fPIC *.c

#Create a shared library using the generated object files
gcc -shared -o liball.so *.o

#Clean up object files
rm *.o
