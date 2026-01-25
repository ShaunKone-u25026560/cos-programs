#ifndef LISTNODE_CPP
#define LISTNODE_CPP

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

#include "ListNode.h"

template <class T>
ListNode<T>::ListNode(T val) // Function 1
            : value(val)
{
    prev = NULL;
    next = NULL;
}

template <class T>
ListNode<T>::~ListNode() // Function 2
{

    if (prev)
    {
        prev->next = NULL;
        delete prev;
        prev = NULL;
    }

    if (next)
    {
        next->prev = NULL;
        delete next;
        next = NULL;
    }
}

template <class T>
T ListNode<T>::getValue() const // Function 3
{
    return value;
}

template <class T>
int ListNode<T>::size() const // Function 4
{
    int count = 1;

    ListNode<T>* crawler = prev;

    while (crawler) // Crawls through previous nodes
    {
        ++count;
        crawler = crawler->prev;
    }

    crawler = next;
    while (crawler)
    {
        ++count;
        crawler = crawler->next;
    }

    return count;
}

template <class T>
void ListNode<T>::append(ListNode<T>* node) // Function 5
{
    if (this != node)
    {
        // Search throught the linked list for this node to ensure it isn't already present
        // Go to the start of the linked list
        ListNode<T>* crawler = this;

        while (crawler->prev) // Gets us to the head of the linked list
        {
                crawler = crawler->prev;
        }

        while (crawler != node && node->prev == NULL) // crawl through until end, looking for the presence on the way
        {
            if (crawler->next == NULL)
            {
                crawler->next = node;
                node->prev = crawler;
                node->next = NULL;
            }else
                crawler = crawler->next;
        }
    }
}

template <class T>
void ListNode<T>::prepend(ListNode<T>* node) // Function 6
{
    if (this != node)
    {
        // Search throught the linked list for this node to ensure it isn't already present
        // Go to the start of the linked list
        ListNode<T>* crawler = this;

        while (crawler->next) // Gets us to the back of the linked list
        {
            crawler = crawler->next;
        }

        while (crawler != node && node->next == NULL) // crawl through until end, looking for the presence on the way
        {
            if (crawler->prev == NULL) // At the head of the linked list
            {
                crawler->prev = node;
                node->next = crawler;
                node->prev = NULL;
            }else
                crawler = crawler->prev;
        }
    }
}

template <class T>
ListNode<T>* ListNode<T>::remove(ListNode<T>* node) // Function 7
{
    // need a pointer for the previous Node and next Node
    if (node)
    {
        ListNode<T>* prevNode = node->prev;
        ListNode<T>* nextNode = node->next;

        if (prevNode)
                prevNode->next = nextNode;

        if (nextNode)
                nextNode->prev = prevNode;

        node->prev = NULL;
        node->next = NULL;
    }else
        return NULL; // Might have to NOT set node to NULL but rather just return NULL


    return node;
}

template <class T>
ListNode<T>* ListNode<T>::remove(int pos) // Function 8
{
    // need a pointer for the previous Node and next Node
    ListNode<T>* prevNode = this->prev;
    ListNode<T>* nodePtr = this;
    ListNode<T>* nextNode = this->next;

    if (pos != 0)
    {
        int count = 0;

        if (pos < 0)
        {
            // Move to the start of the list
            pos *= -1;
            while(prevNode && count < pos)
            {
                nextNode = nodePtr;
                nodePtr = prevNode;
                prevNode = prevNode->prev;
                ++count;
            }
        }

        if (pos > 0)
        {
            while (nextNode && count < pos)
            {
                prevNode = nodePtr;
                nodePtr = nextNode;
                nextNode = nextNode->next;
                ++count;
            }
        }

        if (prevNode && count == pos)
        {
            prevNode->next = nextNode;
        }

        if (nextNode && count == pos)
        {
            nextNode->prev = prevNode;
        }

        if (count < pos)
            return NULL;
        else
        {
            nodePtr->prev = NULL;
            nodePtr->next = NULL;

        }
    }else
        return NULL;

    return nodePtr;
}

template <class T>
ListNode<T>* ListNode<T>::getNodeAt(int pos)// Function 9
{
    // need a pointer for the previous Node and next Node
    ListNode<T>* prevNode = this->prev;
    ListNode<T>* nodePtr = this;
    ListNode<T>* nextNode = this->next;

    if (pos != 0)
    {
        int count = 0;

        if (pos < 0)
        {
            // Move to the start of the list
            pos *= -1;
            while(prevNode && count < pos)
            {
                nextNode = nodePtr;
                nodePtr = prevNode;
                prevNode = prevNode->prev;
                ++count;
            }
        }

        if (pos > 0)
        {
            while (nextNode && count < pos)
            {
                prevNode = nodePtr;
                nodePtr = nextNode;
                nextNode = nextNode->next;
                ++count;
            }
        }

        if (count != pos)
            return NULL;
    }

    return nodePtr;
}

template <class T>
void ListNode<T>::reverseList() // Function 10
{
    // Need to reverse list
    // Start at the back, take the node that comes before it, and swap its allegiance
    ListNode<T>* nodePtr = this;
    ListNode<T>* prevNode = NULL;
    ListNode<T>* nextNode = NULL;

    while (nodePtr->next) // Move to the end of the list
    {
        nodePtr = nodePtr->next;
    } // Now nodePtr is the Last Node in the list

    nextNode = nodePtr->prev;
    while (nodePtr)
    {
        nodePtr->prev = prevNode;
        nodePtr->next = nextNode;

        prevNode = nodePtr;
        nodePtr = nextNode;
        if (nextNode)
            nextNode = nextNode->prev;
    }
}

template <class T>
void ListNode<T>::printList() const // Function 11
{
    // Need to loop through linked list starting from beginning
    // Get to the beginning
    const ListNode<T>* nodePtr = this;
    while (nodePtr->prev)
    {
        nodePtr = nodePtr->prev;
    } // nodePtr is now at the start of the linked list

    // Need to go the end of the linked list, on the way, values must be printed
    while (nodePtr)
    {
        if (nodePtr->next)
            std::cout << nodePtr->value << " ";
        else
            std::cout << nodePtr->value;

        nodePtr = nodePtr->next;
    }

    std::cout << std::endl;
}

#endif //LISTNODE_CPP
