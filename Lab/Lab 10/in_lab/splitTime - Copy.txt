#include<stdio.h>

void split_time(long, int *, int *, int *);

int main(){
    int n, hr, min, sec;
    printf("Enter seconds: ");
    scanf("%d", &n);

    split_time(n, &hr, &min, &sec);

    printf("Converted format: %d hour %d mins %d secs\n", hr, min, sec);
    
    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec){
    *sec = total_sec % 60;
    total_sec /= 60;
    *min = total_sec % 60;
    total_sec /= 60;
    *hr = total_sec % 24;    
}