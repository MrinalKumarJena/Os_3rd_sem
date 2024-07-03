#!/bin/bash

# Prompt the user to enter the filename
echo "Enter the filename:"
read filename

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' does not exist."
    exit 1
fi

# Count the number of characters, words, white spaces, and special symbols
characters=$(wc -m < "$filename")
words=$(wc -w < "$filename")
whitespaces=$(grep -o ' ' "$filename" | wc -l)
specialsymbols=$(grep -o '[^[:alnum:][:space:]]' "$filename" | wc -l)

# Display the results
echo "Number of characters: $characters"
echo "Number of words: $words"
echo "Number of white spaces: $whitespaces"
echo "Number of special symbols: $specialsymbols"
