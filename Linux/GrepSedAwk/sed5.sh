#!/bin/bash
# Problem: ’Sed’ command #5
# Link: https://www.hackerrank.com/challenges/sed-command-5/problem
# Language: Bash

sed -E 's/([0-9]{4}) ([0-9]{4}) ([0-9]{4}) ([0-9]{4})/\4 \3 \2 \1/'
