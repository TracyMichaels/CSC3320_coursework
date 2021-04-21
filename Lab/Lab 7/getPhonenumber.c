#include<stdio.h>

//Tracy Michaels Lab 7 Part 1 #1
//this program asks for users phonenumber in one format and 
//displays it in another

int main(){
    
    int phoneNumber[3];

    printf("Enter phone number [(999) 999-9999]: ");
    scanf("(%d) %d-%d", &phoneNumber[0], &phoneNumber[1], &phoneNumber[2]);
    //printf("\n");

    printf("You entered %d-%d-%d\n", phoneNumber[0], phoneNumber[1], phoneNumber[2]);

    return 0;
}