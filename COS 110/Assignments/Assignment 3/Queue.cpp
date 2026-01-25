#include "InvalidIndexException.h"

template <class T>
Queue<T>::Queue() // Function 1
{
    front = NULL;
    rear = NULL;
}

template <class T>
Queue<T>::~Queue() // Function 2
{
    // Start deallocating linked nodes from front
    QueueNode<T>* prevPtr = NULL;

    if (front)
    {
        while (front != rear)
        {
            prevPtr = front;
            front = front->next;
            delete prevPtr;
        }

        delete front;
    }

    front = NULL;
    rear = NULL;
}

template <class T>
Queue<T>& Queue<T>::operator+=(T& data) // Function 3
{
    QueueNode<T>* newNode = new QueueNode<T>;
    newNode->data = data;
    newNode->next = NULL;


    if (rear)
    {
        rear->next = newNode;
    }

    if (!front)
    {
        front = newNode;
    }

    rear = newNode;

    return *this;
}

template <class T>
Queue<T>& Queue<T>::operator-=(T& data) // Function 4
{
    QueueNode<T>* nodePtr = NULL;

    if (front)
    {
        // Remove from the front
        data = front->data;
        nodePtr = front;

        if (front == rear || front->next == NULL)
        {
            front = NULL;
            rear = NULL;
        }else
            front = front->next;

        delete nodePtr;
    }

    return *this;
}

template <class T>
const T& Queue<T>::operator[](int index) const // Function 5
{
    if (front)
    {
        int count = 0;
        QueueNode<T>* nodePtr = front;

        while (nodePtr != rear && count < index)
        {
            nodePtr = nodePtr->next;
            ++count;
        }

        if (count == index) // Means the node was found
        {
            return nodePtr->data;
        }
    }

    throw InvalidIndexException(index);
}

template <class T>
T& Queue<T>::operator[](int index) // Function 6
{
    if (front)
    {
        int count = 0;
        QueueNode<T>* nodePtr = front;

        while (nodePtr != rear && count < index)
        {
            nodePtr = nodePtr->next;
            ++count;
        }

        if (count == index) // Means the node was found
        {
            return nodePtr->data;
        }
    }

    throw InvalidIndexException(index);
}

template <class T>
Queue<T>* Queue<T>::clone() // Function 7
{
    Queue<T>* result = new Queue<T>();

    QueueNode<T>* nodePtr = this->front;

    while (nodePtr && nodePtr != this->rear)
    {
        *result += nodePtr->data;
        nodePtr = nodePtr->next;
    }

    if (nodePtr)
        *result += nodePtr->data;

    return result;
}

template <class T>
Queue<T>::operator int() const// Function 8
{
    int size = 0;

    if (front)
    {
        QueueNode<T>* nodePtr = front;

        while (nodePtr != rear)
        {
            nodePtr = nodePtr->next;
            ++size;
        }

        ++size;
    }

    return size;
}

template <class T>
std::ostream& Queue<T>::print(std::ostream& out) const// Function 9
{
    QueueNode<T>* nodePtr = NULL;

    if (front)
    {
        nodePtr = front;
        while (nodePtr != rear)
        {
            out << nodePtr->data << ",";
            nodePtr = nodePtr->next;
        }

        out << nodePtr->data;
    }else
        out << "EMPTY";

    return out;
}
