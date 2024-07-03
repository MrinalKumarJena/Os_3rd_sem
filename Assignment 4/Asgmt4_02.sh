#!/bin/bash

# Input five-digit number from the user
read -p "Enter a five-digit number: " number

# Iterate through each digit in the number
for (( i=0; i<${#number}; i+=2 )); do
    echo "${number:$i:1}"
done
