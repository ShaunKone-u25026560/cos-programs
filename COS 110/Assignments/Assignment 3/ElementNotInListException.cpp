#include "ElementNotInListException.h"

std::string ElementNotInListException::getMessage() const // Function 1
{
    return "Element was not in the list.";
}
