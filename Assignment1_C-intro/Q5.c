/* CS261- Assignment 1 - Q.5*/
/* Name: Jeffrey Schachtsick
 * Date: 10/3/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	//Loop through the characters
	for (int i = 0; i < 20; i++)
	{
		// If not a valid character, break
		if (!isalpha(word[i]))
			break;
		// If integer is even, then it needs to be sent to upper case function
		if (i % 2 == 0)
		{
			// Check if the letter is already upper case, leave it if so
			if (!isupper(word[i]))
				word[i] = toUpperCase(word[i]);
		}
		// Otherwise, sent to lower case.
		else
		{
			// Check if the letter is already lower case, leave it if so
			if (!islower(word[i]))
				word[i] = toLowerCase(word[i]);
		}
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char word[20];				// A string with at most 20 characters
	printf("Enter your word here: ");
	scanf("%19s", word);

    /*Call sticky*/
	sticky(word);
    
    /*Print the new word*/
	printf("\nYour word new with Sticky caps is %s \n", word);
    return 0;
}
