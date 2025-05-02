#!/bin/bash
# Problem: Filter an Array with Patterns
# Link: https://www.hackerrank.com/challenges/bash-tutorials-filter-an-array-with-patterns/problem
# Language: Bash


readarray -t arr
declare -a patter1=( ${arr[@]/*[Aa]*/} )
echo ${patter1[@]}
