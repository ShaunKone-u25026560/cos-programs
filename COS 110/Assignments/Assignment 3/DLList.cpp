#include "ElementNotInListException.h"

template <class T>
DLList<T>::DLList() // Function 1
{
    head = NULL;
}

template <class T>
DLList<T>::~DLList() // Function 2
{
    // Note CONTENT IS STORED IN ASCENDING ORDER
    if (head)
    {
        while (head->next != NULL)
        {
            head = head->next;

            delete head->prev;

            head->prev = NULL;
        }

        delete head;
        head = NULL;
    }
}

template <class T>
DLList<T>& DLList<T>::operator+=(T& data) // Function 3
{
    DLLNode<T>* newNode = new DLLNode<T>;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    DLLNode<T>* nodePtr = NULL;
    if (head)
    {
        nodePtr = head;

        if (nodePtr->data >= newNode->data) // If new Nodes value is smallest, we insert at head
        {
            newNode->next = nodePtr;
            nodePtr->prev = newNode;
            head = newNode;
        }else
        {
            while (nodePtr->next != NULL && nodePtr->next->data < newNode->data)
            {
                nodePtr = nodePtr->next;
            }
            // Adds in between the current and next node
            // If nodePtr->next == NULL then you can add the newNode to the end of the list
            if (!nodePtr->next)
            {
                nodePtr->next = newNode;
                newNode->prev = nodePtr;
            }else
            {
                nodePtr->next->prev = newNode;
                newNode->next = nodePtr->next;
                nodePtr->next = newNode;
                newNode->prev = nodePtr;
            }
        }
    }else
        head = newNode;

    return *this;
}

template <class T>
DLList<T>& DLList<T>::operator-=(T& data) // Function 4
{
    DLLNode<T>* nodePtr = NULL;

    if (head)
    {
        nodePtr = head;

        while (nodePtr != NULL && nodePtr->data != data)
        {
            nodePtr = nodePtr->next;
        }

        // If nodePtr == NULL, we couldnt find the data in the list
        if (nodePtr) // nodePtr is the one with the data
        {

            if (nodePtr == head)
                head = nodePtr->next;
            if (nodePtr->prev)
                nodePtr->prev->next = nodePtr->next;
            if (nodePtr->next)
                nodePtr->next->prev = nodePtr->prev;

            nodePtr->prev = NULL;
            nodePtr->next = NULL;
            delete nodePtr;

            return *this;
        }
    }

    throw ElementNotInListException();
}

template <class T>
const T& DLList<T>::operator[](int index) const // Function 5
{
    if (index >= 0)
    {
        // Loop through linked list for "index" amount
        int count = 0;

        DLLNode<T>* nodePtr = NULL;

        if (head)
        {
            nodePtr = head;

            while (nodePtr && count < index)
            {
                nodePtr = nodePtr->next;
                ++count;
            }

            if (nodePtr)
                return nodePtr->data;
        }

    }

    throw InvalidIndexException(index);
}

template <class T>
T& DLList<T>::operator[](int index) // Function 6
{
    if (index >= 0)
    {
        // Loop through linked list for "index" amount
        int count = 0;

        DLLNode<T>* nodePtr = NULL;

        if (head)
        {
            nodePtr = head;

            while (nodePtr && count < index)
            {
                nodePtr = nodePtr->next;
                ++count;
            }

            if (nodePtr)
                return nodePtr->data;
        }

    }

    throw InvalidIndexException(index);
}

template <class T>
DLList<T>* DLList<T>::clone() // Function 7
{
    DLList<T>* result = new DLList<T>();

    // Start with the head, and create and join a list in a similar manner to the current one
    DLLNode<T>* nodePtr = this->head;

    while (nodePtr)
    {
        *result += nodePtr->data;
        nodePtr = nodePtr->next;
    }

    return result;
}

template <class T>
DLList<T>::operator int() const // Function 8
{
    int size = 0;
    DLLNode<T>* nodePtr = NULL;

    if (head)
    {
        nodePtr = head;

        while (nodePtr != NULL)
        {
            nodePtr = nodePtr->next;
            ++size;
        }
    }

    return size;
}

template <class T>
std::ostream& DLList<T>::print(std::ostream& out) const // Function 9
{
    DLLNode<T>* nodePtr = NULL;

    if (head)
    {
        nodePtr = head;

        while (nodePtr->next != NULL)
        {
            out << nodePtr->data << ",";
            nodePtr = nodePtr->next;
        }
        out << nodePtr->data;
    }else
        out << "EMPTY";

    return out;
}
