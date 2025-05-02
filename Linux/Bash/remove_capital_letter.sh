#!/bin/bash
# Problem: Remove the First Capital Letter from Each Element
# Link: https://www.hackerrank.com/challenges/bash-tutorials-remove-the-first-capital-letter-from-each-array-element/problem
# Language: Bash

readarray -t arr

declare -a patter=( "${arr[@]/[A-Z]/.}" )

echo "${patter[@]}"
