#ifndef BOOLEANCOLUMN_H
#define BOOLEANCOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "TemplateFunctions.h"
#include "Column.h"
#include "BooleanElement.h"

class BooleanColumn : public Column
{
    private:
        BooleanElement** array; // Member 1
    public:
        BooleanColumn(std::string columnName, int columnSize); // Function 1
        ~BooleanColumn(); // Function 2
        BooleanColumn* clone() const; // Function 3
        BooleanColumn& operator+=(std::string data); // Function 4
        BooleanColumn& operator-=(std::string data); // Function 5
        BooleanColumn& operator-=(int index); // Function 6
        int operator()(std::string data) const; // Function 7
        BooleanColumn& operator()(std::string value, std::string newValue); // Function 8
        const BooleanElement* operator[](int pos) const; // Function 9
        const BooleanElement* operator[](std::string value) const; // Function 10
        bool operator!() const; // Function 11
};

#endif /* BOOLEANCOLUMN_H */
