#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class Exception{
    public:
        virtual ~Exception(); // Function 1
        friend std::ostream& operator<<(std::ostream& out, const Exception& e); // Function 2
        virtual std::string getMessage() const =0; // Function 3
};

std::ostream& operator<<(std::ostream& out, const Exception& e); // Function 2

#endif /* EXCEPTION_H */