#!/bin/bash

# Function to display digits at odd positions
display_odd_digits() {
    number=$1
    length=${#number}
    
    # Check if the number has exactly five digits
    if [ $length -ne 5 ]; then
        echo "Error: Please enter a five-digit number."
        return 1
    fi
    
    echo "Digits at odd positions:"
    for (( i=0; i<$length; i+=2 )); do
        digit=${number:$i:1}
        echo $digit
    done
}

# Input five-digit number from the user
read -p "Enter a five-digit number: " input_number

# Call function to display digits at odd positions
display_odd_digits $input_number
