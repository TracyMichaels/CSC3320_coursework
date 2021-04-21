#!/bin/bash

#this script runs the c programs in question 5
#asks for a number from user then passes that as argument to c scripts
#c scripts must have already been compiled as <name>.out

echo "Please enter a number:"
read userIn 

./factorial.out ${userIn}
./bitshift.out ${userIn}
