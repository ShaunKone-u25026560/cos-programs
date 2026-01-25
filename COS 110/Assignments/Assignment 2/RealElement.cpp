#include "RealElement.h"

float RealElement::convert(std::string text) // Function 1
{
    std::stringstream ss(text);
    float result = 0.0f;

    ss >> result;

    return result;
}

std::ostream& RealElement::print(std::ostream& out) const // Function 2
{
    std::stringstream ss;
    ss << data;

    out << ss.str();

    return out;
}

RealElement::RealElement(std::string data) // Function 3
{
    this->data = convert(data);
}

bool RealElement::operator==(const std::string& data) const // Function 4
{
    return (this->data == convert(data));
}

void RealElement::operator()(const std::string& data) // Function 5
{
    this->data = convert(data);
}

RealElement::operator std::string() const // Function 6
{
    std::stringstream ss;
    ss << data;

    return ss.str();
}
