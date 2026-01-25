#include <string>
#include <iostream>
#include <cmath>
#include "IO.h"
#include "Memory.h"
#include "OS.h"
#include "Instructions.h"

namespace Instructions
{
    bool halt;
    struct Instruction;

    Instruction *createInstruction(std::string strInstruction)
    {
        if (strInstruction.empty())
            return NULL;

        int opcode = 0;

        for (int i = 0; i < 4; ++i) {
            opcode = (opcode << 1) + (strInstruction[i] - '0');
        }

        int expectedOps = determineNumberOfOperands(opcode);

        int strLength = strInstruction.length();

        if (strLength < 4 + (expectedOps * 4))
        {
            return NULL;
        }

        Instruction *newInstruction = new Instruction;
        newInstruction->opcode = opcode;
        newInstruction->operands = (expectedOps > 0)? new int[expectedOps] : NULL;

        for (int i = 0; i < expectedOps; i++)
        {
            int start = 4 + (i * 4);
            int val = 0;

            for (int b = 0; b < 4; ++b)
            {
                val = (val << 1) + (strInstruction[start + b] - '0');
            }

                newInstruction->operands[i] = val;
        }

        return newInstruction;
    }


    void destroyInstruction(Instruction*& instruction)
    {
        if (instruction == NULL)
            return;

        // Deallocate dynamic/heap memory
        delete[] instruction->operands;
        delete instruction;
        instruction = NULL;
    }

	int binaryToInt(std::string binaryString)
	{
		int result = 0;

		for (int i = binaryString.length() - 1, j = 0; i >= 0; i--, j++)
			result += (binaryString[j] - 48) * pow(2, i);

		return result;
	}

	int determineNumberOfOperands(int opcode)
	{
		if (opcode == 1 || opcode == 2 || opcode == 14 || opcode == 15)
		{
			return 2;
		}else if (opcode >= 3 && opcode <= 8)
		{
			return 3;
		}else if (opcode >= 9 && opcode <= 11)
		{
			return 1;
		}else
			return 0;
	}

    void exitOp()
    {
        Instructions::halt = true;
    }

    void loadOp(int memoryLocation, int RAMLocation)
    {
        int temp = MemoryBuffer::read(storage, memoryLocation);

        MemoryBuffer::store(ram, RAMLocation, temp);
    }

    void saveOp(int RAMLocation, int memoryLocation)
    {
        int temp = MemoryBuffer::read(ram, RAMLocation);
        MemoryBuffer::store(storage, memoryLocation, temp);
    }

    void addOp(int resultLocation, int inputALocation, int inputBLocation)
    {
        int inputA = MemoryBuffer::read(ram, inputALocation);
        int inputB = MemoryBuffer::read(ram, inputBLocation);

        int result = inputA + inputB;

        MemoryBuffer::store(ram, resultLocation, result);
    }

    void minusOp(int resultLocation, int inputALocation, int inputBLocation)
    {
        int inputA = MemoryBuffer::read(ram, inputALocation);
        int inputB = MemoryBuffer::read(ram, inputBLocation);

        int result = inputA - inputB;

        MemoryBuffer::store(ram, resultLocation, result);
    }

    void greaterOp(int resultLocation, int inputALocation, int inputBLocation)
    {
        int inputA = MemoryBuffer::read(ram, inputALocation);
        int inputB = MemoryBuffer::read(ram, inputBLocation);

        (inputA > inputB)? MemoryBuffer::store(ram, resultLocation, 1): MemoryBuffer::store(ram, resultLocation, 0);
    }

    void lessOp(int resultLocation, int inputALocation, int inputBLocation)
    {
        int inputA = MemoryBuffer::read(ram, inputALocation);
        int inputB = MemoryBuffer::read(ram, inputBLocation);

        (inputA < inputB)? MemoryBuffer::store(ram, resultLocation, 1): MemoryBuffer::store(ram, resultLocation, 0);
    }

