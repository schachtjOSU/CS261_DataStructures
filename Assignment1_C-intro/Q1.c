/* CS261- Assignment 1 - Q.1*/
/* Name: Jeffrey Schachtsick
 * Date: 10/01/2015
 * Solution description:  Allocate memory to create a structure of 10 students with unique random IDs and 
	random scores.  Be able to do some stats with the scores and then finally deallocate memory.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* st = malloc(10 * (sizeof(struct student)));
     /*return the pointer*/
	return st;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int studentNum = 9;					// There are 10 students total 0-9 in array
	
	// Enter first ID and score for first student array
	students[0].id = rand() % 10 + 1;
	students[0].score = rand() % 100 + 0;

	// First loop to go through each student
	for (int i = 1; i <= studentNum; i++)
	{
		//Pick a random number between 1 and 10, pick random number between 0 and 100
		students[i].id = rand() % 10 + 1;
		students[i].score = rand() % 100 + 0;

		int stud = 0;					// Resets to first student, but tracks order of each student in array
		
		// Inner loop to search each student to catch unique ID numbers
		while (stud < i)
		{
			// Break from inner loop when number is not unique
			if (students[stud].id == students[i].id)
			{
				--i;					// Offsets outer loop from skipping student
				break;
			}
			else
				++stud;					// ID still unique, move on to next student
		}
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int studNum = 9;					// Number of students in array, 0 through 9

	// Loop through each array element in students struct
	for (int i = 0; i <= studNum; i++)
	{
		printf("%d %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int studNum = 9;					// Number of students in array, 0 through 9
	int min,							// Storage for minimum value
		max,							// Storage for maximum value
		total,							// Storage for adding all scores
		avg,							// Value for the average of all scores.
		temp;							// Compare score with minimum and max

	// Capture the first student's scores into min, max and total
	min = students[0].score;
	max = students[0].score;
	total = students[0].score;

	// Loop through the rest of the array elements capturing minimum, maximum and total scores
	for (int i = 1; i <= studNum; i++)
	{
		temp = students[i].score;
		temp = students[i].score;
		total += students[i].score;

		// Compare Minimum and Max
		if (temp < min)
			min = temp;
		if (temp > max)
			max = temp;
	}

	// Create the average
	avg = total / (studNum + 1);

	// Print Minimum score, Maximum score, and average scores
	printf("Minimum Score: %d\n", min);
	printf("Maximum Score: %d\n", max);
	printf("Average Score: %d\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	//free(stud->id);
	//free(stud->score);
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
