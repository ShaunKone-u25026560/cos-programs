template <class T>
CircularList<T>::CircularList() // Function 1
{
    tail = NULL;
}

template <class T>
CircularList<T>::~CircularList() // Function 2
{
    if (tail)
    {
        CircularListNode<T>* nodePtr = tail->next;
        CircularListNode<T>* prevNode = NULL;

        while (nodePtr != tail)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            delete prevNode;
        }

        delete tail;
        tail = NULL;
    }
}

template <class T>
CircularList<T>& CircularList<T>::operator+=(T data) // Function 3
{

    CircularListNode<T>* newNode = new CircularListNode<T>(data);
    CircularListNode<T>* nodePtr = NULL;

    if (tail)
    {
        nodePtr = tail->next;

        while (nodePtr != tail && nodePtr->next->data < data)
        {
            nodePtr = nodePtr->next;
        }

        if (nodePtr == tail->next && nodePtr->data > data) // Place new Node at the very start if it is located at the very beginning of the nodes
        {
            newNode->next = nodePtr;
            tail->next = newNode;
        }else if (nodePtr == tail) // If it's at the end, it means we append
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }else
        {
            // If it's in the middle, we insert between the current node and the next node
            newNode->next = nodePtr->next;
            nodePtr->next = newNode;
        }
    }else
    {
        tail = newNode;
        newNode->next = newNode;
    }

    return *this;
}

template <class T>
CircularList<T>& CircularList<T>::operator-=(T data) // Function 4
{
    CircularListNode<T>* nodePtr = NULL;
    CircularListNode<T>* prevPtr = NULL;

    if (tail)
    {
        nodePtr = tail->next;

        while (nodePtr != tail && nodePtr->data != data) // Stop at end node or node just before found value
        {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr->data == data)
        {
            if (prevPtr)
            {
                prevPtr->next = nodePtr->next; // PrevPtr now points to head OR node after nodePtr
            }else // Data was found at head
            {
                tail->next = nodePtr->next;
            }

            if (nodePtr == tail)
            {
                tail = prevPtr;
            }

            delete nodePtr;
            nodePtr = NULL;
        }
    }

    return *this;
}

template <class T>
CircularList<T>::operator int()  // Function 5
{
    CircularListNode<T>* nodePtr = NULL;
    int size = 0;

    if (tail)
    {
        nodePtr = tail->next;

        while (nodePtr != tail)
        {
            nodePtr = nodePtr->next;
            ++size;
        }

        ++size;
    }

    return size;
}

template <class T>
bool CircularList<T>::operator[](T data) const// Function 6
{
    CircularListNode<T>* nodePtr = NULL;

    if (tail)
    {
        nodePtr = tail->next;

        while (nodePtr != tail && nodePtr->data != data)
        {
            nodePtr = nodePtr->next;
        }

        if (nodePtr->data == data)
            return true;
    }

    return false;
}

template <class T>
ostream& operator<<(ostream& os, const CircularList<T>& list) // Function 7
{
    CircularListNode<T>* nodePtr = NULL;

    if (list.tail)
    {
        nodePtr = list.tail->next;

        while (nodePtr != list.tail)
        {
            os << nodePtr->data << "->";
            nodePtr = nodePtr->next;
        }

        os << nodePtr->data << std::endl;
    }else
    {
        os << "Empty List" << endl;
    }

    return os;
}
