#include "IntegerElement.h"

int IntegerElement::convert(std::string text) // Function 1
{
    std::stringstream ss(text);
    int result = 0;

    ss >> result;

    return result;
}

std::ostream& IntegerElement::print(std::ostream& out) const // Function 2
{
    std::stringstream ss;
    ss << data;

    out << ss.str();

    return out;
}

IntegerElement::IntegerElement(std::string data) // Function 3
{
    this->data = convert(data);
}

bool IntegerElement::operator==(const std::string& data) const // Function 4
{
    return (this->data == convert(data));
}

void IntegerElement::operator()(const std::string& data) // Function 5
{
    this->data = convert(data);
}

IntegerElement::operator std::string() const // Function 6
{
    std::stringstream ss;
    ss << data;

    return ss.str();
}
