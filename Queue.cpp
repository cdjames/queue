/*********************************************************************
** Author: Collin James
** Date: 11/3/15
** Description: A class that implements a double-linked queue data
** structure; implementation file
*********************************************************************/

#include <iostream>
#include "Queue.hpp" // see for function descriptions

Queue::Queue()
{
	front = NULL;
	back = NULL;
}

Queue::~Queue()
{
	Queuenode *tempPtr = front; // point at front
	/* loop until tempPtr is NULL */
	while(tempPtr)
	{
		Queuenode *trash = tempPtr;
		tempPtr = tempPtr->behind;
		delete trash;
	}	
}

void Queue::add(int val)
{
	/* first element added */
	if(!back) // if back is null
	{
		back = new Queuenode(val);
		front = back; // front and back are the same
	}
	/* second element is added */
	else if(front && front == back)
	{
		/* new node, where back becomes new previous node*/
		Queuenode *newnode = new Queuenode(val, back, NULL);
		front->behind = newnode; // new node is right behind front
		
		/* newnode is the new back of the queue */
		back = newnode;
	}
	else
	{
		/* create a new node, where the old back becomes the node in front of the new node */
		Queuenode *newnode = new Queuenode(val, back, NULL);
		Queuenode *oldback = back;
		
		/* old back is now second from back, so give it a new behind node*/
		oldback->behind = newnode;
		
		/* newnode is the new back of the queue */
		back = newnode;
	}
}

int Queue::remove()
{
	if(front) // front is not null
	{
		Queuenode *tempPtr = front;	// point at front
		int temp_val = tempPtr->value; // save the value
		if(front->behind) // there are at least 2 items in the list
			front = front->behind;
		else // there is only 1 item left
			front = back = NULL; // so back and front should point to nothing
		
		delete tempPtr;
		return temp_val;
	}
	else // nothing in the queue
		return -12345;	// return junk number
}

void Queue::displayQueue()
{
	if(front)
	{
		/* loop through queue and print values */
		Queuenode *tempPtr = front;
		std::cout << "front pointer is: " << front << "   \n";
		while(tempPtr != NULL)
		{
			std::cout << tempPtr->value << "   ";
			/* comment out next three lines for no pointer addresses */
			std::cout << "pointer is: " << tempPtr << "   ";
			std::cout << "behind pointer is: " << tempPtr->behind << "   ";
			std::cout << "ahead pointer is: " << tempPtr->ahead << "   \n";

			tempPtr = tempPtr->behind;
		}	
		std::cout << "back pointer is: " << back << "   \n";
		std::cout << std::endl;
	}
	else // if head is null, nothing is in queue
		std::cout << "Queue is empty" << std::endl;
}