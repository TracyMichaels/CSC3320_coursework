#!bin/bash
#this script creates and maintains a phonebook that can be edited by user

#creates files if it doesn't already exists 
PBDB=./phonebookdb.txt
if [ ! -f $PBDB ]
then
    > phonebookdb.txt
fi

chmod 700 $PBDB

#prompt user
echo "Please select an option"
echo "type corresponding number below to select"
echo "1) create new contact"
echo "2) edit existing entry"
echo "3) remove entry"
echo "4) view entries"

read userSelection

case $userSelection in
    1)
        echo "First Name:"
        read fname
        echo "Last Name:"
        read lname
        echo "Address:"
        read address
        echo "Phone:"
        read phone

        echo "${fname}, ${lname}, ${address}, ${phone}" >> $PBDB
        ;;
    2)
        sort $PBDB | cat -n 
        echo "Please type name of entry you would like to edit"

        read editname

        sed -i  "/^${deleteentry}/d" $PBDB 


        echo "New First Name:"
        read fname
        echo "New Last Name:"
        read lname
        echo "New Address:"
        read address
        echo "New Phone:"
        read phone

        echo "${fname},${lname},${address},${phone}" >> $PBDB
        ;;
    3)
        sort $PBDB | cat -n
        echo "Please type name of entry you would like to delete"

        read deleteentry

        sed -i  "/^${deleteentry}/d" $PBDB 
        ;;
    4)
        sort $PBDB | cat -n
        ;;
    *)
        echo "Invalid input"
        ;;
esac

