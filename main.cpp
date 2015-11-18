/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include "Queue.hpp"

/*********************************************************************
** Description: 
** Test driver; calls removeVal() and addVall()
*********************************************************************/
void queueTest(Queue*);

/*********************************************************************
** Description: 
** Utility function for tests; calls testQueue->removeFront() and cout
*********************************************************************/
void removeVal(Queue* testQueue);

/*********************************************************************
** Description: 
** Utility function for tests; calls testQueue->addBack() and cout
*********************************************************************/
void addVal(Queue* testQueue, int val);

/*********************************************************************
** Description: 
** Utility function combining cin.clear() and cin.ignore(). Useful 
** when using cin.getline() after cin >>
*********************************************************************/
void clearCin();

/*********************************************************************
** Description: 
** A utility function to test for cin.fail(). Useful for detecting 
** erroneous input in menu functions. Returns true or false.
*********************************************************************/
bool cinFail();

/*********************************************************************
** Description: 
** First interaction with user. Gives 3 choices: 1 - add to queue,
** 2 - remove from queue, 3 - print queue, 0 - Quit. Inputs 
** choice, checks for bad input and calls recursively. Returns int 
** upon good input.
*********************************************************************/
int mainMenu();

/*********************************************************************
** Description: 
** Generic function for accepting integer input. Pass int to store
** info (reference) and a message to append to "Please input "
*********************************************************************/
void intakeInt(int &num_items, std::string message);

enum Choices { QUIT, ADD, REMOVE, PRINT };

int main()
{
	Queue *testQueue = new Queue();
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
					std::cout << "Cannot remove from empty queue." << std::endl;
				break;
			case PRINT: // 3
				testQueue->displayQueue();
				break;
			default:
				break;

		}
	}
	delete testQueue;

	return 0;	
}

void queueTest(Queue *testQueue)
{	
	std::cout << "\n- Testing Queue" << std::endl;
	testQueue->displayQueue();
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
	testQueue->displayQueue();
}

void addVal(Queue* testQueue, int val)
{
	std::cout << "Adding " << testQueue->addBack(val) << std::endl;
	testQueue->displayQueue();
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
	std::cout << "   1 - Add value to queue" << std::endl;
	std::cout << "   2 - Remove value from queue" << std::endl;
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

// void addValuePrompt(int &value)
// {
// 	intakeInt(value, "a positive integer.");
// }

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