    void equalOp(int resultLocation, int inputALocation, int inputBLocation)
    {
        int inputA = MemoryBuffer::read(ram, inputALocation);
        int inputB = MemoryBuffer::read(ram, inputBLocation);

        (inputA == inputB)? MemoryBuffer::store(ram, resultLocation, 1): MemoryBuffer::store(ram, resultLocation, 0);
    }

    void ifOp(int booleanLocation, int trueInstructionNumber, int falseInstructionNumber, int& currentInstructionNumber)
    {
        if (MemoryBuffer::read(ram, booleanLocation) == 0)
        {
            currentInstructionNumber = falseInstructionNumber;
        }else
        {
            currentInstructionNumber = trueInstructionNumber;
        }

    }
    void inputOp(int RAMLocation)
    {
        int input = obtainInput();
        MemoryBuffer::store(ram, RAMLocation, input);
    }

    void outputOp(int RAMLocation)
    {
        int output = MemoryBuffer::read(ram, RAMLocation);
        printOut(output);
    }

    void gotoOp(int targetInstructionNumber, int& currentInstructionNumber)
    {
        currentInstructionNumber = targetInstructionNumber;
    }

    void persistOp()
    {
        writeToFile("memory.txt", storage->buffer, storage->bufferSize);
    }

    void reloadOp()
    {
        readFromFile("memory.txt", storage->buffer, storage->bufferSize);
    }

    void constOp(int constValue, int RAMLocation)
    {
        MemoryBuffer::store(ram, RAMLocation, constValue);
    }

    void moveOp(int sourceLocation, int destinationLocation)
    {
        int copyValue = MemoryBuffer::read(ram, sourceLocation);
        MemoryBuffer::store(ram, destinationLocation, copyValue);
    }

    void debugPrintout(const Instruction* instr)
    {
        if (instr == NULL)
        {
            std::cout << "NULL Instruction" << std::endl;
            return;
        }

        std::cout << "[" << instr->opcode << "]:";

        if (instr->operands == NULL)
        {
            std::cout << std::endl;
            return;
        }

        for (int i = 0; i < determineNumberOfOperands(instr->opcode); i++)
        {
            std::cout << " " << instr->operands[i];
        }

        std::cout << std::endl;
    }

    void executeInstruction(Instruction *instruction, int& currentInstructionNumber)
	{
        if (instruction == NULL || (instruction->operands == NULL && instruction->opcode == -1))
        {
            return;
        }

        switch (instruction->opcode)
        {
            case 0: exitOp();
                    break;
            case 1: loadOp(instruction->operands[0], instruction->operands[1]);
                    break;
            case 2: saveOp(instruction->operands[0], instruction->operands[1]);
                    break;
            case 3: addOp(instruction->operands[0], instruction->operands[1], instruction->operands[2]);
                    break;
            case 4: minusOp(instruction->operands[0], instruction->operands[1], instruction->operands[2]);
                    break;
            case 5: greaterOp(instruction->operands[0], instruction->operands[1], instruction->operands[2]);
                    break;
            case 6: lessOp(instruction->operands[0], instruction->operands[1], instruction->operands[2]);
                    break;
            case 7: equalOp(instruction->operands[0], instruction->operands[1], instruction->operands[2]);
                    break;
            case 8: ifOp(instruction->operands[0], instruction->operands[1], instruction->operands[2], currentInstructionNumber);
                    break;
            case 9: inputOp(instruction->operands[0]);
                    break;
            case 10: outputOp(instruction->operands[0]);
                    break;
            case 11: gotoOp(instruction->operands[0], currentInstructionNumber);
                    break;
            case 12: persistOp();
                    break;
            case 13: reloadOp();
                    break;
            case 14: constOp(instruction->operands[0], instruction->operands[1]);
                    break;
            case 15: moveOp(instruction->operands[0], instruction->operands[1]);
                    break;
            default: printError(4);
        }
	}
}
