/* CS261- Assignment 1 - Q.4*/
/* Name: Jeffrey Schachtsick
 * Date: 10/3/2015
 * Solution description: Same in Q1 file where allocate memory to create a structure of 10 students with unique random IDs and 
	random scores.  Be able to do some stats with the scores and then finally deallocate memory.  However, sort the students
	in ascending order by there scores.
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
	int tempID = 0;				// Tempoorary ID storage
	int tempScore = 0;			// Temporrary student score storage
	
	// Using Bubble Sort Algorithm in Chapter 3 for below code
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			// Compare an element with next in the array, swap if needed
			if (students[j].score > students[j + 1].score)
			{
				tempID = students[j].id;
				tempScore = students[j].score;
				students[j].id = students[j + 1].id;
				students[j].score = students[j + 1].score;
				students[j + 1].id = tempID;
				students[j + 1].score = tempScore;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10;					// Number of students
    /*Allocate memory for n students using malloc.*/
	struct student* st = malloc(n * (sizeof(struct student)));

    /*Generate random IDs and scores for the n students, using rand().*/
	// Enter first ID and score for first student array
	st[0].id = rand() % n + 1;
	st[0].score = rand() % 100 + 0;

	// First loop to go through each student
	for (int i = 1; i < n; i++)
	{
		//Pick a random number between 1 and 10, pick random number between 0 and 100
		st[i].id = rand() % n + 1;
		st[i].score = rand() % 100 + 0;

		int stud = 0;					// Resets to first student, but tracks order of each student in array

		// Inner loop to search each student to catch unique ID numbers
		while (stud < i)
		{
			// Break from inner loop when number is not unique
			if (st[stud].id == st[i].id)
			{
				--i;					// Offsets outer loop from skipping student
				break;
			}
			else
				++stud;					// ID still unique, move on to next student
		}
	}

    /*Print the contents of the array of n students.*/
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", st[i].id, st[i].score);
	}

    /*Pass this array along with n to the sort() function*/
	sort(st, n);
    
    /*Print the contents of the array of n students.*/
	printf("\n Scores in Ascending Order:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", st[i].id, st[i].score);
	}

	/*Deallocate memory from stud*/
	//free(st->id);
	//free(st->score);
	free(st);
	system("pause");
    return 0;
}
