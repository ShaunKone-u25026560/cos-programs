#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "CircularListNode.h"

template <class T>
class CircularList;
template <class T>
ostream& operator<<(ostream& os, const CircularList<T>& list);

template <class T>
class CircularList{
    private:
        CircularListNode<T>* tail; // Member 1
    public:
        CircularList(); // Function 1
        ~CircularList(); // Function 2
        CircularList<T>& operator+=(T data); // Function 3
        CircularList<T>& operator-=(T data); // Function 4
        operator int();  // Function 5
        bool operator[](T data) const; // Function 6
        friend ostream& operator<< <> (ostream& os, const CircularList<T>& list); // Function 7
};

#include "CircularList.cpp"

#endif /* CIRCULARLIST_H */