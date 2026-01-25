#include "Tile.h"
#include "TileException.h"

Tile::Tile(int x, int y, bool isStart, bool isEnd, char symbol) // Function 1
{
    this->symbol = symbol;

    if (isStart)
        this->symbol = 's';

    this->x = x;
    this->y = y;
    this->isStart = isStart;
    this->isEnd = isEnd;

    this->player = NULL;
}

 Tile::~Tile() // Function 2
{
    /*if (player)
    {
        delete player;
        player = NULL;
    }*/

}

char Tile::getSymbol() const // Function 3
{
    return symbol;
}

int Tile::getX() const // Function 4
{
    return x;
}

int Tile::getY() const // Function 5
{
    return y;
}

bool Tile::getIsStart() const // Function 6
{
    return isStart;
}

bool Tile::getIsEnd() const // Function 7
{
    return isEnd;
}

Player* Tile::getPlayer() const // Function 8
{
    return player;
}

void Tile::addPlayer(Player* player) // Function 9
{
    if (player)
    {
        if (this->player)
        {
            std::string message = "Tile occupied";
            throw TileException(message);
        }

        this->player = player;
        this->player->setPosition(x, y);
    }else
    {
        std::string message = "Player is NULL";
        throw TileException(message);
    }

}

void Tile::removePlayer() // Function 10
{
    player = NULL;
}

char Tile::toChar() const // Function 11
{
    if (!player)
        return symbol;
    else
        return (player->getUsername())[0];
}
