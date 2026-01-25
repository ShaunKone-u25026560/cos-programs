#ifndef TEXTELEMENT_H
#define TEXTELEMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"

class TextElement : public Element
{
    private:
        std::string data; // Member 1
        std::ostream& print(std::ostream& out) const; // Function 1
    public:
        TextElement(std::string data); // Function 2
        bool operator==(const std::string& data) const; // Function 3
        void operator()(const std::string& data); // Function 4
        operator std::string() const; // Function 5
};

#endif /* TEXTELEMENT_H */
