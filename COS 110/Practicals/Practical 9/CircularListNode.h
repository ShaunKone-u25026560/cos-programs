#ifndef CIRCULARLISTNODE_H
#define CIRCULARLISTNODE_H

#include <iostream>

using namespace std;

template <class T>
class CircularList;
template <class T>
ostream& operator<<(ostream& os, const CircularList<T>& list);  // This function is for the CircularList class, but we want it to be friend to acces private members.

template <class T>
class CircularListNode {
    //friend FFCircularList<T>;
    friend CircularList<T>;

   private:
    T data;
    CircularListNode<T>* next;

   public:
    CircularListNode(T data);
    ~CircularListNode();

    friend ostream& operator<< <>(ostream& os, const CircularList<T>& list);  // NOT implemented in CircularListNode.cpp , but rather you should implement it in CircularList.cpp
};

#include "CircularListNode.cpp"

#endif