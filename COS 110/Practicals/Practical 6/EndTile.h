#ifndef ENDTILE_H
#define ENDTILE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Tile.h"

class EndTile : public Tile
{
    public:
        EndTile(int x, int y); // Function 1
        virtual ~EndTile(); // Function 2
        virtual void addPlayer(Player* player); // Function 3
        virtual char toChar() const; // Function 4
};

#endif /* ENDTILE_H */