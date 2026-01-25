#include "testingFramework.h"

void testAll()
{
    /* Tab all your output from a function with \t */
    std::cout << "==================== TESTING FRAMEWORK ====================" << std::endl;
    testArray();
    testDLList();
    testQueue();
    testStack();
    testPrinter();
    std::cout << "====================== FRAMEWORK END ======================" << std::endl;
}

void testArray()
{
    /* Array Functions */
    std::cout << "Array\n===========================================================" << std::endl;
    std::cout << "Function 1:" << std::endl;

        Array<int>* testArr = new Array<int>(5);
        Array<int>* testArr1 = NULL;
    std::cout << "\tCreated Array with valid size of 5..." << std::endl;
    std::cout << *testArr << std::endl;
    std::cout << "\tArray size (Should be 5): " << int(*testArr) << std::endl;
    std::cout << "\tArray number of elements (Should be 0): " << testArr->numElements() << std::endl;
        try
        {
            testArr1 = new Array<int>(-3);
            std::cout << "\tCreated Array with invalid size (Incorrect output)" << std::endl;
        }catch (InvalidSizeException& err)
        {
            std::cout << "\tCreating Array with invalid size...\ncaught exception with error message (Should be -3): " << err.getMessage() << std::endl;
        }


    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 4:" << std::endl;
    std::cout << "\tReturning size of array: Should be 5..." << std::endl;
    std::cout << int(*testArr) << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 5:" << std::endl;
    int num = 0;
        for (int i = 0; i < int(*testArr); i++)
        {
            num = i + 1;
            *testArr += num;
        }
    std::cout << "\tInserted 5 numbers into 'testArr' array: Should be [1, 2, 3, 4, 5]" << std::endl;
    std::cout << *testArr << std::endl;
    num = 7;
        *testArr += num;
    std::cout << "\tInserted 1 number into Full 'testArr' array: Should be [1, 2, 3, 4, 5, 7, NULL, NULL, NULL, NULL]" << std::endl;
    std::cout << *testArr << std::endl;


    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 3:" << std::endl;
    std::cout << "\tReturning number of elements: Should be 6..." << std::endl;
    std::cout << testArr->numElements() << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 6:" << std::endl;
    std::cout << "\tRemoving elements [3 - 5] from 'testArr': Should be [1, 2, 7, NULL, NULL]" << std::endl;
        num = 0;
        for (int i = 2; i < 5; i++)
        {
            num = i + 1;
            try
            {
                *testArr -= num;
            }catch (ElementNotInListException&)
            {
                std::cout << "\t\tElement Not in List Exception Caught for value " << i + 1 << " (Incorrect Output)" << std::endl;
            }
        }
    std::cout << *testArr << std::endl;
    std::cout << "\tRemoving non-present element from 'testArr': Should throw Exception..." << std::endl;
        try{
            num = 10;
            *testArr -= num;
            std::cout << "\t\tRemoved element (Incorrect Output)" << std::endl;
        }catch (ElementNotInListException&)
        {
            std::cout << "Element Not in List Exception Caught (Correct Output)" << std::endl;
        }


    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 7 & 8:" << std::endl;
    std::cout << "\tAccessing valid value (Should be 7): Output = " << (*testArr)[3] << std::endl;
    std::cout << "\tAccessing invalid index..." << std::endl;
        try{
            std::cout << (*testArr)[5] << std::endl;
            std::cout << "\t\tIncorrect Output." << std::endl;
        }catch (InvalidIndexException& err){
            std::cout << "\t\tCorrect output below (Should NOT be ...index was null):" << std::endl;
            std::cout << err.getMessage() << std::endl;
        }
    std::cout << "\tAccessing NULL index..." << std::endl;
        try{
            std::cout << (*testArr)[2] << std::endl;
            std::cout << "\t\tIncorrect Output." << std::endl;
        }catch (InvalidIndexException& err){
            std::cout << "\t\tCorrect output below (Should be ...index was null):" << std::endl;
            std::cout << err.getMessage() << std::endl;
        }


    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 9:" << std::endl;
    std::cout << "\tCreating deep copy of 'testArr', output should be same as TestArr (See Funct 10)..." << std::endl;
        Array<int>* testArrCopy = testArr->clone();


    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 10:" << std::endl;
    std::cout << "\tPrinting out testArrCopy, there should be no Endline..." << std::endl;
        std::cout << *testArrCopy << "  //On same line as output and no trailing commas? [Correct output]" << std::endl;


    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 11:" << std::endl;
    std::cout << "\tComparing testArr and testArrCopy: Should show [Not Same] below..." << std::endl;
        if (*testArrCopy == *testArr)
            std::cout << "Same" << std::endl;
        else
            std::cout << "Not same" << std::endl;


    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 2:" << std::endl;
        if (testArr)
            delete testArr;
        if (testArr1)
            delete testArr1;
        if (testArrCopy)
            delete testArrCopy;
    std::cout << "\tDestructing Array objects..." << std::endl;

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "Array End";
    std::cout << "\n===========================================================" << std::endl;
    /* Array Functions */
}

