#include "InvalidIndexException.h"

template <class T>
Stack<T>::Stack() // Function 1
{
    top = NULL;
}

template <class T>
Stack<T>::~Stack() // Function 2
{
    StackNode<T>* nodePtr = NULL;

    while (top != NULL)
    {
        nodePtr = top;
        top = top->next;
        delete nodePtr;
    }
}

template <class T>
Stack<T>& Stack<T>::operator+=(T& data) // Function 3
{
    StackNode<T>* newNode = new StackNode<T>;
    newNode->data = data;
    newNode->next = NULL;

    if (top)
        newNode->next = top;

    top = newNode;

    return *this;
}

template <class T>
Stack<T>& Stack<T>::operator-=(T& data) // Function 4
{
    StackNode<T>* nodePtr = NULL;

    if (top)
    {
        nodePtr = top;
        data = nodePtr->data;
        top = top->next;
        delete nodePtr;
    }

    return *this;
}

template <class T>
const T& Stack<T>::operator[](int index) const // Function 5
{
    StackNode<T>* nodePtr = NULL;

    if (top)
    {
        nodePtr = top;
        int count = 0;

        while (nodePtr && count < index)
        {
            nodePtr = nodePtr->next;
            ++count;
        }

        if (nodePtr && count == index)
            return nodePtr->data;
    }

    throw InvalidIndexException(index);
}

template <class T>
T& Stack<T>::operator[](int index) // Function 6
{
    StackNode<T>* nodePtr = NULL;

    if (top)
    {
        nodePtr = top;
        int count = 0;

        while (nodePtr && count < index)
        {
            nodePtr = nodePtr->next;
            ++count;
        }

        if (nodePtr && count == index)
            return nodePtr->data;
    }

    throw InvalidIndexException(index);
}

template <class T>
Stack<T>* Stack<T>::clone() // Function 7
{
    Stack<T>* result = new Stack<T>();

    // Start with the head, and create and join a list in a similar manner to the current one
    StackNode<T>* nodePtr = this->top;

    while (nodePtr)
    {
        *result += nodePtr->data;
        nodePtr = nodePtr->next;
    }

    return result;
}

template <class T>
Stack<T>::operator int() const// Function 8
{
    int size = 0;
    StackNode<T>* nodePtr = NULL;

    if (top)
    {
        nodePtr = top;

        while (nodePtr != NULL)
        {
            nodePtr = nodePtr->next;
            ++size;
        }
    }

    return size;
}

template <class T>
std::ostream& Stack<T>::print(std::ostream& out) const// Function 9
{
    StackNode<T>* nodePtr = NULL;

    if (top)
    {
        nodePtr = top;

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
