#!/bin/bash
# Problem: Lonely Integer - Bash!
# Link: https://www.hackerrank.com/challenges/lonely-integer-2/problem
# Language: Bash

read size

read -a arr

result=${arr[0]}
for num in "${arr[@]:1}"; do
    result=$((result ^ num));
done 

echo $result
