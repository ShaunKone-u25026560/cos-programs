#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

template <class T>
class Array;
template <class T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array);

template <class T>
class Array{
    private:
        T** data; // Member 1
        int size; // Member 2
    public:
        Array(int size = 1); // Function 1
        virtual ~Array(); // Function 2
        int numElements() const; // Function 3
        operator int() const; // Function 4
        virtual Array<T>& operator+=(T& d); // Function 5
        virtual Array<T>& operator-=(T& d); // Function 6
        virtual const T& operator[](int index) const; // Function 7
        virtual T& operator[](int index); // Function 8
        virtual Array<T>* clone(); // Function 9
        // This is a slightly different way of declaring the operator<< compared to the slides.
        // Note: In EOs, you should follow the format shown in the lecture slides
        template <class U>
        friend std::ostream& operator<<(std::ostream& out, const Array<U>& array); // Function 10
        template <class U>
        bool operator==(const U& rhs) const; // Function 11
};


#include "Array.cpp"

#endif /* ARRAY_H */