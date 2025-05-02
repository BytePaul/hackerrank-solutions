#!/bin/bash
# Problem: Arithmetic Operations
# Link: https://www.hackerrank.com/challenges/bash-tutorials---arithmetic-operations/problem
# Language: Bash

read -r expression

result=$(bc -l <<< "$expression")

printf "%.3f\n" "$result"
