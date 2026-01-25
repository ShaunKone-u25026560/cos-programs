#ifndef CHARACTERCOLUMN_H
#define CHARACTERCOLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "CharacterElement.h"

class CharacterColumn : public Column
{
    private:
        CharacterElement** array; // Member 1
    public:
        CharacterColumn(std::string columnName, int columnSize); // Function 1
        ~CharacterColumn(); // Function 2
        CharacterColumn* clone() const; // Function 3
        CharacterColumn& operator+=(std::string data); // Function 4
        CharacterColumn& operator-=(std::string data); // Function 5
        CharacterColumn& operator-=(int index); // Function 6
        int operator()(std::string data) const; // Function 7
        CharacterColumn& operator()(std::string value, std::string newValue); // Function 8
        const CharacterElement* operator[](int pos) const; // Function 9
        const CharacterElement* operator[](std::string value) const; // Function 10
        bool operator!() const; // Function 11
};

#endif /* CHARACTERCOLUMN_H */
