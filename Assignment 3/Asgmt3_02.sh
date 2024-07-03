#!/bin/bash
echo "Enter four values:"
read a
read b 
read c
read d
e=`expr $a + $b + $c + $d`
f=`expr $e / 4`
echo "Sum: $e"
echo "Avg: $f"
