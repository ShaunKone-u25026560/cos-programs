#include <iostream>
#include <string>
#include "TesterHelpers.h"

void passedPrinter(int expected, int received)
{
	std::cout << "Value " << received << " was same as expected value of " << expected << std::endl;
}

void failedPrinter(int expected, int received)
{
	std::cout << "Value " << received << " was not the same as expected value of " << expected << std::endl;
}

void passedPrinter(float expected, float received)
{
    std::cout << "Value " << received << " was same as expected value of " << expected << std::endl;
}

void failedPrinter(float expected, float received)
{
    std::cout << "Value " << received << " was not the same as expected value of " << expected << std::endl;
}

void passedPrinter(double expected, double received)
{
    std::cout << "Value " << received << " was same as expected value of " << expected << std::endl;
}

void failedPrinter(double expected, double received)
{
    std::cout << "Value " << received << " was not the same as expected value of " << expected << std::endl;
}

bool isSame(int expected, int received)
{
	if (expected == received)
	{
		passedPrinter(expected, received);
		return true;
	}else
	{
		failedPrinter(expected, received);
		return false;
	}
}

bool isDifferent(int expected, int received)
{
	if (expected == received)
	{
		passedPrinter(expected, received);
		return false;
	}else
	{
		failedPrinter(expected, received);
		return true;
	}
}

bool isSame(float expected, float received)
{
	if (expected == received)
	{
		passedPrinter(expected, received);
		return true;
	}else
	{
		failedPrinter(expected, received);
		return false;
	}
}

bool isDifferent(float expected, float received)
{
	if (expected == received)
	{
		passedPrinter(expected, received);
		return false;
	}else
	{
		failedPrinter(expected, received);
		return true;
	}
}

bool isSame(double expected, double received)
{
	if (expected == received)
	{
		passedPrinter(expected, received);
		return true;
	}else
	{
		failedPrinter(expected, received);
		return false;
	}
}

bool isDifferent(double expected, double received)
{
	if (expected == received)
	{
		passedPrinter(expected, received);
		return false;
	}else
	{
		failedPrinter(expected, received);
		return true;
	}
}

int compareTo(int expected, int received)
{
	if (expected == received)
		return 0;
	else if(expected > received)
		return 1;
	else
		return -1;
}

int compareTo(float expected, float received)
{
	if (expected == received)
		return 0;
	else if(expected > received)
		return 1;
	else
		return -1;
}

int compareTo(double expected, double received)
{
	if (expected == received)
		return 0;
	else if(expected > received)
		return 1;
	else
		return -1;
}



