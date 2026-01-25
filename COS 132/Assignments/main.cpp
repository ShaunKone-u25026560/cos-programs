#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

#include "IO.h"
#include "Memory.h"
#include "OS.h"
#include "Instructions.h"

void testIOFunctions()
{
    std::cout << "\n=== Testing IO Functions ===\n";

    // Test string conversions
    std::cout << "strToInt('214'): " << strToInt("214")
              << " (expect 214)\n";
    std::cout << "strToInt('-37'): " << strToInt("-37")
              << " (expect -37)\n";

    // Test binary conversions
    std::cout << "intToBin(9, 4): " << intToBin(9, 4)
              << " (expect 1001)\n";
    std::cout << "intToBin(3, 6): " << intToBin(3, 6)
              << " (expect 000011)\n";

    // Test file operations
    const int testData[] = {5, 10, 15};
    writeToFile("io_test.txt", testData, 3);

    int readData[3] = {0};
    readFromFile("io_test.txt", readData, 3);
    std::cout << "File read: " << readData[0] << ","
              << readData[1] << "," << readData[2] << "\n";
}

void testMemoryBuffer() {
    std::cout << "=== Memory Buffer Test Suite ===\n";

    // Test 1: Invalid buffer creation
    MemoryBuffer::MemoryBufferObject* nullBuffer = NULL;
    MemoryBuffer::createBuffer(nullBuffer, 0);  // Should error
    MemoryBuffer::createBuffer(nullBuffer, -5); // Should error

    // Test 2: Valid buffer operations
    MemoryBuffer::MemoryBufferObject* testBuf = NULL;
    MemoryBuffer::createBuffer(testBuf, 3);  // Valid creation

    // Test 4: Invalid access
    MemoryBuffer::store(testBuf, -1, 10);  // Negative index
    MemoryBuffer::read(testBuf, 3);        // Oversized index

    // Test 5: Pointer operations
    int* ptr = MemoryBuffer::dereference(testBuf, 1);
    if(ptr) *ptr = 42;

    // Test 6: Buffer reinitialization
    MemoryBuffer::createBuffer(testBuf, 5);  // Destroy old buffer

    // Test 7: Null buffer handling
    MemoryBuffer::MemoryBufferObject* nullBuf = NULL;
    MemoryBuffer::store(nullBuf, 0, 10);  // Store to NULL
    MemoryBuffer::read(nullBuf, 0);       // Read from NULL

    // Test 8: Clean destruction
    MemoryBuffer::destroyBuffer(testBuf);
    MemoryBuffer::read(testBuf, 0);       // Read destroyed buffer
}

void testInstructionSet()
{
    std::cout << "\n=== Testing Instruction Set ===\n";

    OperatingSystem::bootComputer(10, 5);

    // Test arithmetic operations
    Instructions::constOp(8, 0);
    Instructions::constOp(5, 1);
    Instructions::addOp(2, 0, 1);
    std::cout << "Add result: "
              << MemoryBuffer::read(ram, 2) << " (expect 13)\n";

    // Test conditional logic
    MemoryBuffer::store(ram, 3, 1);
    int currentLine = 0;
    Instructions::ifOp(3, 5, 2, currentLine);
    std::cout << "Conditional jump: "
              << currentLine << " (expect 5)\n";

    OperatingSystem::shutDownComputer();
}

void testFullProgram()
{
    std::cout << "\n=== Testing Full Program ===\n";

    // Create test program
    std::string hardDrive = "harddrive.txt";
    std::string highLevelFile = "programTask.txt";
    std::string lowLevelFile = "programTaskLow.txt";

	for (int i = 0; i < 3; i++)
	{

		if (i == 1)
		{
			std::cout << "Loaded new Files" << std::endl;
			highLevelFile = "programTest.txt";
			lowLevelFile = "programTestLow.txt";
		}else if (i == 2)
		{
			std::cout << "Loaded new Files" << std::endl;
			highLevelFile = "programEmpty.txt";
			lowLevelFile = "programEmptyLow.txt";
		}

        OperatingSystem::bootComputer(5, 5);
        OperatingSystem::loadHardDrive(hardDrive);

        OperatingSystem::translateProgram(highLevelFile, lowLevelFile);
        OperatingSystem::loadInstructions(lowLevelFile);

        OperatingSystem::executeProgram();

        OperatingSystem::printProgram();
		std::cout << "\nRam Contents" << std::endl;
		MemoryBuffer::printOutContents(ram);

        OperatingSystem::shutDownComputer();

		std::cout << "\nLoop : " << i  << std::endl;
	}
}

int main()
{
    testIOFunctions();
    testMemoryBuffer();
    testInstructionSet();
    testFullProgram();

    // Final memory check
    std::cout << "\n=== Final Memory Check ===\n";
    MemoryBuffer::MemoryBufferObject* finalCheck = NULL;
    MemoryBuffer::createBuffer(finalCheck, 2);
    MemoryBuffer::destroyBuffer(finalCheck);
    std::cout << "Memory system operational\n";

    return 0;
}
