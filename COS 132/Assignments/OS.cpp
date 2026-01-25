#include <string>
#include <fstream>

#include "IO.h"
#include "Memory.h"
#include "OS.h"
#include "Instructions.h"

namespace OperatingSystem
{
    Instructions::Instruction** programInstructions = NULL;
    int numberOfInstructions = 0;
    int currentInstructionNumber = 0;


    void bootComputer(int ramSize, int storageSize)
    {
        MemoryBuffer::createBuffer(ram, ramSize);
        MemoryBuffer::createBuffer(storage, storageSize);

        // initialise ram
        for (int i = 0; i < ramSize; i++)
        {
            MemoryBuffer::store(ram, i, 0);
        }

        // initialise storage
        for (int i = 0; i < storageSize; i++)
        {
            MemoryBuffer::store(storage, i, 0);
        }

        currentInstructionNumber = 0;
        Instructions::halt = false;
    }

    void shutDownComputer()
    {
        // deallocate ram memory
        MemoryBuffer::destroyBuffer(ram);

        // deallocate storage memory
        MemoryBuffer::destroyBuffer(storage);

        // deallocate program instructions
        for (int i = 0; i < numberOfInstructions; i++)
        {
            Instructions::destroyInstruction(programInstructions[i]);
        }

        delete[] programInstructions;
        programInstructions = NULL;
    }

    void loadHardDrive(std::string hardDriveDiskName)
    {
        if (storage == NULL || storage->buffer == NULL)
        {
            return;
        }

        readFromFile(hardDriveDiskName, storage->buffer, storage->bufferSize);
    }

    int determineNumberOfInstructions(std::string programFile)
    {
        std::ifstream file(programFile.c_str(), std::ios::in);

        if (!file.is_open())
        {
            return 0;
        }

        int count = 0;
        std::string instruction;

        while (std::getline(file, instruction))
        {
                ++count;
        }

        file.close();

        return count;
    }

    void loadInstructions(std::string programFile)
    {
        std::ifstream file(programFile.c_str(), std::ios::in);
        if (!file.is_open())
        {
            return;
        }

        numberOfInstructions = determineNumberOfInstructions(programFile);
        programInstructions = new Instructions::Instruction*[numberOfInstructions];

        std::string instruction;
        int count = 0;

        while (std::getline(file, instruction))
        {
            programInstructions[count] = Instructions::createInstruction(instruction);
            count++;
        }

        file.close();
    }

    void executeProgram()
    {
        int temp = currentInstructionNumber;

        while (currentInstructionNumber < numberOfInstructions && !Instructions::halt)
        {
            Instructions::executeInstruction(programInstructions[currentInstructionNumber], currentInstructionNumber);

            if (currentInstructionNumber == temp)
                ++currentInstructionNumber;

            temp = currentInstructionNumber;
        }
    }

    void printProgram()
    {
        for (int i = 0; i < numberOfInstructions; i++)
        {
            Instructions::debugPrintout(programInstructions[i]);
        }
    }

    void translateProgram(std::string highLevelFile, std::string lowLevelFile)
    {
        std::ifstream highFile(highLevelFile.c_str(), std::ios::in);
        std::ofstream lowFile(lowLevelFile.c_str(), std::ios::out);

        if (!highFile.is_open() || !lowFile.is_open())
        {
            printError(0);
            return;
        }

        int numInstructions = determineNumberOfInstructions(highLevelFile);
        std::string line = "";
        std::string strNumber = "";
        std::string inputString;
        int number = 0;
        int len;

        for (int i = 0; i < numInstructions; i++)
        {
            inputString = "";
            highFile >> line;

            len = line.length();
            for (int j = 0; j < len; j++)
            {
                if (line[j] != ',')
                {
                    strNumber += line[j];
                }

                if (line[j] == ',' || (j + 1 == len))
                {
                    number = strToInt(strNumber);
                    inputString += intToBin(number, 4);

                    strNumber = "";
                }
            }

            if (i != numInstructions -1)
                lowFile << inputString << std::endl;
            else
                lowFile << inputString;
        }

        highFile.close();
        lowFile.close();

    }

}
