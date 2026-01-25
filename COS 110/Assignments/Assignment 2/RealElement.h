#ifndef REALELEMENT_H
#define REALELEMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"

class RealElement : public Element
{
    private:
        float data; // Member 1
        static float convert(std::string); // Function 1
        std::ostream& print(std::ostream& out) const; // Function 2
    public:
        RealElement(std::string data); // Function 3
        bool operator==(const std::string& data) const; // Function 4
        void operator()(const std::string& data); // Function 5
        operator std::string() const; // Function 6
};

#endif /* REALELEMENT_H */
