#include "TesterHelpers.h"
#include "ValueTesters.h"

int main()
{
	double dA = 3.141592653589;
	double dB = 3.141352353253;
	float fA = 2.5;
	float fB = 3.5;

	passedPrinter(1, 3);
	passedPrinter(fA, fB);
	passedPrinter(dA, dB);

	failedPrinter(1, 1);
	failedPrinter(fA, fB);
	failedPrinter(dA, dB);

	isSame(3, 5);
	isSame(1, 1);
	isDifferent(4, 2);
	isDifferent(3, 3);
	isSame(fA, fB);
	isSame(fA, fA);
	isDifferent(fB, fA);
	isDifferent(fB, fB);
	isSame(dA, dB);
	isSame(dA, dA);
	isDifferent(dB, dA);
	isDifferent(dB, dB);

	compareTo(2, 2);
	compareTo(2, 3);
	compareTo(3, 2);
	compareTo(fA, fA);
	compareTo(fB, fA);
	compareTo(fA, fB);
	compareTo(dA, dB);
	compareTo(dA, dA);
	compareTo(dB, dA);

	return 0;
}
