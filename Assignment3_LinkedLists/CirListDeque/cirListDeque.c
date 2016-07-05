#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
  	/* FIXME: you must write this */
	// Make sure q is not null
	assert(q != NULL);
	// Set up the sentinel
	q->Sentinel = malloc(sizeof(struct DLink));
	// Assign the Sentinel to point to it's self for both next and prev
	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;
	// size equals zero
	q->size = 0;
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
	// Make a temporary link
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// add the value to temp
	temp->value = val;
	/*temporary return value..you may need to change it*/
	// Return the link
	return temp;	 

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */	 
	// Make sure q and lnk is not NULL
	assert(q != NULL);
	assert(lnk != NULL);
	// Check if lnk is in the deque?????????????????????????
	// Make a new link with the value
	struct DLink *newLink = _createLink(v);
	// Add the newLink after lnk.  Point newLink prev to lnk and next to lnk->next
	newLink->prev = lnk;
	newLink->next = lnk->next;
	// Point lnk->next prev to newLink and lnk->next to newLink
	lnk->next->prev = newLink;
	lnk->next = newLink;
	// Add to size
	q->size++;
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */	 
	// Make sure q is not nulll
	assert(q != NULL);
	// Make a new link with the value
	struct DLink *newLink = _createLink(val);
	// Add the newLink after the last link and before Sentinel.  
	// Point newLink prev to Sentinel->prev->next AND next to Sentinel
	newLink->prev = q->Sentinel->prev;
	newLink->next = q->Sentinel;
	// Point Sentinel->prev next to newLink and Sentinel->prev to newLink
	q->Sentinel->prev->next = newLink;
	q->Sentinel->prev = newLink;
	// Add to size
	q->size++;
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */	 
	// Make sure q is not nulll
	assert(q != NULL);
	// Make a new link with the value
	struct DLink *newLink = _createLink(val);
	// Add the newLink after the last link and before Sentinel.  
	// Point newLink next to Sentinel->next->prev AND prev to Sentinel
	newLink->next = q->Sentinel->next;
	newLink->prev = q->Sentinel;
	// Point Sentinel->next prev to newLink and Sentinel->next to newLink
	q->Sentinel->next->prev = newLink;
	q->Sentinel->next = newLink;
	// Add to size
	q->size++;
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIXME: you must write this */
	TYPE val;			// Value to be returned
	// Make sure q is not null
	assert(q != NULL);
	// Make sure q is not empty
	assert(!isEmptyCirListDeque(q));
	// Get the value of the link next to Sentinel
	val = q->Sentinel->next->value;
	/*temporary return value..you may need to change it*/
	// Return val
	return val;
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	
	TYPE val;			// Value to be returned
	// Make sure q is not null
	assert(q != NULL);
	// Make sure q is not empty
	assert(!isEmptyCirListDeque(q));
	// Get the value of the link prev to Sentinel
	val = q->Sentinel->prev->value;
	/*temporary return value..you may need to change it*/
	// Return val
	return val;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */	 
	// Make sure q is not null
	assert(q != NULL);
	// Make sure q is not empty
	assert(!isEmptyCirListDeque(q));
	// Point the prev and next pointers to the previous and next links
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	// Free lnk
	free(lnk);
	// Reduce the size by one
	q->size--;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	// Make sure q is not null
	assert(q != NULL);
	// Make sure q is not empty
	assert(!isEmptyCirListDeque(q));
	// Create a temporary node to traverse the list
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// Assign temp the Sentinel->next
	temp = q->Sentinel->next;
	// Free up the first valued link
	_removeLink(q, temp);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */
	// Make sure q is not null
	assert(q != NULL);
	// Make sure q is not empty
	assert(!isEmptyCirListDeque(q));
	// Create a temporary node to traverse the list
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// Assign temp the Sentinel->prev
	temp = q->Sentinel->prev;
	// Remove temp
	_removeLink(q, temp);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	// Loop through each link and free data and free it
	// Create a temporary node to traverse the list
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// Assign temp to firstLink->next
	temp = q->Sentinel->next;
	// Loop through the list, until reach the Sentinel again
	while (temp != q->Sentinel)
	{
		//Remove the link
		_removeLink(q, temp);
		// Move on to the next in the list
		temp = temp->next;
	}
	// Remove the Sentinel
	_removeLink(q, q->Sentinel);
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	// Make sure q is not nULL
	assert(q != NULL);
	/*temporary return value..you may need to change it*/
	// Return true or false if the size is 0 or not
	return q->size == 0;
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	// Make sure q is not null
	assert(q != NULL);
	// Make sure q is not empty
	assert(!isEmptyCirListDeque(q));
	// Create a temporary node to traverse the list
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// Assign temp to firstLink->next
	temp = q->Sentinel->next;
	// Loop through the list, until reach the Sentinel again
	while (temp != q->Sentinel)
	{
		printf("%g\n", temp->value);
		// Move on to the next in the list
		temp = temp->next;
	}
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	
	TYPE value;					// Value of the current link
	// Make sure q is not null
	assert(q != NULL);
	// Make sure q is not empty
	assert(!isEmptyCirListDeque(q));
	// Make a temporary link
	struct DLink *temp;
	temp = malloc(sizeof(struct DLink));
	// Assign temp to firstLink->next
	temp = q->Sentinel->next;
	// Loop through the list, until reach the Sentinel again
	while (temp != q->Sentinel)
	{
		// Make a second temp link
		struct DLink *tempTwo;
		tempTwo = malloc(sizeof(struct DLink));
		// Assign second temp link to same as temp
		tempTwo = temp;
		// Get the value of the current link
		value = temp->value;
		// Add a link to the beginning with the above value
		addFrontCirListDeque(q, value);
		// Move temp to next in the circle list before removing
		temp = temp->next;
		//Remove the link of the tempTwo
		_removeLink(q, tempTwo);
	}
}
