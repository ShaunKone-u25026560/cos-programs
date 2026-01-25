#ifndef INTERGERELEMENT_H
#define INTERGERELEMENT_H

#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

#include "Element.h"

class IntegerElement : public Element
{
    private:
        int data; // Member 1
        static int convert(std::string); // Function 1
        std::ostream& print(std::ostream& out) const; // Function 2
    public:
        IntegerElement(std::string data); // Function 3
        bool operator==(const std::string& data) const; // Function 4
        void operator()(const std::string& data); // Function 5
        operator std::string() const; // Function 6
};

#endif /* INTERGERELEMENT_H */
