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