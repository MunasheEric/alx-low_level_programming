#!bin/bash
gcc -Wall -pedantic -Warroir -Wextra -c *.c
ar -rc liball.a *.o
ranlib liball.a
