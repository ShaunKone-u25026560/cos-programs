#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

namespace Screen
{
    extern int nx;
    extern int ny;
    extern char** screenBuffer;

    void setUpScreen(int x, int y);
    void cleanScreen();
    void draw(int x, int y, char symbol = 'x');
    void printScreen();
    void cleanUpMemory();
}


#endif /*SCREEN_H*/