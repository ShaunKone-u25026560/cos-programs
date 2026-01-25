#include <iostream>
#include <string>
#include "Arena.h"
#include "Pacifist.h"
#include "Villain.h"
#include "Player.h"
#include "Tile.h"
#include "testingFramework.h"

int main(){

    testAll();

    // Create Arena
    std::string fileName = "arena.txt";
    Arena thunderDome(fileName);

    // Create Players
    int size = 4;
    Player** players = new Player*[size];
    players[0] = new Pacifist("Aaron", 100);
    players[1] = new Villain("Brett", 100, 3);
    players[2] = new Pacifist("Jester", 80);
    players[3] = new Villain("Michael", 50, 5); // For testing purposes

    // Add players to Arena
    /*bool allPlayersEntered = false;
    int turn = 0; // Resets after it hits 3
    std::string direction = "left";

    while (getNumPlayers > 0 || !allPlayersEntered)
    {
        if (!allPlayersEntered) // Enters all players into ThunderDome
        {
            thunderDome.addPlayer(players[turn]);

            if (thunderDome.getNumPlayers() == size)
                allPlayersEntered = true;
        }

        // Player moves
        std::cin >> direction;
        thunderDome.movePlayer(players[turn])

        if (turn == 3)
            turn = 0;
        else
            ++turn;
    } */

    // FOr submission
    thunderDome.print();
    std::cout << std::endl;
    thunderDome.addPlayer(players[0]);
    thunderDome.movePlayer(players[0], "left");

    thunderDome.addPlayer(players[1]);
    thunderDome.movePlayer(players[0], "left");

    thunderDome.movePlayer(players[1], "left");
    thunderDome.addPlayer(players[2]);
    thunderDome.movePlayer(players[0], "left");
    thunderDome.movePlayer(players[1], "left");
    // Player 1 interact
    players[1]->interact(players[0]);
    thunderDome.movePlayer(players[2], "left");
    thunderDome.movePlayer(players[0], "up");
    thunderDome.movePlayer(players[1], "left");
    thunderDome.movePlayer(players[2], "up");
    // Player 2 interact
    players[2]->interact(players[1]);
    thunderDome.movePlayer(players[0], "up");
    thunderDome.movePlayer(players[1], "left");
    thunderDome.movePlayer(players[2], "up");
    thunderDome.movePlayer(players[0], "up");
    thunderDome.movePlayer(players[1], "up"); // Player 1 at Lethal Tile, Should die
    thunderDome.movePlayer(players[2], "up");
    thunderDome.movePlayer(players[0], "up"); // Player 0 at the end, Should exit arena
    thunderDome.movePlayer(players[2], "up");
    thunderDome.movePlayer(players[2], "right");
    thunderDome.movePlayer(players[2], "left");
    // Villain try to kill player 2
    players[3]->interact(players[2]);
    thunderDome.movePlayer(players[2], "left");
    // Villain try to kill player 2
    players[3]->interact(players[2]);
    thunderDome.movePlayer(players[2], "left"); // Player 2 at the end, Should exit arena

    // Delete Player 3 and the array cause Arena destructor will handle those that entered the arena
    delete players[3];
    delete[] players;
    return 0;
};
