#ifndef BOOBYTRAPPEDTILE_H
#define BOOBYTRAPPEDTILE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Tile.h"
#include "Threat.h"

class BoobyTrappedTile : public Tile, public Threat
{
    private:
        int damageReduction; // Member 1
    public:
        BoobyTrappedTile(int x, int y, int damage); // Function 1
        virtual void addPlayer(Player* player); // Function 2
        virtual int getDamage(); // Function 3
        virtual bool harmPlayer(Player* player); // Function 4
};

#endif /* BOOBYTRAPPEDTILE_H */