#ifndef REALVALUECOLUMN_H
#define REALVALUECOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "RealElement.h"

class RealValueColumn : public Column
{
    private:
        RealElement** array; // Member 1
    public:
        RealValueColumn(std::string columnName, int columnSize); // Function 1
        ~RealValueColumn(); // Function 2
        RealValueColumn* clone() const; // Function 3
        RealValueColumn& operator+=(std::string data); // Function 4
        RealValueColumn& operator-=(std::string data); // Function 5
        RealValueColumn& operator-=(int index); // Function 6
        int operator()(std::string data) const; // Function 7
        RealValueColumn& operator()(std::string value, std::string newValue); // Function 8
        const RealElement* operator[](int pos) const; // Function 9
        const RealElement* operator[](std::string value) const; // Function 10
        bool operator!() const; // Function 11
};

#endif /* REALVALUECOLUMN_H */
