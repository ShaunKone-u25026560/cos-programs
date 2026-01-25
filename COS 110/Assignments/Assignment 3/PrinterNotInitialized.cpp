#include "PrinterNotInitialized.h"

std::string PrinterNotInitialized::getMessage() const // Function 1
{
    return "Attempted to print or add a document, but no printer has been requested yet.";
}
