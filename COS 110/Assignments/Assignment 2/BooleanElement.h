#ifndef BOOLEANELEMENT_H
#define BOOLEANELEMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"

class BooleanElement : public Element
{
    private:
        bool data; // Member 1
        static bool convert(std::string); // Function 1
        std::ostream& print(std::ostream& out) const; // Function 2
    public:
        BooleanElement(std::string data); // Funciton 3
        bool operator==(const std::string& data) const; // Function 4
        void operator()(const std::string& data); // Function 5
        operator std::string() const; // Function 6
};

#endif /* BOOLEANELEMENT_H */
