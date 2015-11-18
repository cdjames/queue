/*********************************************************************
** Author: Collin James
** Date: 11/3/15
** Description: A class that implements a circular double-linked queue data
** structure.
**
** Implementation file
*********************************************************************/

#include <iostream>
#include "Queue.hpp" // see for function descriptions

Queue::Queue(int val)
{
	back = new Queuenode(val); // will be -1 when created, so empty node
	front = back;	// front and back are the same thing at this point
}

Queue::~Queue()
{
	Queuenode *tempPtr = front; // point at front
	Queuenode *frontPtr = front; // point at front

	/* loop until done; set done to true when the element behind the one deleted is
	 * back at front */
	bool done = false;
	while(!done)
	{
		Queuenode *trash = tempPtr;
		std::cout << "deleting " << tempPtr << std::endl; // uncomment for quiet deletion
		
		if(tempPtr->behind == front)
			done = true;
		else
		{
			tempPtr = tempPtr->behind;
			std::cout << "next: " << tempPtr << std::endl; // uncomment for quiet deletion
		}
		
		delete trash;
	}	
}

int Queue::addBack(int val)
{
	/* if negative value, don't add anything */
	if(val < 0)
		return -1;
	else
	{
		/* first element added; works if "virgin" or if other nodes exist 
		 * reuses back node to save memory */
		if(back->value == -1 && back == front) // if back is front and empty
			back->value = val;

		/* "virgin" 2nd node (only 2 node pointers in existence) */
		else if(front == back && front->ahead == back)
		{
			Queuenode *newnode = new Queuenode(val, front, front);
			front->ahead = newnode; // new node is right behind front
			front->behind = newnode; // new node is right behind front
			
			/* newnode is the new back of the queue */
			back = newnode;
		}
		/* upon non-virgin 2+ nodes */
		else
		{
			// if(front->ahead != back)
			// {
			// 	Queuenode *tempPtr = front->ahead;
			// 	front = front->ahead;
			// }
			// std::cout << "addBack third if" << std::endl;
			/* create a new node, where the old back becomes the node in front of the new node */
			Queuenode *newnode = new Queuenode(val, back, back->behind);
			Queuenode *oldback = back;
			
			/* old back is now second from back, so give it a new behind node*/
			oldback->behind = newnode;
			
			/* newnode is the new back of the queue */
			back = newnode;
		}

		return val;
	}
}

int Queue::removeFront()
{
	int frontval = getFront();

	if(frontval >= 0) // front (and list) is not empty
	{
		front->value = -1; // set front value to empty (i.e. "remove" it)

		if(back != front) // only set new front if more than 1 item in list
			front = front->behind;
	}
		
	return frontval;	// return value; may be -1 if empty queue
}

int Queue::getFront()
{
	if(front->value == -1)
		std::cout << "Queue is empty" << std::endl;

	/* will return -1 if empty */
	return front->value;
}

void Queue::displayQueue()
{
	int count = 0;
	std::cout << "    front: " << front->value << "    " << "back: " << back->value << std::endl;
	if(front->value != -1)
	{
		/* loop through queue and print values */
		Queuenode *tempPtr = front;
		std::cout << "    front pointer is: " << front << "   \n";
		
		do
		{
			if(tempPtr->value != -1) // if not empty node
			{
				count++;
				std::cout << "value at node " << count << " is: " << tempPtr->value << std::endl;
				/* comment out next three lines for no pointer addresses */
				std::cout << "    pointer is: " << tempPtr << std::endl;
				std::cout << "    behind pointer is: " << tempPtr->behind << std::endl;
				std::cout << "    ahead pointer is: " << tempPtr->ahead << std::endl;
			}

			tempPtr = tempPtr->behind;
		} while(tempPtr != front); // when it has gone all the way around it will be equal to front again

		std::cout << "    back pointer is: " << back;
		std::cout << std::endl;
	}
	else // if front (or back) is -1, nothing is in queue
		std::cout << "Queue is empty" << std::endl;
}