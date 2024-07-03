#!/bin/bash
echo "Enter a number :"
read a
c=`expr $a % 2`
if [ $c -eq 0 ]
then
echo "The number is even"
else
echo "The number is odd"
fi

