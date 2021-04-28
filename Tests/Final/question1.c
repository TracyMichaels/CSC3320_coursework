#include<stdio.h>
#include<ctype.h>
#include<string.h>

//this program reads a file and returns:
// -- the number of characters including whitespaces (' ', '\n', '\t', '\v', '\f', '\r')
// -- the number of words (sequence of non-whitespace characters)
// -- number of lines
char* isNice(int n);

int main( int argc, char **argv ){

    char file_path[256];
    FILE *f;
    int currChar;
    int prevChar;
    int numCharacters = 0;
    int numWords = 0;
    //initialized to one to avoid fence-post problem
    int numLines = 1;

    // Checks for command line argument for file path
    // if none, prompts user to enter file path
    if(argc >= 2){
        strcpy(file_path, argv[1]);
    }else{
        printf("Enter file path: ");
        scanf("%s", file_path);
    } 
    //opens file in read mode
    if((f = fopen(file_path, "r")) == NULL){
        //printf("File not found\n");
        perror("Error");
        return 0;
    } 

    //logic loop
    while((currChar = fgetc(f)) != EOF){
        numCharacters++;
        if(currChar == '\n') numLines++;        
        if(isspace(currChar) && !isspace(prevChar)) numWords++;
        prevChar = currChar;
    }

    //display results
    printf("%10s: %d%s\n", "Characters", numCharacters, isNice(numCharacters));
    printf("%10s: %d%s\n", "Words", numWords, isNice(numWords));
    printf("%10s: %d%s\n", "Lines", numLines, isNice(numLines));

    //close file
    fclose(f);
    return 0;
}

char* isNice(int n){
    return (n == 69) ? "(nice)" : "";
}
