#include "CharacterElement.h"

char CharacterElement::convert(std::string text) // Function 1
{
    if (text.empty())
        return ' ';
    else
        return text[0];
}

std::ostream& CharacterElement::print(std::ostream& out) const // Function 2
{
    out << data;
    return out;
}

CharacterElement::CharacterElement(std::string data) // Function 3
{
    this->data = convert(data);
}

bool CharacterElement::operator==(const std::string& data) const // Function 3
{
    return (this->data == convert(data));
}

void CharacterElement::operator()(const std::string& data)
{
    this->data = convert(data);
}

CharacterElement::operator std::string() const
{
    std::string result = "";
    result += data;

    return result;
}
