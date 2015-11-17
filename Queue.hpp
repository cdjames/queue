/*********************************************************************
** Author: Collin James
** Date: 11/3/15
** Description: A class that implements a double-linked queue data
** structure
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
		Queuenode(int val, Queuenode *aheadnode = NULL, Queuenode *behindnode = NULL)
		{
			value = val;
			ahead = aheadnode;
			behind = behindnode;
		}
	};

	Queuenode *front; 	// points to front of queue
	Queuenode *back;	// points to back of queue	
public:
	/*********************************************************************
	** Description: 
	** Constructor; set front and back to null
	*********************************************************************/
	Queue();
	
	/*********************************************************************
	** Description: 
	** Deconstructor; loop through nodes and delete pointers
	*********************************************************************/
	~Queue();

	/*********************************************************************
	** Description: 
	** Add a value to the queue. Value will be at back of the queue (FIFO)
	*********************************************************************/
	void add(int val);

	/*********************************************************************
	** Description: 
	** Remove a value from the front of queue. Return the value before 
	** removing. Return -12345 if queue is empty.
	*********************************************************************/
	int remove();

	/*********************************************************************
	** Description: 
	** Loop through queue and print values separated by spaces. If empty
	** print "Queue is empty". Print from front to back.
	*********************************************************************/
	void displayQueue();
};

#endif