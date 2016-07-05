/*******************************************************************
* Author:					Jeffrey Schachtsick
* Date Created:				09/27/2015
* Last Modification Date:	9/27/15
* Filename:					assign0.c
*
* Overview:
*		This program will essentially convert miles into kilometers
*		or will convert kilometers into miles.  The user will enter
*		into a loop until the user would like to quit.  However, while
*		in the loop, the user can select to do one of the 2 conversions
*		and the user can enter a value for it to be converted.
*
* Input:
*		The input will consist of the user typing in a selection for
*		either converting from miles to kilometers, from kilometers to miles
*		or to exit the program.  If the user selects to make a conversion,
*		then the user will type a value to be converted.
*		expected format selection:
*		1) Convert from miles to kilometers
*		2) Convert from kilometers to miles
*		3) Quit
*		Example input includes:
*		1 50
*		2 35
*		3
*
* Output:
*		The output will be the conversion from miles to kilometers or
*		from kilometers to miles.  The ouptut will be on the display for the
*		user to see the results.  Example of output is below from example 
*		input above.
*		
*		50 miles is 80.467 kilometers
*		35 kilometers is 21.747985 miles
*		Thank you for using my conversion program!
*
*
******************************************************************************/

#include <stdio.h>
#include <ctype.h>

// This function is to ask what conversion to try or quit program
char AskUserConvert(void);

// This function will convert miles to kilometers
void MilesToKiloMeter(void);

// This function will convert kilometers to miles
void KiloMeterToMiles(void);

// This is the main function to bigin execution of the program
int main(void)
{
	// Set variables
	_Bool quit = 0;		// Set to false to continue loop, otherwise will quit the program.
	char answer;		// Users answer to convert or quit program

	// Welcome message for user
	printf("Assignment 0 by Jeffrey Schachtsick\n");
	printf("Welcome to th miles and kilometer conversion program\n\n");
	printf("This program will convert from miles to kilometers and vice versa\n\n");

	// Start do...while loop until user wishes to exit program.
	do
	{
		// Function to ask what the user would like to do
		answer = AskUserConvert();

		// Switch and cases to select between different options.
		switch (answer)
		{
		case 'M':
		{
			// Function to convert miles to kilometers
			MilesToKiloMeter();
			break;
		}
		case 'K':
		{
			// Function to convert kilometers to miles
			KiloMeterToMiles();
			break;
		}
		case 'Q':
		{
			// Exit the program by making quit to true
			quit = 1;
			printf("Thank you for using my program!\n");
			break;
		}
		default:
			printf("I didn't understand\n");
			break;
		}

	} while (!quit);
	
	// Exit the program
	return 0;
}

/***********************************************
* Entry: None
*
* Exit: Return the character selection from the user called, answer.
*
* Purpose: Menu is displayed for user and the user types a selection from
*			that list.
*************************************************/ 
char AskUserConvert(void)
{
	// Set variable
	char answer;		// User selected answer
	
	printf("Conversion Menu:\n");
	printf("M) Miles to Kilometers\n");
	printf("K) Kilometers to Miles\n");
	printf("Q) Exit the program\n");
	printf("Enter the letter selection here: ");
	scanf(" %c", &answer);

	// Convert answer toupper
	answer = toupper(answer);
	printf("\n");
	return answer;
}

/***********************************************
* Entry: None
*
* Exit: no exit variables
*
* Purpose: User enters the miles to be converted.  Output will
*		display the result in kilometers.
*************************************************/
void MilesToKiloMeter(void)
{
	// Set variables
	double m = 1;							// miles variable
	double k = 1;							// kilometers variable
	const double KILO_CONVERT = 1.60934;	// Kilo conversion Number

	// Ask user what miles to enter
	printf("\nEnter the value of miles: ");
	scanf("%lf", &m);

	// Convert miles into kilometers
	k = m * KILO_CONVERT;

	// Print answer
	printf("%f mile(s) is %f kilometer(s).\n\n", m, k);
}

/***********************************************
* Entry: None
*
* Exit: no exit variables
*
* Purpose: User enters the kilometers to be converted.  Output will
*		display the result in miles.
*************************************************/
void KiloMeterToMiles(void)
{
	// Set variables
	double m = 1;							// miles variable
	double k = 1;							// kilometers variable
	const double MILE_CONVERT = 0.621371;	// Miles conversion number
	
	// Ask user what miles to enter
	printf("\nEnter the value of kilometers: ");
	scanf("%lf", &k);

	// Convert miles into kilometers
	m = k * MILE_CONVERT;

	// Print answer
	printf("%f kilometer(s) is %f mile(s).\n\n", k, m);
}
