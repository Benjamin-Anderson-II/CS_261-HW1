/* CS261- HW1 - Program4.c*/
/* Name: Benjamin Anderson II
 * Date: 01/12/2023
 * Solution description: 
    Creates a dynamically allocated array of random student structures and sorts
    them alphabetically through selection sort based on their initials.
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(int n){
    /*Allocate memory for ten students*/
    struct student* ptr = (struct student*)malloc(n*sizeof(struct student));
    /*return the pointer*/
    return ptr;
}

void generate(struct student* students, int n){
     /*Generate random initials and scores for ten students.
    The two initial letters must be capital and must be between A and Z. 
    The scores must be between 0 and 100*/
    int i;
    char c1, c2;
    for(i = 0; i < n; i++){
        c1 = rand()%26 + 'A';
        c2 = rand()%26 + 'A';
        students[i].initials[0] = c1;
        students[i].initials[1] = c2;
        students[i].score = rand()%101;
    }
}

void output(struct student* students, int n){
    /*Output information about the ten students in the format:
          1. Initials  Score
          2. Initials  Score
          ...
          10. Initials Score*/
    int i;
    for(i = 0; i < n; i+=1)
        printf("%s  %d\n", students[i].initials, students[i].score);
    printf("\n");
}

void swap(struct student* xp, struct student* yp) {
    struct student temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(struct student* students, int n){
    /*Sort n students based on their initials*/
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        /*sets the current minimum to i*/
        min_idx = i;
        for (j = i; j < n; j++)
            /*checks first initial*/
            if((students[j].initials[0] < students[min_idx].initials[0]) ||

                 /*if same first initial*/
                (students[j].initials[0] == students[min_idx].initials[0] &&
                /*checks second initial*/
                students[j].initials[1] < students[min_idx].initials[1])) 

                /*sets index of current minimum to j*/
                min_idx = j;

        /*swaps the current and found minimum*/
        swap(&students[min_idx], &students[i]);
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;

    /*Allocate memory for n students using malloc.*/
    struct student* students = allocate(n);

    /*Generate random initials and scores for the n students, using rand().*/
    generate(students, n);

    /*Print the contents of the array of n students.*/
    output(students, n);

    /*Pass this array along with n to the sort() function*/
    sort(students, n);

    /*Print the contents of the array of n students.*/
    output(students, n);

    free(students);

    return 0;
}