void testDLList()
{
    /* DLList Functions */
    std::cout << "DLList\n===========================================================" << std::endl;
    std::cout << "Function 1:" << std::endl;
    std::cout << "\t Creating doubly linked lists..." << std::endl;
        DLList<int>* list1 = new DLList<int>();
        DLList<int>* listEmpty = new DLList<int>();

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 3:" << std::endl;
    std::cout << "\t Adding in values [1 - 3]..." << std::endl;
        int num = 0;
        for (int i = 1; i < 4; i++)
        {
            *list1 += i;
        }
    std::cout << "\t\t Adding in values [4 - 7] backwards (Should output in ascending order)..." << std::endl;
        for (int i = 7; i > 3; i--)
        {
            *list1 += i;
        }
        std::cout << *list1;

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "Function 4:" << std::endl;
    std::cout << "\t Removing value from empty list..." << std::endl;
        try{
            num = 3;
            *listEmpty -= num;
            std::cout << "\t\tIncorrect Output" << std::endl;
        }catch (ElementNotInListException& err){
            std::cout << err.getMessage() << " (Correct Output)" << std::endl;
        }
    std::cout << "\t Removing value [5] from list1, should output: [1,2,3,4,6,7]" << std::endl;
        try{
            num = 5;
            *list1 -= num;
            std::cout << *list1;
        }catch (ElementNotInListException& err){
            std::cout << err.getMessage() << " (Incorrect Output)";
        }

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "Function 5 & 6:" << std::endl;
    std::cout << "\t Getting value from valid index 4: Should output 6..." << std::endl;
        try{
            std::cout << (*list1)[4] << std::endl;
        }catch (InvalidIndexException& err){
            std::cout << err.getMessage() << " (Incorrect Output)" << std::endl;
        }
    std::cout << "\t Getting value from invalid index 8..." << std::endl;
        try{
            std::cout << (*list1)[8] << std::endl;
            std::cout << "Incorrect Output." << std::endl;
        }catch (InvalidIndexException& err){
            std::cout << err.getMessage() << " (Correct Output)" << std::endl;
        }

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 7:" << std::endl;
    std::cout << "\t Making copy of list1..." << std::endl;
        DLList<int>* listCopy = list1->clone();

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 8:" << std::endl;
    std::cout << "\t Returning size of listCopy: Should be 6..." << std::endl;
        std::cout << int(*listCopy) << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 2:" << std::endl;
    std::cout << "\t Destroying doubly linked lists..." << std::endl;
        if (list1)
            delete list1;
        if (listEmpty)
            delete listEmpty;
        if (listCopy)
            delete listCopy;

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "DLList End";
    std::cout << "\n===========================================================" << std::endl;
    /* DLList Functions */
}

