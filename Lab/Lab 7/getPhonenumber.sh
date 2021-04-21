#!/bin/bash

echo "Enter phone number [(999) 999-9999]: "

read phoneNumber

echo "You Entered ${phoneNumber}" | sed -e 's/(//g' -e's/) /-/g' 