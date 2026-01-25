#ifndef THREAT_H
#define THREAT_H
#include <iostream>
// PLEASE DO NOT ALTER THE NEXT LINE
class Player;

class Threat {
    protected:
        int damage; // Member 1
    public:
        Threat(int damage); // Function 1
        virtual ~Threat(); // Function 2
        virtual int getDamage() =0; // Function 3
        virtual bool harmPlayer(Player* player) =0; // Function 4
};


#endif //THREAT_H