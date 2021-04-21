#include<stdio.h>
#include<string.h>

//Tracy Michaels
//This program tell user if an entered message is a palindrome

#define MAXIMUM 256

int isPalindrome(char *);

int main(){

    char message[MAXIMUM];

    printf("Enter Message: ");
    fgets(message, MAXIMUM, stdin);

    (isPalindrome(message)) ? printf("Is a Palindrome\n") : printf("Not a Palindrome\n");

    return 0;
}


//function to determine if a string is a palindrome
//returns 1 if it is a palindrome and
//0 if it is not
int isPalindrome(char *s){
    int i, j;
    for(i = 0, j = strlen(s) - 2; i <= strlen(s)/2; i++, j--){
        
        //skip white space
        if(s[i] == ' ') i++;
        if(s[j] == ' ') j--;

        if(i >= j){
            return 1;
        } else if(s[i] != s[j]){
            return 0;
        }
    }
}