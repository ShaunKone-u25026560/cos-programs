#ifndef ELEMENTNOTINLISTEXCEPTION_H
#define ELEMENTNOTINLISTEXCEPTION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Exception.h"

class ElementNotInListException : public Exception{
    public:
        virtual std::string getMessage() const; // Function 1
};

#endif /* ELEMENTNOTINLISTEXCEPTION_H */