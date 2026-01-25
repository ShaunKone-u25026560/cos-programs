#ifndef PRINTERNOTINITIALIZED_H
#define PRINTERNOTINITIALIZED_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Exception.h"

class PrinterNotInitialized : public Exception{
    public:
        virtual std::string getMessage() const; // Function 1
};

#endif /* PRINTERNOTINITIALIZED_H */