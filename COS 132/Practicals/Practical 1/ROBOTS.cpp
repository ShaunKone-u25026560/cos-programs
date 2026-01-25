#include "ROBOTS.h"
#include <string>
#include <sstream>
#include <iostream>

//This is provided for you
std::string ROBOTS::intToString(int v)
{
    std::stringstream ss;
    ss << v;
    std::string result;
    ss >> result;
    return result;
}

//Task 1: Validate the input
bool ROBOTS::task1(std::string input)
{
//TODO: Post the AI-generated code here
	// Input is valid if it only contains characters A-Z and 0-9
    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];
        if (!((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))) {
            return false; // Invalid character found
        }
    }
    return true; // All characters are valid
}

// Task 2: Convert input to Base 3 representation
std::string ROBOTS::task2(std::string input)
{
//TODO: Post the AI-generated code here
	// Mapping of characters to their Base 3 codes (from Table 3)
    const char* base3Codes = "0000 0001 0002 0010 0011 0012 0020 0021 0022 0100 0101 0102 0110 0111 0112 0120 0121 0122 0200 0201 0202 0210 0211 0212 0220 0221 0222 1000 1001 1002 1010 1011 1012 1020 1021 1022";
    std::string base3Result;

    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];
        if (ch >= 'A' && ch <= 'Z') {
            // Map A-Z to indices 0-25
            int index = ch - 'A';
            base3Result += std::string(&base3Codes[index * 5], 4); // Each code is 4 characters long
        } else if (ch >= '0' && ch <= '9') {
            // Map 0-9 to indices 26-35
            int index = 26 + (ch - '0');
            base3Result += std::string(&base3Codes[index * 5], 4); // Each code is 4 characters long
        }
    }
    return base3Result;
}

// Task 3: Translate the converted input using Table 4
std::string ROBOTS::task3(std::string convertedInput)
{
//TODO: Post the AI-generated code here
std::string translatedResult;
    for (size_t i = 0; i < convertedInput.size(); ++i) {
        char ch = convertedInput[i];
        switch (ch) {
            case '0': translatedResult += 'A'; break; // 0 -> A
            case '1': translatedResult += 'B'; break; // 1 -> B
            case '2': translatedResult += 'C'; break; // 2 -> C
            default: break; // Ignore invalid characters (though task1 ensures validity)
        }
    }
    return translatedResult;
}

// Task 4: Expand the translated input
std::string ROBOTS::task4(std::string translatedInput)
{
//TODO: Post the AI-generated code here
	 if (translatedInput.empty()) {
        return ""; // Handle empty input
    }

    std::string expandedResult;
    char currentChar = translatedInput[0];
    int count = 1;

    for (size_t i = 1; i < translatedInput.size(); ++i) {
        if (translatedInput[i] == currentChar) {
            count++; // Increment count for consecutive characters
        } else {
            expandedResult += intToString(count) + currentChar; // Append count and character
            currentChar = translatedInput[i]; // Update current character
            count = 1; // Reset count
        }
    }

    // Append the last character and its count
    expandedResult += intToString(count) + currentChar;
    return expandedResult;
}


