#ifndef VILLIAIN_H
#define VILLIAIN_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Threat.h"

class Villain : public Player, public Threat
{
    private:
        int numRocks; // Member 1
    public:
        Villain(const std::string& username, int health, int numRocks); // Function 1
        virtual std::string toString() const; // Function 2
        virtual void interact(Player* otherPlayer);// Function 3
        virtual int getDamage(); // Function 4
        virtual bool harmPlayer(Player* player); // Function 5
};

#endif /* VILLAIN_H */