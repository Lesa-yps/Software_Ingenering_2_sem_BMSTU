#!/bin/bash

count=0

for file in func_tests/data/*; do
	if [ -f "$file" ]; then
		if [[ "${file}" == func_tests/data/pos_??_in.txt ]]; then
			./func_tests/scripts/pos_case.sh  "$file" "${file:0:23}""out.txt"
			if [[ $? == 1 ]]; then
				count=$((count+1))
				echo "${file} ERROR"
			else
				echo "${file} OK"
			fi
		fi
		if [[ "${file}" == func_tests/data/neg_??_in.txt ]]; then
			./func_tests/scripts/neg_case.sh  "$file" "${file:0:23}""out.txt"
			if [[ $? == 1 ]]; then
				count=$((count+1))
				echo "${file} ERROR"
			else
				echo "${file} OK"
			fi
		fi
	fi
done

echo "Failed $count tests."
