#ifndef LETHALTILE_H
#define LETHALTILE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Tile.h"
#include "Threat.h"

class LethalTile : public Tile, public Threat
{
    public:
        LethalTile(int x, int y); // Function 1
        virtual void addPlayer(Player* player); // Function 2
        virtual int getDamage(); // Function 3
        virtual bool harmPlayer(Player* player); // Function 4
};

#endif /* LETHALTILE_H */