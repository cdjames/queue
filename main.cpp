/*********************************************************************
** Author: Collin James
** Date: 11/17/15
** Description: Driver program to demonstrate Queue ADT. Prompts user
** to add value, remove value, or print queue
*********************************************************************/

#include <iostream>
#include "Queue.hpp" // a queue ADT
#include "main.hpp" // please see for function descriptions

int main()
{
	Queue *testQueue = new Queue(); // new empty queue
	Queue *tempQueue = new Queue(); // new empty queue
	// queueTest(testQueue); // uncomment to run tests

	int input = -1,
		value;

	/* loop until user enters 0 for quit */
	while(input != QUIT)
	{
		/* Present menu to user. mainMenu() does input error-checking and loops
			until good input */
		input = mainMenu();

		clearCin(); // get cin ready for next input

		switch(input)
		{
			case ADD: // 1
				intakeInt(value, "a positive integer."); // passed as references
				testQueue->addBack(value);
				std::cout << "Added " << value << " to queue." << std::endl;
				break;
			case REMOVE: // 2
				value = testQueue->removeFront();
				if(value >= 0)
					std::cout << "Removed " << value << " from queue." << std::endl;
				else
					std::cout << "Error: cannot remove from empty queue." << std::endl;
				break;
			case PRINT: // 3
				// testQueue->displayQueue(); // for testing, yeah
				displayQueue(testQueue, tempQueue);
				break;
			default:
				break;

		}
	}

	delete testQueue; // delete the pointer
	delete tempQueue; // delete the pointer

	return 0;	
}

void queueTest(Queue *testQueue)
{	
	std::cout << "\n- Testing Queue" << std::endl;
	// testQueue->displayQueue();
	addVal(testQueue, 2);
	addVal(testQueue, 4);
	addVal(testQueue, 6);
	addVal(testQueue, 8);
	// std::cout << "front is " << testQueue->getFront() << std::endl;
	// removeVal(testQueue);
	testQueue->removeFront();
	testQueue->removeFront();
	testQueue->removeFront();
	testQueue->removeFront();
	// removeVal(testQueue);
	// removeVal(testQueue);
	// addVal(testQueue, 8);
	testQueue->addBack(10);
	testQueue->addBack(12);
	testQueue->addBack(12);
	testQueue->addBack(12);
	addVal(testQueue, 14);
	removeVal(testQueue);
	// std::cout << "front is " << testQueue->getFront() << std::endl;
	// removeVal(testQueue);
	// removeVal(testQueue);
	// std::cout << "front is " << testQueue->getFront() << std::endl;
	// removeVal(testQueue);
	// addVal(testQueue, 8);
	// addVal(testQueue, 10);	
	// addVal(testQueue, 12);
	// std::cout << "front is " << testQueue->getFront() << std::endl;	
	// addVal(testQueue, -1);	
	// addVal(testQueue, 14);
	// removeVal(testQueue);
	// removeVal(testQueue);
	// removeVal(testQueue);
	// removeVal(testQueue);
	// // removeVal(testQueue);
	// testQueue->getFront();
}

void removeVal(Queue* testQueue)
{
	std::cout << "removed node value: " << testQueue->removeFront() << std::endl;
	// testQueue->displayQueue();
}

void addVal(Queue* testQueue, int val)
{
	std::cout << "Adding " << testQueue->addBack(val) << std::endl;
	// testQueue->displayQueue();
}

void clearCin()
{
	std::cin.clear();
	std::cin.ignore(50, '\n');
}

bool cinFail()
{
	bool failed = false;
	if(std::cin.fail()) // check for bad input
	{
		clearCin(); // ignore the bad input
		failed = true;
	}
	return failed;
}

int mainMenu()
{
	int input = -1;

	std::cout << std::endl;
	std::cout << "Choose an action:" << std::endl;
	std::cout << "   1 - Add value to back of queue" << std::endl;
	std::cout << "   2 - Remove value from front of queue" << std::endl;
	std::cout << "   3 - Display queue" << std::endl;
	std::cout << "   0 - Quit program" << std::endl;

	std::cin >> input;

	/* test for bad input and loop until good */
	while(input < 0 || input > 3 || cinFail())
	{
		std::cout << "Please enter 1, 2, 3, or 0." << std::endl;
		clearCin(); // clear cin, otherwise endless loop!
		input = mainMenu(); // run menu again
	}

	return input;
}

void intakeInt(int &num_items, std::string message)
{ // not in spec
	int imax = std::numeric_limits<int>::max(); // upper limit for ints on system
	std::cout << "Please enter "<< message << std::endl;
	
	do{
		std::cin >> num_items;
		if(cinFail()) // some bad or strange input
			std::cout << "Please enter a correct value." << std::endl;
		else if (num_items < 0)
			std::cout << "Please enter a positive number." << std::endl;
		else if (num_items > imax)
			std::cout << "Please enter a lower number." << std::endl;

	} while (cinFail() || num_items < 0 || num_items > imax);

	clearCin();
	return;
}

void displayQueue(Queue *testQueue, Queue *tempQueue)
{
	int value,
		count = 0;
	value = testQueue->removeFront();

	if(value != -1)
	{
		while(value != -1)
		{
			count++;
			std::cout << "value at node " << count << " is: " << value << std::endl;
			tempQueue->addBack(value);
			value = testQueue->removeFront();
		}
		
		value = tempQueue->removeFront();
		while(value != -1)
		{
			testQueue->addBack(value);
			value = tempQueue->removeFront();
		}
	}
	else
		std::cout << "Queue is empty." << std::endl;
}