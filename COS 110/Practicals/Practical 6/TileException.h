#ifndef TILEEXCEPTION_H
#define TILEEXCEPTION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class TileException
{
    private:
        std::string message; // Member 1
    public:
        TileException(const std::string& message); // Function 1
        std::string getMessage() const; // Function 2
};

#endif /* TILEEXCEPTION_H*/