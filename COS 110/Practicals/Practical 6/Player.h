#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;
// PLEASE DO NOT ALTER THE NEXT LINE
class Threat;

class Player {
    private:
        std::string username; // Member 1
        int health; // Member 2
        int x; // Member 3
        int y; // Member 4
    public:
        static int numAlivePlayers; // Member 5
        Player(const std::string& username, int health); // Function 1
        virtual ~Player(); // Function 2
        std::string getUsername() const; // Function 3
        int getHealth() const; // Function 4
        int getX() const; // Function 5
        int getY() const; // Function 6
        void setPosition(int x, int y); // Function 7
        virtual std::string toString() const; // Function 8
        virtual void interact(Player* otherPlayer) =0; // Function 9
        virtual bool takeDamage(Threat* threat); // Function 10
};


#endif //PLAYER_H