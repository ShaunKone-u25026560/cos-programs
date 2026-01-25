#ifndef BRAINHURT_H
#define BRAINHURT_H

#include <iostream>
#include <string>
#include <sstream>
#include "Tape.h"

class Brainhurt{
private:
    Tape* tape; // Member 1
public:
    Brainhurt(int tapeSize); // Function 1
    ~Brainhurt(); // Function 2
    void operator()(std::string code, std::istream& in, std::ostream& out); // Function 3
};


#endif // BRAINHURT_H
