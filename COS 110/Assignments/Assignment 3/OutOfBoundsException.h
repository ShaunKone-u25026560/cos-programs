#ifndef OUTOFBOUNDSEXCEPTION_H
#define OUTOFBOUNDSEXCEPTION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Exception.h"

class OutOfBoundsException : public Exception{
    public:
        virtual std::string getMessage() const; // Function 1
};

#endif /* OUTOFBOUNDSEXCEPTION_H */