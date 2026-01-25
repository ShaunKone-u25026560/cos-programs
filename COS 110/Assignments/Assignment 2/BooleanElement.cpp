#include "BooleanElement.h"

bool BooleanElement::convert(std::string text) // Function 1
{
    if (text == "T")
        return true;
    else
        return false;
}

std::ostream& BooleanElement::print(std::ostream& out) const // Function 2
{
    if (data)
        out << "T";
    else
        out << "F";

    return out;
}

BooleanElement::BooleanElement(std::string data) // Function 3
{
    if (convert(data))
        this->data = true;
    else
        this->data = false;
}

bool BooleanElement::operator==(const std::string& data) const // Function 4
{
    return (convert(data) == this->data);
}

void BooleanElement::operator()(const std::string& data) // Function 5
{
    this->data = convert(data);
}

BooleanElement::operator std::string() const // Function 6
{
    if (data)
        return "T";
    else
        return "F";
}
