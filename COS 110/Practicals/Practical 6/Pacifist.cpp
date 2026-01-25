#include "Pacifist.h"

Pacifist::Pacifist(const std::string& username, int health) // Function 1
        : Player(username, health)
{}

void Pacifist::interact(Player* otherPlayer) // Function 2
{
    if (this != otherPlayer && otherPlayer != NULL)
    {
        std::cout << this->getUsername() << " waved at " << otherPlayer->getUsername() << std::endl;
    }

}
