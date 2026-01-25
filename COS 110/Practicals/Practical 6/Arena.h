#ifndef ARENA_H
#define ARENA_H
#include <string>

using namespace std;
// PLEASE DO NOT ALTER THE NEXT 2 LINES
class Tile;
class Player;

class Arena {
    private:
        int size; // Member 1
        int numPlayers; // Member 2
        int startX; // Member 3
        int startY; // Member 4
        int endX; // Member 5
        int endY; // Member 6
        Tile*** tiles; // Member 7
        Player** players; // Member 8
    public:
        Arena(const std::string& arenaFileName); // Function 1
        ~Arena(); // Function 2
        int getSize() const; // Function 3
        int getNumPlayers() const; // Function 4
        bool isValidPosition(int x, int y) const; // Function 5
        void addPlayer(Player* newPlayer); // Function 6
        void movePlayer(Player* player, const std::string& direction); // Function 7
        void print() const; // Function 8
};


#endif //ARENA_H