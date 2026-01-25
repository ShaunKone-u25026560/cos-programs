#include "LethalTile.h"

LethalTile::LethalTile(int x, int y) // Function 1
            : Tile(x, y, false, false, '#'), Threat(200)
{}

void LethalTile::addPlayer(Player* player) // Function 2
{
    Tile::addPlayer(player);

    if (harmPlayer(player))
        removePlayer();
}

int LethalTile::getDamage() // Function 3
{
    return damage;
}

bool LethalTile::harmPlayer(Player* player) // Function 4
{
    return player->takeDamage(this);
}
