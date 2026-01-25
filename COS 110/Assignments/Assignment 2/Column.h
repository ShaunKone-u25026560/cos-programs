#ifndef COLUMN_H
#define COLUMN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"
#include "TemplateFunctions.h"

class Column;
class BooleanColumn;
class CharacterColumn;
class IntegerColumn;
class RealValueColumn;
class TextColumn;

class Column
{
    protected:
        std::string columnName; // Member 1
        int columnSize; // Member 2
        Column(std::string columnName = "", int columnSize = 0); // Function 1
    public:
        static Column* createColumnFromSchema(std::string schema); // Function 2
        operator int() const; // Function 3
        operator std::string() const; // Function 4
        bool operator==(const Column&) const; // Function 5
        bool operator!=(const Column&) const; // Function 6
        virtual ~Column(); // Function 7
        virtual Column* clone() const =0; // Function 8
        virtual Column& operator+=(std::string data) =0; // Function 9
        virtual Column& operator-=(std::string data) =0; // Funcion 10
        virtual Column& operator-=(int index) =0; // Function 11
        virtual int operator()(std::string data) const =0; // Function 12
        virtual Column& operator()(std::string value, std::string newValue) =0; // Function 13
        virtual const Element* operator[](int pos) const =0; // Function 14
        virtual const Element* operator[](std::string value) const =0; // Function 15
        virtual bool operator!() const =0; // Function 16
};

#endif /* COLUMN_H */
