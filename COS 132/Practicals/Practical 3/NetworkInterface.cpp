#include <iostream>
#include <string>
#include "NetworkInterface.h"
#include "UDP.h"

std::string dataSourceRequest = "Please enter the source port: ";
std::string dataDestRequest = "Please enter the destination port: ";
std::string dataDataRequest = "Please enter the message: ";

std::string askUserForSourcePort()
{
	int sourcePort;
	std::cout << dataSourceRequest << std::endl;
	std::cin >> sourcePort;
	return intToBin(sourcePort, 16);
}

std::string askUserForDestinationPort()
{
	int destinationPort;
	std::cout << dataDestRequest << std::endl;
	std::cin >> destinationPort;
	return intToBin(destinationPort, 16);
}

std::string askUserForData()
{
	std::string data;
	std::cout << dataDataRequest << std::endl;
	std::cin >> data;
	return stringToBin(data, 5);
}

std::string formUDPFromUserInput()
{
	std::string sP  = askUserForSourcePort();
	std::string dP  = askUserForDestinationPort();
	std::string d = askUserForData();
	std::string length = intToBin(d.length(), 16);
	std::string checkSum = "1111111100000000";

	return sP + dP + length + checkSum + d;
}

void prettyPrint(std::string UDPPacket)
{
	std::cout << "Source Port: " << extractSourcePortBin(UDPPacket) << std::endl;
	std::cout << "Destination Port: " << extractDestinationPortBin(UDPPacket) << std::endl;
	std::cout << "Length: " << extractLengthBin(UDPPacket) << std::endl;
	std::cout << "Checksum: " << extractCheckSumBin(UDPPacket) << std::endl;
	std::cout << "Message: " << extractDataBin(UDPPacket) << std::endl;
}

void packetPrint(std::string UDPPacket)
{
	std::cout << "Source Port: " << hexBinToInt(UDPPacket.substr(0, 16)) << std::endl;
	std::cout << "Destination Port: " << hexBinToInt(UDPPacket.substr(16, 16)) << std::endl;
	std::cout << "Length: " << hexBinToInt(UDPPacket.substr(32, 16)) << std::endl;
	std::cout << "Checksum: " << hexBinToInt(UDPPacket.substr(48, 16)) << std::endl;
	std::cout << "Message: " << binToString(UDPPacket.erase(0, 64), 5) << std::endl;
}
