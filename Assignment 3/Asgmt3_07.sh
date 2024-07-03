#!/bin/bash
echo "Enter name: "
read name
echo "Enter roll number: "
read roll
echo "Enter marks in subj1: "
read m1
echo "Enter marks in subj2: "
read m2
echo "Enter marks in subj3: "
read m3
echo "Enter marks in subj4: "
read m4
sum=`expr $m1 + $m2 + $m3 + $m4`
avg=`expr $sum / 4`
echo "Name: $name"
echo "Roll_No: $roll"
echo "Average marks: $avg"
if [ $avg -lt 50 ]
then
        echo "Fail"
elif [ $avg -ge 50 ] && [ $avg -lt 60 ]
then
        echo "C grade"
elif [ $avg -ge 60 ] && [ $avg -lt 70 ]
then
        echo "B grade"
elif [ $avg -ge 70 ] && [ $avg -lt 80 ]
then
        echo "A grade"
elif [ $avg -ge 80 ] && [ $avg -lt 90 ]
then
        echo "E grade"
else
        echo "O grade"
fi
