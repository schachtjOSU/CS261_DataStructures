/* CS261- Assignment 1 - Q.3*/
/* Name: Jeffrey Schachtsick
 * Date: 10/3/2015
 * Solution description:  Create an array of random numbers, then sort in ascending order.
 */
 
#include <stdio.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	int temp = 0;				// Temporary number to swap values to
	// Using Bubble Sort in Chapter 3 below
	// Outer loop
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			// Compare an element with next in the array, swap if needed
			if (number[j] > number[j + 1])
			{
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
	// Reference of the below line of code found for making a dynamic array here: http://stackoverflow.com/questions/4237896/im-very-confused-about-malloc-and-calloc-on-c
	int *ar = malloc(n * (sizeof(*ar)));
    /*Fill this array with random numbers, using rand().*/
    // Loop through ar and insert random numbers.
	for (int i = 0; i < n; i++)
	{
		// Insert a random number into ar, I suppose between 1 and 50
		ar[i] = rand() % 50 + 1;
	}
    /*Print the contents of the array.*/
	// Loop through ar and just print contents
	for (int i = 0; i < n; i++)
	{
		printf("The value of ar[%d] is: %d\n", i, ar[i]);
	}
    /*Pass this array along with n to the sort() function of part a.*/
	sort(ar, n);
    /*Print the contents of the array.*/    
	// Loop through ar and just print contents
	for (int i = 0; i < n; i++)
	{
		printf("The sorted value of ar[%d] is now: %d\n", i, ar[i]);
	}
	// Deallocate memory of the array of n integers
	free(ar);

    return 0;
}
