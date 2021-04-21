#!/bin/bash
#prompts user to enter a command
#if command it present in mandatabase.txt return relevent information
#must have mandatabase.txt in same directory

echo "Please type a command:"

read userIn

case $userIn in
    man)
        sed -rn  '/MAN\(1\)$/,/MAN\(1\)$/p' ./mandatabase.txt  
        ;;
    ls)
        sed -rn  '/LS\(1\)$/,/LS\(1\)$/p' ./mandatabase.txt 
        ;;
    grep)
        sed -rn  '/GREP\(1\)$/,/GREP\(1\)$/p' ./mandatabase.txt 
        ;;
    vim)
        sed -rn  '/VIM\(1\)$/,/VIM\(1\)$/p' ./mandatabase.txt 
        ;;
    sort)
        sed -rn  '/SORT\(1\)$/,/SORT\(1\)$/p' ./mandatabase.txt 
        ;;
    time)
        sed -rn  '/TIME\(1\)$/,/TIME\(1\)$/p' ./mandatabase.txt 
        ;;
    whoami)
        sed -rn  '/WHOAMI\(1\)$/,/WHOAMI\(1\)$/p' ./mandatabase.txt 
        ;;
    at)
        sed -rn  '/AT\(1\)$/,/AT\(1\)$/p' ./mandatabase.txt 
        ;;
    find)
        sed -rn  '/FIND\(1\)$/,/FIND\(1\)$/p' ./mandatabase.txt 
        ;;
    tar)
        sed -rn  '/TAR\(1\)$/,/TAR\(1\)$/p' ./mandatabase.txt 
        ;;
    *)
        echo 'Sorry, I cannot help you' 
        ;;
esac