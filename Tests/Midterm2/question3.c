#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Tracy Michaels
//This program sorts an array of strings given by user
//and stores them dynamically in an array
//and displays it in either 
//ascending or descending order
//based on user input

void sort_alphabet(char *arr[], int);
void display(char* a[], int);

int main(){

    char **array = malloc(1);
    int size = 0;
    char input[15];


    //get user input
    printf("Enter words ('q' to quit): \n");
    do{
        scanf("%s", input);
        array = (char **)realloc(array, (size + 1) * sizeof(char *));
        array[size++] = strdup(input);
    } while (strcasecmp(input, "q") != 0);



    //sort array and display      
    sort_alphabet(array, size -1);
    display(array, size -1);

    //deallocate memory for each element
    int i = 0;
    for(i = 0; i < size; i++){
        free(array[i]);
    }
        
    //deallocate array
    free(array);

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