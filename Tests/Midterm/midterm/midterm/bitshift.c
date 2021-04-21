#include<stdio.h>

//this program bit shifts an integer to the left by 3
// and then adds it to the complement

int main(int argc, char *argv[]){
    int num = atoi(argv[1]);
    int result;
    result = (num<<3) + (~num);
    printf("%d bit-shifted by 3 plus it's complement is: %d\n", num, result);

}