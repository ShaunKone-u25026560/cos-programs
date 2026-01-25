#include "OutOfBoundsException.h"

std::string OutOfBoundsException::getMessage() const // Function 1
{
    return "The iterator went outside of the bounds of the iterable object.";
}
