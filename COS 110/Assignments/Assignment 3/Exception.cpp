#include "Exception.h"

Exception::~Exception() // Function 1
{}

std::ostream& operator<<(std::ostream& out, const Exception& e) // Function 2
{
    out << e.getMessage() << std::endl;

    return out;
}
