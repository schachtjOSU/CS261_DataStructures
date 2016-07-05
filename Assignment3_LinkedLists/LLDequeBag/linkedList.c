#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
  /* FIXME: you must write this */
	// Set up the first sentinel
	lst->firstLink = malloc(sizeof(struct DLink));
	assert(lst->firstLink != 0);
	// Set up the end sentinel
	lst->lastLink = malloc(sizeof(struct DLink));
	assert(lst->lastLink);
	// Assign firstLink next to point to the end, Assign lastLink prev to point to beginning
	lst->firstLink->next = lst->lastLink;
	lst->lastLink->prev = lst->firstLink;
	lst->size = 0;								// Current size at initialization is 0
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
	
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */
	// Make sure lst is not Null
	assert(lst != NULL);
	// Make sure link prev is not NULL
	assert(l->value != NULL);
	// Make a temporary link
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// give the value to temp
	temp->value = v;
	// Point 'next' of temp to l and point 'prev of temp to l's 'prev'
	temp->next = l;
	temp->prev = l->prev;
	// Reassign links for l's prev next to temp and l prev to temp
	l->prev->next = temp;
	l->prev = temp;
	// Add to size
	lst->size++;
}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{

	/* FIXME: you must write this */
	// Make sure lst is not Null
	assert(lst != NULL);
	// Make a temporary link
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// give the value to temp
	temp->value = e;
	// Point 'next' of temp to firstLink's next and point 'prev' of temp to firstLink's next link of 'prev'
	temp->next = lst->firstLink->next;
	temp->prev = lst->firstLink;
	// Reassign links for firstLink next to temp and firstLink's next-prev to temp
	lst->firstLink->next->prev = temp;
	lst->firstLink->next = temp;
	// Add to size
	lst->size++;
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
	/* FIXME: you must write this */
	// Make sure lst is not Null
	assert(lst != NULL);
	// Make a temporary link
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// give the value to temp
	temp->value = e;
	// Point 'next' of temp to lastLink and point 'prev' of temp to LastLink's previous-next
	temp->next = lst->lastLink;
	temp->prev = lst->lastLink->prev;
	// Reassign lastLink's previous link of next to temp AND lastLink's prev to temp
	lst->lastLink->prev->next = temp;
	lst->lastLink->prev = temp;
	// Add to size
	lst->size++;
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */
	TYPE val;			// Value to be returned
	// Make sure the lst is not NULL
	assert(lst != NULL);
	// Make sure the list is not empty
	assert(!isEmptyList(lst));
	// Get the value of the link with data just after firstLink sentinel
	val = lst->firstLink->next->value;
	/*temporary return value...you may need to change this */
	return val;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	TYPE val;			// Value to be returned
	// Make sure the lst is not NULL
	assert(lst != NULL);
	// Make sure the list is not empty
	assert(!isEmptyList(lst));
	// Get the value of the link with data just before lastLink sentinel
	val = lst->lastLink->prev->value;
	/*temporary return value...you may need to change this */
	return val;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
	// Make sure the lst is not NULL
	assert(lst != NULL);
	// Make sure the l is not null
	assert(l != NULL);
	// Point the prev and next pointers to the previous and next links
	l->prev->next = l->next;
	l->next->prev = l->prev;
	// Free l
	free(l);
	// Reduce the size by one
	lst->size--;
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	/* FIXME: you must write this */
	// Make sure the lst is not NULL
	assert(lst != NULL);
	// Make sure the list is not empty
	assert(!isEmptyList(lst));
	// Point the firstLink-> next to the one after the first actual link
	lst->firstLink->next = lst->firstLink->next->next;
	// Point the prev of the second valued link to firstLink
	lst->firstLink->next->next->prev = lst->firstLink;
	// Free up the first valued link
	free(lst->firstLink->next);
	// Reduce the size by one
	lst->size--;
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
	/* FIXME: you must write this */
	// Make sure the lst is not NULL
	assert(lst != NULL);
	// Make sure the list is not empty
	assert(!isEmptyList(lst));
	// Point the lastLink->prev to the one before the last valued link
	lst->lastLink->prev = lst->lastLink->prev->prev;
	// Point the 2nd to last valued link->next to lastLink
	lst->lastLink->prev->prev->next = lst->lastLink;
	// Free up the first valued link
	free(lst->lastLink->prev);
	// Reduce the size by one
	lst->size--;
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	// Make sure the lst is not NULL
	assert(lst != NULL);
	/*temporary return value...you may need to change this */
	// Return true or false if the size is 0 or not
	return lst->size == 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* FIXME: you must write this */
	// Make sure the lst is not NULL
	assert(lst != NULL);
	// Create a temporary node to traverse the list
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// Assign temp to firstLink->next
	temp = lst->firstLink->next;
	// Loop through the list, until reach the end sentinel with NULL
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		// Move on to the next in the list
		temp = temp->next;
	}
}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	/* FIXME: you must write this */
	// Make sure the lst is not null
	assert(lst != NULL);
	// Make a temporary link
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// give the value to temp
	temp->value = v;
	// Point 'next' of temp to lastLink and point 'prev' of temp to LastLink's previous-next
	temp->next = lst->lastLink;
	temp->prev = lst->lastLink->prev;
	// Reassign lastLink's previous link of next to temp AND lastLink's prev to temp
	lst->lastLink->prev->next = temp;
	lst->lastLink->prev = temp;
	// Add to size
	lst->size++;
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	int exists = 0;			// Flag for if e is in the bag
	// Make sure lst is not Null
	assert(lst != NULL);
	// Make sure lst is not empty
	assert(!isEmptyList(lst));
	// Create a temporary node to traverse the list
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// Assign temp to firstLink->next
	temp = lst->firstLink->next;
	// Loop through the list, until reach the end sentinel with NULL
	while (temp != NULL)
	{
		// Conditional when value in temp has e
		if (temp->value == e)
		{
			exists = 1;
			break;
		}
		// Move on to the next in the list
		temp = temp->next;
	}
	/*temporary return value...you may need to change this */
	return exists;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	// Make sure lst is not null
	assert(lst != NULL);
	// Make sure lst is not empty
	assert(!isEmptyList(lst));
	// Create a temporary node to traverse the list
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// Assign temp to firstLink->next
	temp = lst->firstLink->next;
	// Loop through the list, until reach the end sentinel with NULL
	while (temp != NULL)
	{
		// Conditional when value in temp has e
		if (temp->value == e)
		{
			_removeLink(lst, temp);
			break;
		}
		// Move on to the next in the list
		temp = temp->next;
	}
}