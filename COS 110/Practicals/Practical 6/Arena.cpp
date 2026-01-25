#include "Arena.h"
#include "Tile.h"
#include "EndTile.h"
#include "BoobyTrappedTile.h"
#include "LethalTile.h"
#include "TileException.h"
#include <iostream>
#include <sstream>
#include <fstream>

Arena::Arena(const std::string& arenaFileName) // Function 1
{
    // Open textfile
    std::ifstream file(arenaFileName.c_str());
    std::stringstream read;
    std::string line = "";


    // Enter size
    std::getline(file, line);
    read.str(line);
    read >> this->size;
    read.str("");
    read.clear();

    // Set tiles
    tiles = new Tile**[this->size]; // Create rows

    for (int i = 0; i < 5; i++)
    {
        // create columns
        tiles[i] = new Tile*[size];
        std::getline(file, line);
        read.str(line);

        for (int j = 0; j < 5; j++)
        {
            char symbol = line[j];

            switch (symbol)
            {
                case '+' :  tiles[i][j] = new Tile(i, j);
                    break;
                case 's' :  tiles[i][j] = new Tile(i, j, true, false, symbol);
                            startX = i;
                            startY = j;
                    break;
                case 'e' :  tiles[i][j] = new EndTile(i, j);
                            endX = i;
                            endY = j;
                    break;
                case 'x' :  tiles[i][j] = new BoobyTrappedTile(i, j, 20);
                    break;
                case '#' :  tiles[i][j] = new LethalTile(i, j);
                    break;
            }
        }

        read.str("");
        read.clear();
    }

    // Set players
    numPlayers = 0;
    players = new Player*[0];

    // Close textfile
    file.close();
}

Arena::~Arena() // Function 2
{
    // Manage tiles
    if (tiles)
    {
        for (int i = 0; i < size; i++)
        {
            if (tiles[i])
            {
                for (int j = 0; j < size; j++)
                {
                    if (tiles[i][j])
                        delete tiles[i][j];
                }

                delete[] tiles[i];
            }
        }

        delete[] tiles;
    }

    // Manage players
    if (players)
    {
        for (int i = 0; i < numPlayers; i++)
        {
            if (players[i])
                delete players[i];
        }

        delete[] players;
    }
}

int Arena::getSize() const // Function 3
{
    return size;
}

int Arena::getNumPlayers() const // Function 4
{
    // Count number of players currently on tiles/in the arena
    int playersInArena = 0;

    if (tiles)
    {
        for (int i = 0; i < size; i++)
        {
            if (tiles[i])
            {
                for (int j = 0; j < size; j++)
                {
                    if (tiles[i][j])
                    {
                        if ( (tiles[i][j])->getPlayer() ) // If its not NULL (Player is on tile)
                            ++playersInArena;
                    }
                }
            }
        }
    }

    return playersInArena;
}

bool Arena::isValidPosition(int x, int y) const // Function 5
{
    if (x < size && x >= 0 && y < size && y >= 0) /////////// May have to check that these are also greater than -1
        return true;

    return false;
}

void Arena::addPlayer(Player* newPlayer) // Function 6
{
    if (newPlayer)
    {
        // Check to see if newPlayer is already in the arena
        bool isPresent = false;
        if (players)
        {
            for (int i = 0; i < numPlayers; i++)
            {
                if (players[i] == newPlayer)
                    isPresent = true;
            }
        }

        if (!isPresent)
        {
            // Add a player to the starting tile
            try // try to add player
            {
                (tiles[startX][startY])->addPlayer(newPlayer);

                // Copy over old players array values
                Player** tempPlayers = new Player*[this->numPlayers + 1];
                if (players)
                {
                    for (int i = 0; i < this->numPlayers; i++)
                    {
                        tempPlayers[i] = players[i];
                    }

                    delete[] players;
                }

                tempPlayers[this->numPlayers] = newPlayer;
                players = tempPlayers;
                this->numPlayers++;
            }catch (TileException tileExcept)
            {
                std::cout << tileExcept.getMessage() << std::endl;
            }
        }
    }
}

void Arena::movePlayer(Player* player, const std::string& direction) // Function 7
{
    if (player != NULL && player->getX() != -1 && player->getY() != -1)
    {
        int newPosX = player->getX(), newPosY = player->getY();

        if (direction == "up")
        {
            --newPosX;
        }else if (direction == "down")
        {
            ++newPosX;
        }else if (direction == "left")
        {
            --newPosY;
        }else if (direction == "right")
        {
            ++newPosY;
        }else
        {
            return;
        }

        if (isValidPosition(newPosX, newPosY))
        {
            (tiles[player->getX()][player->getY()])->removePlayer(); // Removes player from current tile
            try
            {
                (tiles[newPosX][newPosY])->addPlayer(player);
            }catch (TileException tileExcept)
            {
                std::cout << tileExcept.getMessage() << std::endl;
            }

        }else
            std::cout << "Invalid Position" << std::endl;
    }
}

void Arena::print() const // Function 8
{
    std::cout << getNumPlayers() << " players entered the Arena" << std::endl;
    std::cout << Player::numAlivePlayers << " alive players" << std::endl << std::endl;

    std::cout << "-Player info-" << std::endl;

    // Find out who is in the arena and output their info
    if (players)
    {
        for (int i = 0; i < numPlayers; i++)
        {
            if (players[i])
            {
                //////////////// REMOVE COMMENTS IF YOU ONLY WANT TO DISPLAY THE PLAYERS IN THE ARENA
                //int xValue = players[i]->getX();
                //int yValue = players[i]->getY();

               // if (xValue > -1 && yValue > -1 && isValidPosition(xValue, yValue))
               // {
                    std::cout << players[i]->toString() << std::endl; // Displays all Plalyers with comments applied
                    std::cout << std::endl;
               // }
            }
        }
    }

    // Output Tiles
    if (tiles)
    {
        for (int i = 0; i < size; i++)
        {
            if (tiles[i])
            {
                for (int j = 0; j < size; j++)
                {
                    if (tiles[i][j])
                    {
                        std::cout << (tiles[i][j])->toChar();
                    }
                }
            }
            if (i != size - 1) ///////////////////// May have to remove in order to not skip line
                std::cout << std::endl;
        }
    }
}
