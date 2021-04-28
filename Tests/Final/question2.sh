#!/bin/bash

#this script counts the number of characters, words and lines in a file
#passed as a command line argument to the script
characters=$(wc -m < "$1")
words=$(wc -w < "$1")
lines=$(wc -l < "$1")
printf "Characters: %s\n" "$characters"
printf "Words: %s\n" "$words"
printf "Lines: %s\n" "$lines"