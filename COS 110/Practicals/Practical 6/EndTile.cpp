#include "EndTile.h"

EndTile::EndTile(int x, int y) // Function 1
        : Tile(x, y, false, true, 'e')
{}

EndTile::~EndTile() // Function 2
{}

void EndTile::addPlayer(Player* player) // Function 3
{
    Tile::addPlayer(player);

    player->setPosition(-1, -1);

    std::cout << player->getUsername() << " has escaped" << std::endl;
    this->player = NULL;
}

char EndTile::toChar() const // Function 4
{
    return getSymbol();
}
