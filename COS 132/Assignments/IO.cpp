#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "IO.h"
#include "Memory.h"
#include "OS.h"
#include "Instructions.h"

int strToInt(std::string str)
{
	if (str.empty())
    {
        return 0;
    }

    bool negative = false;
    std::size_t pos = 0;
    int result = 0;

    if (str[0] == '-')
    {
        negative = true;
        pos = 1;
    }

    else if (str[0] == '+')
    {
        pos = 1;
    }

    for (; pos < str.length(); ++pos)
    {
        char c = str[pos];
        if (c < '0' || c > '9')
        {
            break;
        }

        result = result * 10 + (c - '0');
    }

    return negative ? -result : result;
}

std::string intToBin(int value, int size)
{
	std::string bin = "";

	if (value == 0)
    {
        bin = "0";
    }

	while (value != 0)
	{
		((value % 2) == 0)? bin = "0" + bin: bin = "1" + bin;
		value /= 2;
	}

	int strLength = bin.length();

	if (strLength > size)
    {
       bin = bin.substr(strLength - size, size);
    }else if (strLength < size)
    {
        for (int i = 0; i < size - strLength; i++)
        {
            bin = "0" + bin;
        }
    }


	return bin;
}

void writeToFile(std::string fileName, const int* array, int size)
{

    if (array == NULL || size <= 0)
    {
        return;
    }

	std::ofstream file(fileName.c_str(), std::ios::out);
	if (!file.is_open())
    {
        return;
    }

    for(int i = 0; i < size; i++)
    {
        file << array[i] << std::endl;
    }

	file.close();
}

void readFromFile(std::string fileName, int* array, int size)
{

	if (array == NULL || size <= 0)
	{
	    return;
    }


		std::ifstream file(fileName.c_str(), std::ios::in);

        if (!file.is_open())
        {
            return;
        }

        std::string input;
		for (int i = 0; i < size; i++)
		{
		    if (std::getline(file, input))
            {
                array[i] = strToInt(input);
            }else
            {
                array[i] = 0;
            }
		}

		file.close();
}

void printError(int errorCode)
{
	switch (errorCode)
	{
		case 0: std::cout << "Error: Buffer Is Null\n";
			break;
		case 2: std::cout << "Error: Segfault\n";
			break;
		case 3: std::cout << "Error: Invalid buffer size\n";
			break;
		case 4: std::cout << "Error: Unknown Instruction\n";
			break;
	}
}

int obtainInput()
{
	std::cout << "Please enter an input:\n";
	int input;
	std::cin >> input;
	return input;
}

void printOut(int value)
{
	std::cout << "Printout: " << value << std::endl;
}
