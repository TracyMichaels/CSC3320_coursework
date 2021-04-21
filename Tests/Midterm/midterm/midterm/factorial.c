#include<stdio.h>

// calculate the factorial of a given number

int main(int argc, char *argv[]){
    
    int result = 1;
    int i = 0;
    int num = atoi(argv[1]);

    if(num > 0){
        for(i = 1; i <= num; ++i){
            result *= i;
        }

        printf("%d! = %d\n", num, result);

    } else {
        printf("please use positive integer");
    }
    
    return 0;
}