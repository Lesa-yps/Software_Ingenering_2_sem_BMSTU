#!/bin/bash

for file in func_tests/data/*; do
	if [ -f "$file" ]; then
		if [[ "${file}" == ../data/pos_??_in.txt ]]; then
			./app.exe < "$file" > "${file:0:15}""out.txt"
		fi
		if [[ "${file}" == ../data/neg_??_in.txt ]]; then
			./app.exe < "$file" > "${file:0:15}""out.txt"
		fi
	fi
done
