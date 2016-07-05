/* CS261- Assignment 1 - Q.2*/
/* Name: Jeffrey Schachtsick
 * Date: 10/3/2015
 * Solution description:  Create 3 integers in main and then pass them to foo funciton.  Values in foo function
	will be modified as they are passed by reference, while a third will be returned to main.  Back in Main, the
	value will be assigned as the result of foo.  Each value will be printed.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a *= 2;
    /*Set b to half its original value*/
	*b /= 2;
    /*Assign a+b to c*/
	c = *a + *b;
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5,					// First integer value, will be doubled in foo
		y = 6,					// Second integer value, will be halfed in foo
		z = 7;					// Third integer value, sum of x and y after being halfed or doubled.
    /*Print the values of x, y and z*/
	printf("The value of x is: %d\n", x);
	printf("The value of y is: %d\n", y);
	printf("The value of z is: %d\n\n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
	int retValue = foo(&x, &y, z);
    /*Print the value returned by foo*/
	printf("The value returned by foo is: %d\n\n", retValue);
    /*Print the values of x, y and z again*/
	printf("The value of x after foo is: %d\n", x);
	printf("The value of y after foo is: %d\n", y);
	printf("The value of z after foo is: %d\n\n", z);
    /*Is the return value different than the value of z?  Why?*/
	/* Yes, the returned value is different than that of the value of z, because when calling foo() I'm only
	making a copy of the value to send to foo() and it will not be changed in the scope of main no matter what
	occurs in foo().*/
    return 0;
}
    
    
