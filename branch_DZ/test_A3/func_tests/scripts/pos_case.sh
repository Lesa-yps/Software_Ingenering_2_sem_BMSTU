#!/bin/bash

touch file.txt
./app.exe < "$1" > file.txt

a=$?
file="$1"

if [[ $a != 0 ]]; then
	exit 1
else
	./func_tests/scripts/comparator.sh "${file:0:23}""out_h.txt" "$2"
	exit $?
fi
