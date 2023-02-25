/* CS261- HW1 - Program2.c*/
/* Name: Benjamin Anderson II
 * Date: 01/11/2023
 * Solution description:
     Creates a dynamically allocated array of 10 students with randomized
     initials and scores, prints them, then displays the minimum, maximum, 
     and average of the students
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* ptr = (struct student*)malloc(10*sizeof(struct student));
     /*return the pointer*/
     return ptr;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
     int i;
     char c1, c2;
     for(i = 0; i < 10; i+=1){
          c1 = rand()%26 + 'A';
          c2 = rand()%26 + 'A';
          students[i].initials[0] = c1;
          students[i].initials[1] = c2;
          students[i].score = rand()%101;
     }

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
     int i;
     for(i = 0; i < 10; i+=1){
          printf("%s  %d\n", students[i].initials, students[i].score);
     }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     struct student curr_student = students[0];
     int min_score = 100;
     int max_score = 0;
     int sum_score = 0;
     int i;
     for(i = 0; i < 10; i+=1){
          curr_student = students[i];
          max_score = (curr_student.score>max_score) ? curr_student.score : max_score;
          min_score = (curr_student.score<min_score) ? curr_student.score : min_score;
          sum_score += curr_student.score;
     }
     printf("Minimum Score: %d\nMaximum Score: %d\nAverage Score: %d\n", min_score, max_score, sum_score/10);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
