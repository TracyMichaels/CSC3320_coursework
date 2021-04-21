#include<stdio.h>
#include<string.h>

//Tracy Michaels
//System Level Programming Homework 4

//this program checks for the safty of a password
//password is unsafe if deductions are greater than 30 points
// - deduct 5 points for each character under length of 10
// - deduct 20 points for missing a lowercase letters
// - deduct 20 points for missing capital letters
// - deduct 20 points for missing letters
// - deduct 20 points for having consecutive characters

void checkLength(char *, int *);
void checkCriteria(char *, int *);
const char* checkSafty(int);

int main(){

    char inputPasswd[40];
    int deductions = 0;

    printf("Enter Password: ");
    scanf("%s", &inputPasswd);

    checkLength(inputPasswd, &deductions);
    checkCriteria(inputPasswd, &deductions);
    printf("%s", checkSafty(deductions));

    return 0;
}

//check if length of password is less than 10 characters long.
//deduct 5 points for every missing character
void checkLength(char *passwd, int *deduct){
    if((int) strlen(passwd) < 10){
        *deduct += (10 - ((int) strlen(passwd))) * 5;
    }
}

//returns if the password is safe or not
//safe if no more than 30 points have been deducted
const char* checkSafty(int deduction){
    printf("total deductions: %d\n", deduction);
    return (deduction > 30) ? "The password is unsafe! Please reset.\n" : "The password is safe\n";
}

void checkCriteria(char *passwd, int *deduct){
    char *p = passwd;
    int numCap = 0;
    int numLow = 0;
    int numNum = 0;
    int numConsecutive = 0;
    char prev;
    int i = 0;

    //TODO remove debugs
    for (i; passwd[i] != '\0'; i++){
        //printf("character: %c\n", passwd[i]);
        if(passwd[i] >= 'A' && passwd[i] <= 'Z') ++numCap;
        //printf("numCap: %d\n", numCap);
        if(passwd[i] >= 'a' && passwd[i] <= 'z') ++numLow;
        //printf("numLow: %d\n", numLow);
        if(passwd[i] >= '0' && passwd[i] <= '9') ++numNum;
        //printf("numNum: %d\n", numNum);
        if(passwd[i] == prev) numConsecutive++;
        //printf("numCon: %d\n", numConsecutive);
        prev = passwd[i];
    }

    if(numCap < 1) *deduct += 20;
    if(numLow < 1) *deduct += 20;
    if(numNum < 1) *deduct += 20;
    if(numConsecutive > 0) *deduct += 20;
}

