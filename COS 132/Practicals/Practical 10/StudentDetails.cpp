#include <string>
#include <sstream>
#include <iostream>
#include "StudentDetails.h"

struct StudentDetails;

StudentDetails* constructor(std::string line)
{
    StudentDetails *newStud = new StudentDetails;

    stringstream ss(line);
    string firstName;
    string lastName;

    // Capitalise first Name
    // Iterate through first Name using characters (c-style strings)
    std::getline(ss, firstName, ',');
    char letter[] = firstName;

    // Iterate through each character, setting each letter to its uppercase version
    int i = 0;
    while (letter[i] != '\0')
    {
        if (letter[i] >= 'a' && letter[i] <= 'z')
            firstName[i] = letter[i] - 32;

        i++;
    }

    std::getline(ss, lastName, ',');
    letter = lastName;
    i = 0;
    while (letter[i] != '\0')
    {
        if (letter[i] >= 'a' && letter[i] <= 'z')
            lastName[i] = letter[i] - 32;

        i++;
    }



}
StudentDetails* constructor(std::string fName, std::string lName, int studentNumber, float mark,  bool didPrepWork)
void destructor(StudentDetails*& stdDetails)
std::string toString(StudentDetails& stdDetails)
