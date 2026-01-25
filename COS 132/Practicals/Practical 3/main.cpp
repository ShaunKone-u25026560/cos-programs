#include <iostream>
#include <sstream>

#include "UDP.h"
#include "NetworkInterface.h"
#include "ProvidedFunctions.h"
#include "InputOutput.h"

using namespace std;

void studentExample()
{
    string udpPacket = formUDPFromUserInput();
    cout << endl;
    prettyPrint(udpPacket);
    cout << endl;
    packetPrint(udpPacket);
    cout << endl;
}

int main()
{
    studentExample();
    return 0;
}