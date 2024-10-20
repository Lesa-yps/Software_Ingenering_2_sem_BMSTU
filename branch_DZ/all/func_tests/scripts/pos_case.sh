#!/bin/bash

touch file.txt
file_contents=$(<"$1")
my_word1=$(echo "$file_contents" | cut -d ' ' -f 1)
my_word2=$(echo "$file_contents" | cut -d ' ' -f 2)
./app.exe "$my_word1" "$my_word2"
file="$1"
a=$?
if [[ $a != 0 ]]; then
	exit 1
else
	./func_tests/scripts/comparator.sh "${file:0:23}""out_h.txt" "$2"
	exit $?
fi
