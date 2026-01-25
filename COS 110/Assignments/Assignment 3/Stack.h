#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "List.h"

template <class T>
class Stack : public List<T> {
    private:
        template <class U>
        struct StackNode{
            U data; // StackNode Member 1
            StackNode<U>* next; // StackNode Member 2
        };
        StackNode<T>* top; // Member 1
    public:
        Stack(); // Function 1
        virtual ~Stack(); // Function 2
        Stack<T>& operator+=(T& data); // Function 3
        Stack<T>& operator-=(T& data); // Function 4
        const T& operator[](int index) const; // Function 5
        T& operator[](int index); // Function 6
        Stack<T>* clone(); // Function 7
        operator int() const; // Function 8
    protected:
        std::ostream& print(std::ostream& out) const; // Function 9
};

#include "Stack.cpp"

#endif /* STACK_H */