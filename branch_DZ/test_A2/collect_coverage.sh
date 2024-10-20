#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion --coverage -c ./*.c
gcc -o app.exe --coverage  ./*.o -lm

touch file.txt

for file in func_tests/data/*; do
  if [ -f "$file" ]; then 
    if [[ "${file}" == func_tests/data/pos_??_in.txt ]]; then
        ./app.exe  < "$file" > file.txt
    fi
    if [[ "${file}" == func_tests/data/neg_??_in.txt ]]; then
        ./app.exe < "$file" > file.txt
    fi
  fi
done

gcov ./Sorter.c
