#include<stdio.h>

int main(){

    int letters;
    int words;
    char character;
    int isSpace = 0;

    printf("Enter a Sentence: ");

    while((character=getchar()) != '\n'){
        if(character != ' '){
            if(!isSpace){
                words++;
                isSpace = 1;
            }
            letters++;
        }else{
            isSpace = 0;
        }
    }

    printf("Average word length: %.1f\n", (double)letters/words);

    return 0;
}