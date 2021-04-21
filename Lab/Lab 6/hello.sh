#!/bin/bash

#1. Greet user
echo 'Welcome to computer science society'

#2. comment section:
# Tracy Michaels
# tmichaels1@student.gsu.edu

#3. print date
date

#4. print the number of directories 
ls -l /home | grep '^d' | wc -l

#5. print value of variables PATH, USER, and SHELL
echo $PATH
echo $USER
echo $SHELL

#6. Print your disk usage
df

#7. Print Please, could you loan me $25.00?
echo 'Please, could you loan me $25.00?'

#8. Print if x = 2, x * x = 4, x / 2 = 1
echo 'if x=2, x*x=4, x/2=1'

#9. List all the .sh files with c at the beginning of the 
#   file name in current working directory.
ls | grep  '^c.*\.sh'

#10. Tell the user Good bye and the current hour
echo 'Good bye'
date +'%H'