/*********************************************************************
** Author: Collin James
** Date: 11/17/15
** Description: A class that implements a double-linked circular queue 
** data structure
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
protected:
	/* container structure for nodes */
	struct Queuenode
	{
		int value;
		Queuenode *ahead; 	//link to node added before
		Queuenode *behind;	//link to node added after

		/* constructor; set a value and before/after nodes */
		Queuenode(int val = -1, Queuenode *aheadnode = NULL, Queuenode *behindnode = NULL)
		{
			value = val;

			/* Don't want null pointers, so make ahead/behind point to itself */
			if(!aheadnode)
				ahead = this;
			else
				ahead = aheadnode;

			if(!behindnode)
				behind = this;
			else
				behind = behindnode;
		}
	};

	Queuenode *front; 	// points to front of queue
	Queuenode *back;	// points to back of queue	
public:
	/*********************************************************************
	** Description: 
	** Constructor; set front and back to -1 (empty node). Can be created
	** with initial value as well.
	*********************************************************************/
	Queue(int val = -1);
	
	/*********************************************************************
	** Description: 
	** Deconstructor; loop through nodes and delete pointers
	*********************************************************************/
	~Queue();

	/*********************************************************************
	** Description: 
	** Add a positive value to the queue. Value will be at back of the queue (FIFO)
	*********************************************************************/
	int addBack(int val);

	/*********************************************************************
	** Description: 
	** Remove a value from the front of queue. Return the value before 
	** removing. Removing actually just sets to -1. Return -1 if queue is 
	** empty.
	*********************************************************************/
	int removeFront();

	/*********************************************************************
	** Description: 
	** Simply return the value at the front pointer of the queue. Returns
	** -1 if queue is empty.
	*********************************************************************/
	int getFront();

	/*********************************************************************
	** Description: 
	** Loop through queue and print values. If empty print "Queue is 
	** empty". Print from front to back.
	*********************************************************************/
	void displayQueue();
};

#endif