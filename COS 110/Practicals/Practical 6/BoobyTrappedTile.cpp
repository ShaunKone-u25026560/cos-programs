#include "BoobyTrappedTile.h"
#include "TileException.h"

BoobyTrappedTile::BoobyTrappedTile(int x, int y, int damage) // Function 1
                : Tile(x, y, false, false, 'x'), Threat(damage)
{
    this->damageReduction = 0;
}

void BoobyTrappedTile::addPlayer(Player* player) // Function 2
{
    try
    {
        Tile::addPlayer(player);

        if (harmPlayer(player)) // If the player was killed
            removePlayer();
    }catch (TileException)
    {
        std::cout << "Failed to harm player" << std::endl;
    }
}

int BoobyTrappedTile::BoobyTrappedTile::getDamage() // Function 3
{
    int result = damage - damageReduction;
    damageReduction += 10;
    return result;
}

bool BoobyTrappedTile::harmPlayer(Player* player) // Function 4
{
    return player->takeDamage(this);
}