void testQueue()
{
    /* DLList Functions */
    std::cout << "Queue\n===========================================================" << std::endl;
    std::cout << "Function 1:" << std::endl;
    std::cout << "\t Creating queues..." << std::endl;
        Queue<int>* queue1 = new Queue<int>();
        Queue<int>* queueEmpty = new Queue<int>();

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 3:" << std::endl;
    std::cout << "\t Adding in values [1 - 3]..." << std::endl;
        for (int i = 1; i < 4; i++)
        {
            *queue1 += i;
        }
    std::cout << "\t\t Adding in values [4 - 7] backwards, should output: [1,2,3,7,6,5,4]..." << std::endl;
        for (int i = 7; i > 3; i--)
        {
            *queue1 += i;
        }
        std::cout << *queue1 << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 4:" << std::endl;
    std::cout << "\t Removing front element from empty list..." << std::endl;
        int returnNum = 0;
        *queueEmpty -= returnNum;
        std::cout << "\t\tReturned Number (Should be 0): " << returnNum << std::endl;
    std::cout << "\t Removing front element from queue1" << std::endl;
        *queue1 -= returnNum;
        std::cout << "\t\t Removed number (Should be 1): " << returnNum << std::endl;
        std::cout << "\t\t" << *queue1 << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 5 & 6:" << std::endl;
    std::cout << "\t Getting value from valid index 4: Should output 5..." << std::endl;
        try{
            std::cout << (*queue1)[4] << std::endl;
        }catch (InvalidIndexException& err){
            std::cout << err.getMessage() << " (Incorrect Output)" << std::endl;
        }
    std::cout << "\t Getting value from invalid index 8..." << std::endl;
        try{
            std::cout << (*queue1)[8] << std::endl;
            std::cout << "Incorrect Output." << std::endl;
        }catch (InvalidIndexException& err){
            std::cout << err.getMessage() << " (Correct Output)" << std::endl;
        }

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 7:" << std::endl;
    std::cout << "\t Making copy of queue1..." << std::endl;
        Queue<int>* queueCopy = queue1->clone();

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 8:" << std::endl;
    std::cout << "\t Returning size of queueCopy: Should be 6..." << std::endl;
        std::cout << int(*queueCopy) << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 2:" << std::endl;
    std::cout << "\t Destroying queues..." << std::endl;
        if (queue1)
            delete queue1;
        if (queueEmpty)
            delete queueEmpty;
        if (queueCopy)
            delete queueCopy;

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "Queue End";
    std::cout << "\n===========================================================" << std::endl;
    /* DLList Functions */
}

void testStack()
{
    /* DLList Functions */
    std::cout << "Stack\n===========================================================" << std::endl;
    std::cout << "Function 1:" << std::endl;
    std::cout << "\t Creating Stacks..." << std::endl;
        Stack<int>* stack1 = new Stack<int>();
        Stack<int>* stackEmpty = new Stack<int>();

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 3:" << std::endl;
    std::cout << "\t Adding in values [1 - 3]..." << std::endl;
        for (int i = 1; i < 4; i++)
        {
            *stack1 += i;
        }
    std::cout << "\t\t Adding in values [4 - 7] backwards, should output: [4,5,6,7,3,2,1]..." << std::endl;
        for (int i = 7; i > 3; i--)
        {
            *stack1 += i;
        }
        std::cout << *stack1 << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 4:" << std::endl;
    std::cout << "\t Removing front element from empty list..." << std::endl;
        int returnNum = 0;
        *stackEmpty -= returnNum;
        std::cout << "\t\tReturned Number (Should be 0): " << returnNum << std::endl;
    std::cout << "\t Removing front element from stack1" << std::endl;
        *stack1 -= returnNum;
        std::cout << "\t\t Removed number (Should be 4): " << returnNum << std::endl;
        std::cout << "\t\t" << *stack1 << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 5 & 6:" << std::endl;
    std::cout << "\t Getting value from valid index 4: Should output 2..." << std::endl;
        try{
            std::cout << (*stack1)[4] << std::endl;
        }catch (InvalidIndexException& err){
            std::cout << err.getMessage() << " (Incorrect Output)" << std::endl;
        }
    std::cout << "\t Getting value from invalid index 8..." << std::endl;
        try{
            std::cout << (*stack1)[8] << std::endl;
            std::cout << "Incorrect Output." << std::endl;
        }catch (InvalidIndexException& err){
            std::cout << err.getMessage() << " (Correct Output)" << std::endl;
        }

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 7:" << std::endl;
    std::cout << "\t Making copy of stack1..." << std::endl;
        Stack<int>* stackCopy = stack1->clone();

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 8:" << std::endl;
    std::cout << "\t Returning size of stackCopy: Should be 6..." << std::endl;
        std::cout << int(*stackCopy) << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 2:" << std::endl;
    std::cout << "\t Destroying stacks..." << std::endl;
        if (stack1)
            delete stack1;
        if (stackEmpty)
            delete stackEmpty;
        if (stackCopy)
            delete stackCopy;

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "Stack End";
    std::cout << "\n===========================================================" << std::endl;
    /* DLList Functions */
}

