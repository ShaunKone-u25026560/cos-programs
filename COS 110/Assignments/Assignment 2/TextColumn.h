#ifndef TEXTCOLUMN_H
#define TEXTCOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "TextElement.h"

class TextColumn : public Column
{
    private:
        TextElement** array; // Member 1
    public:
        TextColumn(std::string columnName, int columnSize); // Function 1
        ~TextColumn(); // Function 2
        TextColumn* clone() const; // Function 3
        TextColumn& operator+=(std::string data); // Function 4
        TextColumn& operator-=(std::string data); // Function 5
        TextColumn& operator-=(int index); // Function 6
        int operator()(std::string data) const; // Function 7
        TextColumn& operator()(std::string value, std::string newValue); // Function 8
        const TextElement* operator[](int pos) const; // Function 9
        const TextElement* operator[](std::string value) const; // Function 10
        bool operator!() const; // Function 11
};

#endif /* TEXTCOLUMN_H */
