#!/bin/bash
#count the number of times a word entered by the user occurrs in a wikipedia page
#must have myexamfile.txt in same directory

echo 'Please enter a word:'

read userIn

num=$(grep -owi ${userIn} ./myexamfile.txt | wc -l)

if [ $num \> 0 ]
then
    echo "There are ${num} occurences of '${userIn}' in this file"
else
    echo "There are no occurances of '${userIn}' in this file"
fi

