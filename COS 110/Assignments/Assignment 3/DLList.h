#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "List.h"

template <class T>
class DLList : public List<T>{
    private:
        template <class U>
        struct DLLNode{
            U data; // DLLNode Member 1
            DLLNode<U>* next; // DLLNode Member 2
            DLLNode<U>* prev; // DLLNode Member 3
        };

        DLLNode<T>* head; // Member 1
    public:
        DLList(); // Function 1
        virtual ~DLList(); // Function 2
        DLList<T>& operator+=(T& data); // Function 3
        DLList<T>& operator-=(T& data); // Function 4
        const T& operator[](int index) const; // Function 5
        T& operator[](int index); // Function 6
        DLList<T>* clone(); // Function 7
        operator int() const; // Function 8
    protected:
        std::ostream& print(std::ostream& out) const; // Function 9
};

#include "DLList.cpp"

#endif /* DLLIST_H */