Data Structures
Assignment 1: C Programming Practice Assignment
Topics: Programming practice
Author: Jeffrey Schachtsick

** Files **
Q0.c
Q1.c
Q2.c
Q3.c
Q4.c
Q5.c
Assign1Makefile

** Compiling **
Each of the files included in this file have been compiled using Visual Studio 2013.  You could also compile the files using gcc.  It should be noted, the files should not be compiled together, but as seperate programs.  To compile them all at once, I have a created a makefile called Assign1Makefile which needs to be changed to makefile.

** Q0 Program **
In main, declare an integer called 'x', print the address of x, and call fooA function with the address of x.  Within fooA, print the value pointed to by iptr, print the address pointed to by iptr, and print iptr address.  Finally print the value of x.

** Q1 Program **
Allocate memory to create a structure of 10 students with unique random IDs and random scores.  Be able to do some stats with the scores and then finally deallocate memory.

** Q2 Program **
Create 3 integers in main and then pass them to foo funciton.  Values in foo function will be modified as they are passed by reference, while a third will be returned to main.  Back in Main, the value will be assigned as the result of foo.  Each value will be printed.

** Q3 Program **
Create an array of random numbers, then sort in ascending order.

** Q4 Program **
Same in Q1 file where allocate memory to create a structure of 10 students with unique random IDs and 	random scores.  Be able to do some stats with the scores and then finally deallocate memory.  However, sort the students in ascending order by there scores.

** Q5 Program **
Write a function void sticky(char* word) where word is a single word such as “sticky” or “RANDOM”. sticky() should modify the word to appear with “sticky caps” (http://en.wikipedia.org/wiki/StudlyCaps) , that is, the letters must be in alternating cases(upper and lower), starting with upper case for the first letter. For example, “sticky” becomes “StIcKy” and “RANDOM” becomes “RaNdOm”. Watch out for the end of the string, which is denoted by ‘\0’. You can assume that legal strings are given to the sticky() function. 



