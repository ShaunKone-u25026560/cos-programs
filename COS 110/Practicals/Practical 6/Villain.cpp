#include "Villain.h"

Villain::Villain(const std::string& username, int health, int numRocks) // Function 1
        : Player(username, health), Threat(10)
{
    this->numRocks = numRocks;
}

std::string Villain::toString() const // Function 2
{
    std::stringstream ss;
    ss << Player::toString() << "\nRocks: " << numRocks << "\nDamage: " << damage;

    return ss.str();
}

void Villain::interact(Player* otherPlayer)// Function 3
{
    if (otherPlayer != NULL && otherPlayer != this)
        harmPlayer(otherPlayer);
}

int Villain::getDamage() // Function 4
{
    return damage;
}

bool Villain::harmPlayer(Player* player) // Function 5
{
    if (player->getHealth() > 10)
    {
        if (numRocks > 0)
        {
            player->takeDamage(this);
            --numRocks;
            return true;
        }
    }

    return false;
}
