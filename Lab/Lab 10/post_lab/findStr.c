#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    char input[20];
    char largestWord[20];
    char smallestWord[20];

    bool canEnterWord = true;

    while(canEnterWord){
        printf("Enter Word: ");
        scanf("%s", input);
        if(strlen(input) == 4){
            canEnterWord = false;
        }
        if(smallestWord[0] == '\0'){
            strcpy(smallestWord, input);
        }
        if(strcmp(input, smallestWord) <= 0){
            strcpy(smallestWord, input);
        }
        if(strcmp(input, largestWord) >= 0){
            strcpy(largestWord, input);
        }
    }
    printf("Smallest Word: %s\n", smallestWord);
    printf("Largest Word: %s\n", largestWord);
}


