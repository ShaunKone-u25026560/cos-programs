#include "Tape.h"

Tape::Tape(int tapeSize) // Function 1
{
    // VALIDATE tapeSize Parameter
    if (tapeSize < 0)
        tapeSize = 0;

    // Initialise tape array
    tape = new int[tapeSize];
    for (int i = 0; i < tapeSize; i++) // Initialise all values in array to 0
    {
            tape[i] = 0;
    }

    this->tapeSize = tapeSize;
    head = 0;
}

Tape::~Tape() // Function 2
{
    if (tape)
        delete[] tape;
}

Tape& Tape::operator++() // Function 3
{
    if (tape && head >= 0 && head < tapeSize)
    {
        ++tape[head];
    }

    return *this;
}

Tape& Tape::operator++(int) // Function 4
{
    if (head >= tapeSize - 1)
    {
        throw "end of tape reached\n";
    }else
        ++head;

    return *this;
}

Tape& Tape::operator--() // Function 5
{
    if (tape && head >= 0 && head < tapeSize)
    {
        --tape[head];
    }

    return *this;
}

Tape& Tape::operator--(int) // Function 6
{
    if (head <= 0)
    {
        throw "front of tape reached\n";
    }else
        --head;

    return *this;
}

bool Tape::operator[](int value) const // Function 7
{
    if (tape && head >= 0 && head < tapeSize)
    {
        if (tape[head] == value)
            return true;
    }

    return false;
}

std::istream& operator>>(std::istream& is, Tape& tape) // Function 8
{
    int value;
    is >> value;

    if (is.good())
    {
        //if (tape.head >= 0 && tape.head < tape.tapeSize && tape.tape) // VALIDATION: IF needed
        //{
            tape.tape[tape.head] = value;
        //}
    }else
    {
        throw "Invalid input\n";
    }

    return is;
}

std::ostream& operator<<(std::ostream& is, const Tape& tape) // Function 9
{
    if (tape.tape)
    {
        char result = tape.tape[tape.head];
        is << result << " (" << tape.tape[tape.head] << ")\n" ;
    }

    return is;
}

void Tape::operator!() // Function 10
{
    if (tape)
    {
        for (int i = 0; i < tapeSize; i++) // Set all values in array to 0
        {
                tape[i] = 0;
        }
    }
}
