#include <iostream>
#include <string>
#include "BubbleTeaShop.h"
#include "Menus.h"
int main()
{
	formOrder();

	// Teas

	std::cout << "\nTesting\n" << std::endl;

	std::cout << "Check Valid: " << processTeaOption(0) << std::endl;
	std::cout << "Check Valid: " << processTeaOption(1) << std::endl;
	std::cout << "Check Valid: " << processTeaOption(2) << std::endl;
	std::cout << "Check Valid: " << processTeaOption(3) << std::endl;
	std::cout << "Check Valid: " << processTeaOption(4) << std::endl;
	std::cout << "Check Valid: " << processTeaOption(5) << std::endl;
	std::cout << "Check InValid: " << processTeaOption(6) << std::endl;
	std::cout << "Check Valid: " << getTeaName(1) << std:: endl;
	std::cout << "Check Valid: " << getTeaName(2) << std:: endl;
	std::cout << "Check Valid: " << getTeaName(3) << std:: endl;
	std::cout << "Check Valid: " << getTeaName(4) << std:: endl;
	std::cout << "Check Valid: " << getTeaName(5) << std:: endl;
	std::cout << "Check InValid: " << getTeaName(9) << std:: endl;
	std::cout << "Check Valid: " << getTeaPrice("Black Tea") << std:: endl;
	std::cout << "Check Valid: " << getTeaPrice("Passion Fruit Tea") << std:: endl;
	std::cout << "Check Valid: " << getTeaPrice("Lemon Tea") << std:: endl;
	std::cout << "Check Valid: " << getTeaPrice("Mango Tea") << std:: endl;
	std::cout << "Check Valid: " << getTeaPrice("Honey Lemon Tea") << std:: endl;
	std::cout << "Check InValid: " << getTeaPrice("Chai tea") << std:: endl;

	std::cout << "Check Valid: " << processBubbleOption(0) << std::endl;
	std::cout << "Check Valid: " << processBubbleOption(1) << std::endl;
	std::cout << "Check Valid: " << processBubbleOption(2) << std::endl;
	std::cout << "Check Valid: " << processBubbleOption(3) << std::endl;
	std::cout << "Check Valid: " << processBubbleOption(4) << std::endl;
	std::cout << "Check Valid: " << processBubbleOption(5) << std::endl;
        std::cout << "Check InValid: " << processBubbleOption(6) << std::endl;
        std::cout << "Check Valid: " << getBubbleName(1) << std:: endl;
	std::cout << "Check Valid: " << getBubbleName(2) << std:: endl;
	std::cout << "Check Valid: " << getBubbleName(3) << std:: endl;
	std::cout << "Check Valid: " << getBubbleName(4) << std:: endl;
	std::cout << "Check Valid: " << getBubbleName(5) << std:: endl;
        std::cout << "Check InValid: " << getBubbleName(9) << std:: endl;
        std::cout << "Check Valid: " << getBubblePrice("Litchi Bubble") << std:: endl;
	std::cout << "Check Valid: " << getBubblePrice("Strawberry Bubble") << std:: endl;
	std::cout << "Check Valid: " << getBubblePrice("Pomegranate Bubble") << std:: endl;
	std::cout << "Check Valid: " << getBubblePrice("Blueberry Bubble") << std:: endl;
	std::cout << "Check Valid: " << getBubblePrice("Passion Fruit Bubble") << std:: endl;
        std::cout << "Check InValid: " << getBubblePrice("Chai tea") << std:: endl;

	std::cout << "Check Valid: " << processExtrasOption(0) << std::endl;
	std::cout << "Check Valid: " << processExtrasOption(1) << std::endl;
	std::cout << "Check Valid: " << processExtrasOption(2) << std::endl;
	std::cout << "Check Valid: " << processExtrasOption(3) << std::endl;
	std::cout << "Check Valid: " << processExtrasOption(4) << std::endl;
	std::cout << "Check Valid: " << processExtrasOption(5) << std::endl;
        std::cout << "Check InValid: " << processExtrasOption(6) << std::endl;
        std::cout << "Check Valid: " << getExtrasName(1) << std:: endl;
	std::cout << "Check Valid: " << getExtrasName(2) << std:: endl;
	std::cout << "Check Valid: " << getExtrasName(3) << std:: endl;
	std::cout << "Check Valid: " << getExtrasName(4) << std:: endl;
	std::cout << "Check Valid: " << getExtrasName(5) << std:: endl;
        std::cout << "Check InValid: " << getExtrasName(9) << std:: endl;
        std::cout << "Check Valid: " << getExtrasPrice("Mango Slush") << std:: endl;
	std::cout << "Check Valid: " << getExtrasPrice("Coffee Slush") << std:: endl;
	std::cout << "Check Valid: " << getExtrasPrice("Extra Ice") << std:: endl;
	std::cout << "Check Valid: " << getExtrasPrice("Fresh Taro") << std:: endl;
	std::cout << "Check Valid: " << getExtrasPrice("Almond Pearls") << std:: endl;
        std::cout << "Check InValid: " << getExtrasPrice("Chai tea") << std:: endl;
	return 0;
}
