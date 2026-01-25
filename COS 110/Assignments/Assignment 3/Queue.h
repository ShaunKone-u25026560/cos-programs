#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "List.h"

template <class T>
class Queue : public List<T>{
    private:
        template <class U>
        struct QueueNode{
            U data; // QueueNode Member 1
            QueueNode<U>* next; // QueueNode Member 2
        };
        QueueNode<T>* front; // Member 1
        QueueNode<T>* rear; // Member 2
    public:
        Queue(); // Function 1
        virtual ~Queue(); // Function 2
        Queue<T>& operator+=(T& data); // Function 3
        Queue<T>& operator-=(T& data); // Function 4
        const T& operator[](int index) const; // Function 5
        T& operator[](int index); // Function 6
        Queue<T>* clone(); // Function 7
        operator int() const; // Function 8
    protected:
        std::ostream& print(std::ostream& out) const; // Function 9
};

#include "Queue.cpp"

#endif /* QUEUE_H */