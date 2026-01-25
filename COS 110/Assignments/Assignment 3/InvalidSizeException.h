#ifndef INVALIDSIZEEXCEPTION_H
#define INVALIDSIZEEXCEPTION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Exception.h"

class InvalidSizeException : public Exception{
    private:
        int size; // Member 1
    public:
        InvalidSizeException(int size); // Function 1
        virtual std::string getMessage() const; // Function 2
};

#endif /* INVALIDSIZEEXCEPTION_H */