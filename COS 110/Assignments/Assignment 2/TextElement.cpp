#include "TextElement.h"

std::ostream& TextElement::print(std::ostream& out) const // Function 2
{
    out << data;

    return out;
}

TextElement::TextElement(std::string data) // Function 3
{
    this->data = data;
}

bool TextElement::operator==(const std::string& data) const // Function 4
{
    return (this->data == data);
}

void TextElement::operator()(const std::string& data) // Function 5
{
    this->data = data;
}

TextElement::operator std::string() const // Function 6
{
    return data;
}
