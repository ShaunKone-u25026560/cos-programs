#include <iostream>
#include "Memory.h"
#include "IO.h"
#include "Memory.h"
#include "OS.h"
#include "Instructions.h"

MemoryBuffer::MemoryBufferObject* ram;
MemoryBuffer::MemoryBufferObject* storage;

namespace MemoryBuffer
{
	struct MemoryBufferObject;

	void printOutContents(MemoryBufferObject* memoryBufferObject)
	{
		if (memoryBufferObject == NULL || memoryBufferObject->buffer == NULL)
		{
			printError(0);
			return;
		}
		for (int i = 0; i < memoryBufferObject->bufferSize; i++)
		{
			std::cout << "[" << i << "]" << ": " << memoryBufferObject->buffer[i] << std::endl;
		}
	}

	int* dereference(MemoryBufferObject* memoryBufferObject, int memoryAddress)
	{
		if (memoryBufferObject == NULL || memoryBufferObject->buffer == NULL)
		{
			printError(0);
			return NULL;
		}

		if (memoryAddress < 0 || memoryAddress >= memoryBufferObject->bufferSize)
		{
			printError(2);
			return NULL;
		}

		return &(memoryBufferObject->buffer[memoryAddress]);
	}

	void store(MemoryBufferObject* memoryBufferObject, int memoryAddress, int value)
	{
		if (memoryBufferObject == NULL || memoryBufferObject->buffer == NULL)
		{
			printError(0);
			return;
		}

		if (memoryAddress < 0 || memoryAddress >= memoryBufferObject->bufferSize)
		{
			printError(2);
			return;
		}

		memoryBufferObject->buffer[memoryAddress] = value;
	}

	int read(MemoryBufferObject* memoryBufferObject, int memoryAddress)
	{
		if (memoryBufferObject == NULL || memoryBufferObject->buffer == NULL)
        {
                printError(0);
                return 0;
        }

        if (memoryAddress < 0 ||  memoryAddress >= memoryBufferObject->bufferSize)
        {
                printError(2);
                return 0;
        }

		return memoryBufferObject->buffer[memoryAddress];
	}

	void createBuffer(MemoryBuffer::MemoryBufferObject*& memoryBufferObject, int bufferSize)
	{
		if (bufferSize < 1)
		{
			printError(3);
			return;
		}

		if (memoryBufferObject != NULL)
		{
			delete[] memoryBufferObject->buffer;
			delete memoryBufferObject;
			memoryBufferObject = NULL;
		}

		// Create and populate object
		memoryBufferObject = new MemoryBuffer::MemoryBufferObject();
		memoryBufferObject->buffer = new int[bufferSize]();
		memoryBufferObject->bufferSize = bufferSize;
	}

	void destroyBuffer(MemoryBuffer::MemoryBufferObject*& memoryBufferObject)
	{
		if (memoryBufferObject == NULL)
			return;

		// Deallocating heap memory
		delete[] memoryBufferObject->buffer;
		// Deallocating rest of memory
		delete memoryBufferObject;
		memoryBufferObject = NULL;
	}

}
