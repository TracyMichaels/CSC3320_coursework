#include<stdio.h>

//Tracy Michaels
//This program sorts an array and displays it in either 
//ascending or descending order
//based on user input

void sort_numeric(float[], int);
void display(float[], int);
void swapFloats(float *, float *);

int main(){

    float array[] = {10, 0.25, 2342, 3.145435, 6, 6, 5.999, 2, 5, 109.56};
    int size = sizeof array/ sizeof array[0];

    sort_numeric(array, size);
    display(array, size);
    return 0;
}

//performs a bubble sort algorithm on array
void sort_numeric(float arr[], int num){
    int i,j;

    for(i = 0; i < num - 1; i++){
        for(j = i+1; j<num; j++){
            if(arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//displays array in order according to user input
void display(float a[], int n){
    char input[20];
    int index;
    printf("Sort by Ascending(A) or Descending(D): ");
    scanf("%s", input);

    switch(input[0]){
        case 'A':
        case 'a':
            for(index = 0; index < n; index++){
                printf("%f\n", a[index]);
            }
            break;
        case 'D':
        case 'd':
            for(index = 0; index < n; index++){
                printf("%f\n", a[n - 1 - index]);
            }
            break;
        default:
            printf("Invalid input");
    }
    printf("\n");

}