#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

template <class T>
class List;
template <class T> 
std::ostream& operator<<(std::ostream& out, const List<T>& list); // Function 8

template <class T>
class List{
    protected:
        virtual std::ostream& print(std::ostream& out) const =0; // Function 10
    public:
        virtual ~List(); // Function 1
        virtual List<T>& operator+=(T&  data) =0; // Function 2
        virtual List<T>& operator-=(T& data) =0; // Function 3
        virtual const T& operator[](int index) const =0; // Function 4
        virtual T& operator[](int index) =0; // Function 5
        virtual operator int() const =0; // Function 6
        virtual List<T>* clone() =0; // Function 7
        template <class U>
        friend std::ostream& operator<<(std::ostream& out, const List<U>& list); // Function 8
        template <class U>
        bool operator==(const U& rhs) const; // Function 9
};

#include "List.cpp"

#endif /* LIST_H */