#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <sstream>
#include <string>

class Tape{
private:
    int* tape; // Member 1
    int tapeSize; // Member 2
    int head; // Member 3
public:
    Tape(int tapeSize); // Function 1
    ~Tape(); // Function 2

    Tape& operator++(); // Function 3
    Tape& operator++(int); // Function 4
    Tape& operator--(); // Function 5
    Tape& operator--(int); // Function 6
    bool operator[](int value) const; // Function 7

    friend std::istream& operator>>(std::istream& is, Tape& tape); // Function 8
    friend std::ostream& operator<<(std::ostream& is, const Tape& tape); // Function 9

    void operator!(); // Function 10
};

std::istream& operator>>(std::istream& is, Tape& tape); // Function 8
std::ostream& operator<<(std::ostream& is, const Tape& tape); // Function 9

#endif // TAPE_H
