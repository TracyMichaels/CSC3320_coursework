#include<stdio.h>
#include<string.h>

//Tracy Michaels
//This program sorts an array of strings and displays it in either 
//ascending or descending order
//based on user input

void sort_alphabet(char *arr[], int);
void display(char* a[], int);

int main(){
    //initialize array of strings
    char * array[] = {"Systems", 
                    "Programming", 
                    "Deep", 
                    "Learning", 
                    "Internet", 
                    "Things", 
                    "Robotics", 
                    "Course"};

    int size = sizeof array/ sizeof array[0];

    sort_alphabet(array, size);
    display(array, size);
    return 0;
}

//performs a bubble sort algorithm on array
void sort_alphabet(char* arr[], int num){
    
    int i,j;
    
    char *temp;

    for(i = 0; i < num - 1; i++){
        for(j = i+1; j<num; j++){
            if(strcasecmp(arr[i], arr[j]) >= 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
           }
        }
    }
}

//displays array in order according to user input
void display(char* a[], int n){
    char input[1];
    int index;
    printf("Sort by Ascending(A) or Descending(D): ");
    scanf("%s", input);

    switch(input[0]){
        case 'A':
        case 'a':
            for(index = 0; index < n; index++){
                printf("%s\n", a[index]);
            }
            break;
        case 'D':
        case 'd':
            for(index = 0; index < n; index++){
                printf("%s\n", a[n - 1 - index]);
            }
            break;
        default:
            printf("Invalid input");
    }
    printf("\n");

}