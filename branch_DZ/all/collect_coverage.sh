#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion --coverage -c ./*.c
gcc -o app.exe --coverage  ./*.o -lm

touch file.txt

./func_tests/scripts/func_tests.sh > file.txt
gcov ./main.c
