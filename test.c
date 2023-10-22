#include <stdlib.h> 
#include <stdio.h>


int main (void){


    int* arr;
    int counter;
    int m = 100, n = 100;
    int temp[] = {1,2,3};

    arr = (int*)malloc(m*sizeof(int));
    *(arr+1) = temp;
    //*(arr+5) = (int*)malloc(m*sizeof(int));
    //*((arr+1)+5) = 10;

    printf("%d",*arr[0][1]);

}