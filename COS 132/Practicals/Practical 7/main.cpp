#include <iostream>
#include "Lines.h"
#include "Shapes.h"
#include "Screen.h"

int main()
{
	Screen::setUpScreen(10, 6);
	Screen::printScreen();
	Screen::cleanUpMemory();

	Screen::setUpScreen(10, 6);
	drawLine(0, 0, 10, 10, '@');
	Screen::printScreen();
	Screen::cleanUpMemory();

	Screen::setUpScreen(10, 6);
	drawLine(0, 0, 10, 10, '@');
	drawLine(9, 0, 0, 6, '^');
	Screen::printScreen();
	Screen::cleanUpMemory();

	Screen::setUpScreen(10, 6);
	drawTriangle(3, 3, 0, 0, 8, 0);
	Screen::printScreen();
	Screen::cleanUpMemory();

	Screen::setUpScreen(20, 20);
	drawSquare(0, 19, 15, 15, 14, 5, 3, 3, '$');
	Screen::printScreen();
	Screen::cleanUpMemory();

	Screen::setUpScreen(8, 8);
	drawTriangle(1, 1, 3, 3, 5, 1);
	Screen::printScreen();
	Screen::cleanScreen();

        drawSquare(1, 5, 5, 5, 5, 1, 1, 1);
        Screen::printScreen();
        Screen::cleanScreen();

	drawTriangle(1, 1, 3, 5, 6, 1);
	Screen::printScreen();
	Screen::cleanScreen();

	Screen::cleanUpMemory();
	return 0;
}
