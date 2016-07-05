/* CS261- Assignment 1 - Q. 0*/
/* Name: Jeffrey Schachtsick
 * Date: 10/01/2015
 * Solution description: In main, declare an integer called 'x', print the address of x, and 
	call fooA function with the address of x.  Within fooA, print the value pointed to by iptr,
	print the address pointed to by iptr, and print iptr address.  Finally print the value of x.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("The value pointed to by iptr is %d\n", *iptr);
     /*Print the address pointed to by iptr*/
	printf("The address pointed to by iptr is %p\n", iptr);
     /*Print the address of iptr itself*/
	printf("The address of iptr is %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x;
    /*print the address of x*/
	printf("Address of x is %p\n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("The value of x is %d\n", x);
    return 0;
}
