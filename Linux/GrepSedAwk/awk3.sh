#!/bin/bash
# Problem: ’Awk’ - 3
# Link: https://www.hackerrank.com/challenges/awk-3/problem
# Language: Bash

awk '{
    sum=0;
    for(i=2;i<=NF;i++){
        sum+=$i
    }
    avg=sum/3
    #print avg
    if(avg>=80) print $0,": A"
    else if(avg>=60) print $0,": B"
    else if(avg>=50) print $0,": C"
    else print $0,": FAIL"
    }'
