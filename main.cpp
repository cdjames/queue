/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include "Queue.hpp"

void queueTest(Queue*);

void removeVal(Queue* testQueue);

void addVal(Queue* testQueue, int val);

int main()
{
	Queue *testQueue = new Queue(0);
	queueTest(testQueue); // uncomment to run tests
	// std::cout << "got past queueTest" << std::endl;
	delete testQueue;
}

void queueTest(Queue *testQueue)
{	
	std::cout << "\n- Testing Queue" << std::endl;
	testQueue->displayQueue();
	addVal(testQueue, 2);
	addVal(testQueue, 4);
	addVal(testQueue, 6);
	std::cout << "front is " << testQueue->getFront() << std::endl;
	removeVal(testQueue);
	removeVal(testQueue);
	removeVal(testQueue);
	addVal(testQueue, 8);
	addVal(testQueue, 10);
	std::cout << "front is " << testQueue->getFront() << std::endl;
	removeVal(testQueue);
	removeVal(testQueue);
	std::cout << "front is " << testQueue->getFront() << std::endl;
	removeVal(testQueue);
	addVal(testQueue, 8);
	addVal(testQueue, 10);	
	addVal(testQueue, 12);
	std::cout << "front is " << testQueue->getFront() << std::endl;	
	addVal(testQueue, -1);	
	addVal(testQueue, 14);
	removeVal(testQueue);
	removeVal(testQueue);
	removeVal(testQueue);
	removeVal(testQueue);
	// removeVal(testQueue);
	testQueue->getFront();
}

void removeVal(Queue* testQueue)
{
	std::cout << "removed node value: " << testQueue->removeFront() << std::endl;
	testQueue->displayQueue();
}

void addVal(Queue* testQueue, int val)
{
	std::cout << "Adding " << testQueue->addBack(val) << std::endl;
	testQueue->displayQueue();
}