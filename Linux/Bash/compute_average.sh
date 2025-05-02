#!/bin/bash
# Problem: Compute the Average
# Link: https://www.hackerrank.com/challenges/bash-tutorials---compute-the-average/problem
# Language: Bash

read N
sum=0

for((i = 0; i < N; i++)); do
    read num
    sum=$((sum + num))
done

average=$(bc -l <<< "scale=4; $sum / $N")

printf "%.3f\n" "$average"
