#!/bin/bash
#this script will compress files in the directory tree that have not been accesed
#in N days, where N is given by user

echo "Archive files not accessed in N days"
echo "Please input number(N) of days:"

read userIn

#doesn't work remove
#find ~/* -type f -atime +${userIn} | tar -cf ~/midterm/notaccessedin${userIn}days.tar 

#works
tar -cf ~/midterm/notaccessedin${userIn}days.tar $(find ~/* -type f -atime +${userIn})