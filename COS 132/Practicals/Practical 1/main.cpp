#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "ROBOTS.h"

using namespace std;

void studentAlgorithm(string input)
{
    cout << "This is a test" << endl;
    cout << "Enter droid name: ";
    cout << input << endl;
    if (ROBOTS::task1(input))
    {
        cout << "Input was valid... progressing to next phase" << endl;
        string convertedInput = ROBOTS::task2(input);
        cout << "Converted: " << convertedInput << endl;
        string translatedInput = ROBOTS::task3(convertedInput);
        cout << "Translated: " << translatedInput << endl;
        string expandedInput = ROBOTS::task4(translatedInput);
        cout << "Expanded: " << expandedInput << endl;
    }
    else {
        cout << "Input was invalid... halting execution" << endl;
    }
}

int main(int argc, char const *argv[])
{
    studentAlgorithm("R2D2"); // Testing the program with valid input
    studentAlgorithm(""); // Testing the program with no input
    studentAlgorithm("@#*!"); // Testing the program with special characters
    studentAlgorithm("r23g"); // Testing the program with lowercase letters
    //You will need to copy the above line to and change the passed in parameter (the "R2D2") to test your code
	studentAlgorithm("R2D2");
}
