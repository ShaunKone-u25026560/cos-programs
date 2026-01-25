#include "TileException.h"

TileException::TileException(const std::string& message) // Function 1
{
    this->message = message;
}

std::string TileException::getMessage() const // Function 2
{
    return message;
}
