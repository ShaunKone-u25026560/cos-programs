#ifndef TOOMANYPRINTERSDELETED_H
#define TOOMANYPRINTERSDELETED_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Exception.h"

class TooManyPrintersDeleted : public Exception {
    public:
        virtual std::string getMessage() const; // Function 1
};


#endif /* TOOMANYPRINTERSDELETED_H */