void testPrinter()
{
    /* DLList Functions */
    std::cout << "Printer\n===========================================================" << std::endl;
    std::cout << "Function 1:" << std::endl;
    std::cout << "\t Requesting printer..." << std::endl;
        Printer<DLList, int> printer = Printer<DLList, int>::requestPrinter(); ///////////// Likely gonna need a type for this

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 2:" << std::endl;
    std::cout << "\t Returning current printer ..." << std::endl;
        Printer<DLList, int>::returnPrinter();
        std::cout << "\t\t Returning unavailable printer ..." << std::endl;
        try{
                Printer<DLList, int>::returnPrinter();
                std::cout << "Incorrect Output" << std::endl;
        }catch (TooManyPrintersDeleted& err)
        {
            std::cout << "\t\t" << err.getMessage() << " (Correct Output)" << std::endl;
        }

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 3:" << std::endl;
/*
    std::cout << "\t Inserting into NULL printer ..." << std::endl;
        try{
            printer.insertDocument(5);
            std::cout << "Incorrect Output" << std::endl;
        }catch (PrinterNotInitialized& err){
            std::cout << "\t\t" << err.getMessage() << " (Correct Output)";
        }

*/
    std::cout << "\t Requesting Printer & Inserting data [1-7] ..." << std::endl;
        printer = Printer<DLList, int>::requestPrinter();
        for (int i = 1; i < 8; i++)
        {
            printer.insertDocument(i);
        }
        printer.printToStream(std::cout);

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 5:" << std::endl;
    std::cout << "\t Inputting printer queue into 'test.txt' textfile ..." << std::endl;

        for (int i = 1; i < 8; i++)
        {
            printer.insertDocument(i);
        }
        std::string fileName = "test.txt";
        std::fstream file(fileName.c_str(), std::ios::out | std::ios::in);
        printer.printToFile(file);
        file.close();

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 6:" << std::endl;
    std::cout << "\t Returning printerQueue size (Should be 0)..." << std::endl;
        std::cout << printer.numberOfDocuments() << std::endl;

    std::cout << "===========================================================" << std::endl;
    std::cout << "Function 7:" << std::endl;
    std::cout << "\t Checking if 3 is in the queue (Should return [Yes]) ..." << std::endl;
        // Inserting documents in cause it will likely be null
        for (int i = 1; i < 8; i++)
        {
            printer.insertDocument(i);
        }

        int num = 3;
        if (printer.isInQueue(num))
        {
            std::cout << "Yes" << std::endl;
        }else
            std::cout << "No" << std::endl;

    num = 9;
    std::cout << "\t Checking if 9 is in the queue (Should return [No]) ..." << std::endl;
    if (printer.isInQueue(num))
    {
        std::cout << "Yes" << std::endl;
    }else
        std::cout << "No" << std::endl;

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "Printer End";
    std::cout << "\n===========================================================" << std::endl;
    /* DLList Functions */
}
