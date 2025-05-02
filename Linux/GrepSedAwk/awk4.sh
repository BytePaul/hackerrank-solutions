#!/bin/bash
# Problem: ’Awk’ - 3
# Link: https://www.hackerrank.com/challenges/awk-3/problem
# Language: Bash

awk 'ORS=NR%2?";":RS'
