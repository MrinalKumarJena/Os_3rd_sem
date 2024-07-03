#!bin/bash
echo "Enter the value of A and B:"
read a 
read b
echo "Before swapping:"
echo "A=$a And B=$b"
c=$a
a=$b
b=$c
echo "After swapping"
echo "A=$a And B=$b"
