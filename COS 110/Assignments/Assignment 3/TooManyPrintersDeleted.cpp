#include "TooManyPrintersDeleted.h"

std::string TooManyPrintersDeleted::getMessage() const // Function 1
{
    return "More printer references were returned than were requested.";
}
