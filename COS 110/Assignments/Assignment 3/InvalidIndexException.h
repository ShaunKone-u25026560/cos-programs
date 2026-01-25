#ifndef INVALIDINDEXEXCEPTION_H
#define INVALIDINDEXEXCEPTION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Exception.h"

class InvalidIndexException : public Exception{
    private:
        int index; // Member 1
        bool isNull; // Member 2
    public:
        InvalidIndexException(int index, bool isNull = false); // Function 1
        virtual std::string getMessage() const; // Function 2
};

#endif /* INVALIDINDEXEXCEPTION_H */