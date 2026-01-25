#include "InvalidSizeException.h"

InvalidSizeException::InvalidSizeException(int size) // Function 1
{
    this->size = size;
}

std::string InvalidSizeException::getMessage() const // Function 2
{
    std::stringstream ss;

    ss << "Invalid size of " << size << " was passed in.";

    return ss.str();
}
