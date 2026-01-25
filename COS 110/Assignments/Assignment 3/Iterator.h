#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

template < template <class> class Iterable, class T >
class Iterator{
    private:
        Iterable<T> iterable; // Member 1
        int currentPosition; // Member 2
    public:
        Iterator(); // Function 1
        Iterator<Iterable, T>& operator++(int i); // Function 2
        Iterator<Iterable, T>& operator++(); // Function 3
        Iterator<Iterable, T>& operator--(int i); // Function 4
        Iterator<Iterable, T>& operator--(); // Function 5
        operator T&(); // Function 6
        void setStart(); // Function 7
        void setEnd(); // Function 8
        bool isAtStart() const; // Function 9
        bool isAtEnd() const; // Function 10
        Iterator<Iterable, T>& operator+=(T& data); // Function 11
        Iterator<Iterable, T>& operator-=(T& data); // Function 12
};

#include "Iterator.cpp"

#endif /* ITERATOR_H */