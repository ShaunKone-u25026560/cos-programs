#include "Player.h"
#include "Threat.h"
#include <sstream>

int Player::numAlivePlayers = 0;

Player::Player(const std::string& username, int health) // Function 1
{
    this->username = username;

    if (health < 0)
        this->health = 50;
    else if (health > 100)
        this->health = 100;
    else
        this->health = health;

    this->x = -1;
    this->y = -1;

    ++numAlivePlayers;
}

Player::~Player() // Function 2
{}

std::string Player::getUsername() const // Function 3
{
    return this->username;
}

int Player::getHealth() const // Function 4
{
   return this->health;
}

int Player::getX() const // Function 5
{
    return this->x;
}

int Player::getY() const // Function 6
{
    return this->y;
}

void Player::setPosition(int x, int y) // Function 7
{
    this->x = x;
    this->y = y;
}

std::string Player::toString() const // Function 8
{
    std::stringstream result;
    // Dont add a newline at the end
    result << "Username: " << username << "\n" << "Health: " << health << "\n" << "Position: (" << x << "," << y << ")";

    return result.str();
}

bool Player::takeDamage(Threat* threat) // Function 10
{
    int damage = threat->getDamage();

    if (damage >= this->health)
        this->health = 0;
    else
        this->health -= damage;

    if (this->health <= 0)
    {
        --numAlivePlayers;
        std::cout << this->username << " has perished" << std::endl;
        return true;
    }

    std::cout << this->username << " took " << damage << " damage and now has " << this->health << " health" << std::endl;
    return false;
}
