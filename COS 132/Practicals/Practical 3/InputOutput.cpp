#include <iostream>
#include <string>
#include "InputOutput.h"

std::string askForStringInput(std::string message)
{
    std::string input;

    std::cout << message << std::endl;

    std::getline(std::cin, input);

    return input;
}

int askForIntInput(std::string message)
{
    int input;

    std::cout << message << std::endl;

    std::cin >> input;

    return input;
}

void printOut(std::string message)
{
    std::cout << message << std::endl;
}
