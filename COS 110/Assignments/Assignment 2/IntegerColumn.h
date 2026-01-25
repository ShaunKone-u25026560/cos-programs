#ifndef INTERGERCOLUMN_H
#define INTERGERCOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "IntegerElement.h"

class IntegerColumn : public Column
{
    private:
        IntegerElement** array; // Member 1
    public:
        IntegerColumn(std::string columnName, int columnSize); // Function 1
        ~IntegerColumn(); // Function 2
        IntegerColumn* clone() const; // Function 3
        IntegerColumn& operator+=(std::string data); // Function 4
        IntegerColumn& operator-=(std::string data); // Function 5
        IntegerColumn& operator-=(int index); // Function 6
        int operator()(std::string data) const; // Function 7
        IntegerColumn& operator()(std::string value, std::string newValue); // Function 8
        const IntegerElement* operator[](int pos) const; // Function 9
        const IntegerElement* operator[](std::string value) const; // Function 10
        bool operator!() const; // Function 11
};

#endif /* INTERGERCOLUMN_H */
