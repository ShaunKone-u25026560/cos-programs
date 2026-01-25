#include "InvalidIndexException.h"

InvalidIndexException::InvalidIndexException(int index, bool isNull) // Function 1
{
    this->index = index;
    this->isNull = isNull;
}

std::string InvalidIndexException::getMessage() const // Function 2
{
    std::stringstream ss;

    if (isNull)
        ss << "Attempted access at invalid index of " << index << " and index was null.";
    else
        ss << "Attempted access at invalid index of " << index << ".";

    return ss.str();
}
