#include "testingFramework.h"

void testAll()
{
    std::cout << "==================== TESTING FRAMEWORK ====================" << std::endl;
    std::cout << "Function 1\n====================\n...";

    std::cout << "Creating 'holder' list node" << std::endl;
    ListNode<int>* holder = new ListNode<int>(5); // Create a List Node with a value of 5

    std::cout << std::endl;
    std::cout << "Function 3\n====================\n..." << std::endl;
    std::cout << "Get value of holder List Node: " << holder->getValue() << ". Should be 5" << std::endl;


    std::cout << std::endl;
    std::cout << "Function 5\n====================\n...";

    ListNode<int>* backNode = new ListNode<int>(9);
    std::cout << "Appending 'backNode' to back of 'holder' list node" << std::endl;
    holder->append(backNode);

    std::cout << std::endl;
    std::cout << "Function 6\n====================\n...";

    ListNode<int>* frontNode = new ListNode<int>(3);
    std::cout << "Appending 'frontNode' to front of 'holder' list node" << std::endl;
    holder->append(backNode); // To test for trying to add same node again
    holder->prepend(frontNode);
    holder->prepend(backNode); // To test for trying to add same node again

    std::cout << std::endl;
    std::cout << "Function 4\n====================\n...";

    std::cout << "Get Size of List Node: " << holder->size() << ". Should be 3" << std::endl;

    std::cout << std::endl;
    std::cout << "Function 7\n====================\n...";

    std::cout << "Removing backNode from back" << std::endl;
    ListNode<int>* testNode = holder->remove(backNode);

    (testNode == backNode)? std::cout << "The removed node is the backNode (CORRECT EXECUTION)" << std::endl: std::cout << "The removed Node is NULL (WRONG EXECUTION)" << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Function 8\n====================\n...";

    holder->append(backNode); // Adding backnode back for purpose of 8

    ListNode<int>** addNodes = new ListNode<int>*[4];

    for (int i = 0; i < 4; i++)
    {
        addNodes[i] = new ListNode<int>(i + 1);

        if (i < 2)
        {
            std::cout << "Adding node: " << i << " to the back" << std::endl;
            holder->append(addNodes[i]);
        }else
        {
            std::cout << "Adding node: " << i << " to the front" << std::endl;
            holder->prepend(addNodes[i]);
        }
    }

    std::cout << "\nPrinting list before removals: " << std::endl;
    holder->printList();

    std::cout << "Removing frontNode: ";
    testNode = holder->remove(-1);
    (testNode == frontNode)? std::cout << "The removed node is the frontNode (CORRECT EXECUTION)" << std::endl: std::cout << "The removed Node is NULL/Not the frontNode (WRONG EXECUTION)" << std::endl;

    std::cout << "Removing backNode: ";
    testNode = holder->remove(1);
    (testNode == backNode)? std::cout << "The removed node is the backNode (CORRECT EXECUTION)" << std::endl: std::cout << "The removed Node is NULL/Not the backNode (WRONG EXECUTION)" << std::endl;

    std::cout << "Removing node 2 steps forward (The 2 node): ";
    testNode = holder->remove(2);
    (testNode == addNodes[1])? std::cout << "The removed node is the 2 node (CORRECT EXECUTION)" << std::endl: std::cout << "The removed Node is NULL (WRONG EXECUTION)" << std::endl;

    std::cout << "Removing node 2 steps back (The 4 node): ";
    testNode = holder->remove(-2);
    (testNode == addNodes[3])? std::cout << "The removed node is the 4 node (CORRECT EXECUTION)" << std::endl: std::cout << "The removed Node is NULL (WRONG EXECUTION)" << std::endl;

    std::cout << std::endl;
    std::cout << "Function 9\n====================\n...";

    holder->append(backNode);
    holder->prepend(frontNode);

    std::cout << "Getting holder Node: ";
    testNode = holder->getNodeAt(0);
    (testNode == holder)? std::cout << "The found node is PRESENT (CORRECT EXECUTION)" << std::endl: std::cout << "OUT OF BOUNDS (WRONG EXECUTION)" << std::endl;

    std::cout << std::endl;
    std::cout << "Function 10\n====================\n...";


    std::cout << "Printing list before reversal: " << std::endl;
    holder->printList();

    std::cout << "Reversing the list" << std::endl;
    holder->reverseList();


    std::cout << std::endl;
    std::cout << "Function 11\n====================\n...";

    std::cout << "Printing List: " << std::endl;
    holder->printList();

    std::cout << std::endl;
    std::cout << "Function 2\n====================\n...";
    std::cout << "Deleting Nodes" << std::endl;
    delete holder;
    delete addNodes[1];
    delete addNodes[3];
    delete[] addNodes;
}
