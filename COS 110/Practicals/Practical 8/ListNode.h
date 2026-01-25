#ifndef LISTNODE_H
#define LISTNODE_H

template<class T>
class ListNode {
    private:
        T value; // Member 1
        ListNode<T>* prev; // Member 2
        ListNode<T>* next; // Member 3
    public:
        ListNode(T val); // Function 1
        ~ListNode(); // Function 2
        T getValue() const; // Function 3
        int size() const; // Function 4
        void append(ListNode<T>* node); // Function 5
        void prepend(ListNode<T>* node); // Function 6
        static ListNode<T>* remove(ListNode<T>* node); // Function 7
        ListNode<T>* remove(int pos); // Function 8
        ListNode<T>* getNodeAt(int pos); // Function 9
        void reverseList(); // Function 10
        void printList() const; // Function 11
};

#include "ListNode.cpp"

#endif //LISTNODE_H