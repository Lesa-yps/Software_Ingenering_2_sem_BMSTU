#!/bin/bash

touch file.txt
file_contents=$(<"$1")
my_word1=$(echo "$file_contents" | cut -d ' ' -f 1)
my_word2=$(echo "$file_contents" | cut -d ' ' -f 2)
./app.exe "$my_word1" "$my_word2" > file.txt
a=$?
if [[ $a != 0 ]]; then
	exit 0
else
	exit 1
fi
