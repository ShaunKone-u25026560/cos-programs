#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Player.h"

class Tile
{
    private:
        int x; // Member 1 (Row)
        int y; // Member 2 (Column)
        bool isStart; // Member 3
        bool isEnd; // Member 4
        char symbol; // Member 5
    protected:
        Player* player; // Member 6
    public:
        Tile(int x, int y, bool isStart = false, bool isEnd = false, char symbol = '+'); // Function 1
        virtual ~Tile(); // Function 2
        char getSymbol() const; // Function 3
        int getX() const; // Function 4
        int getY() const; // Function 5
        bool getIsStart() const; // Function 6
        bool getIsEnd() const; // Function 7
        Player* getPlayer() const; // Function 8
        virtual void addPlayer(Player* player); // Function 9
        void removePlayer(); // Function 10
        virtual char toChar() const; // Function 11
};

#endif /* TILE_H */