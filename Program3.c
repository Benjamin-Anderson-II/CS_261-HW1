/* CS261- HW1 - Program3.c*/
/* Name: Benjamin Anderson II
 * Date: 01/11/2023
 * Solution description:
    Randomly generates a dynamically allocated array of 20 integers
    and uses selection sort to sort them in ascending order
 */
 
#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int* number, int n){
     /*Sort the array of integers of length n*/
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i; j < n; j++)
            if(number[j] < number[min_idx])
                min_idx = j;
        swap(&number[min_idx], &number[i]);
    }
}

void output (int* ptr, int n){
    int i;
    for (i = 0; i < n-1; i++)
        printf("%d, ", ptr[i]);
    printf("%d\n\n", ptr[n-1]);
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int* ptr = (int*)malloc(n*sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    int i;
    for (i = 0; i < n; i++)
        ptr[i] = rand();


    /*Print the contents of the array.*/
    output(ptr, n);

    /*Pass this array along with n to the sort() function of part a.*/
    sort(ptr, n);

    /*Print the contents of the array.*/    
    output(ptr, n);
    
    free(ptr);

    return 0;
}
