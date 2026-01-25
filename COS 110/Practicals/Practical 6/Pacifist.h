#ifndef PACIFIST_H
#define PACIFIST_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Player.h"


class Pacifist : public Player
{
    public:
        Pacifist(const std::string& username, int health); // Function 1  
        virtual void interact(Player* otherPlayer); // Function 2
};

#endif /* PACIFIST_H */