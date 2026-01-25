#include <iostream>
#include <string>
#include "BubbleTeaShop.h"
#include "PriceList.h"
#include "Menus.h"

namespace Order
{
	float teaSubtotal;
	float bubbleSubtotal;
	float extraSubtotal;
	std::string teas;
	std::string bubbles;
	std::string extras;
}

void resetOrder()
{
	Order::teas = "";
	Order::bubbles = "";
	Order::extras = "";

	Order::teaSubtotal = 0;
	Order::bubbleSubtotal = 0;
	Order::extraSubtotal = 0;
}

void processBill()
{
	std::cout << "Your bill is:\n";
	std::cout << "\nTeas:\n";
	std::cout << Order::teas << std::endl;
	std::cout << "Tea total: " << currencySymbol << Order::teaSubtotal << std::endl;

	std::cout << "\nBubbles:\n";
	std::cout << Order::bubbles << std::endl;
	std::cout << "Bubble total: " << currencySymbol << Order::bubbleSubtotal << std::endl;

	std::cout << "\nExtras:\n";
	std::cout << Order::extras << std::endl;
	std::cout << "Extra total: " << currencySymbol << Order::extraSubtotal << std::endl;

	float subTotal = Order::teaSubtotal + Order::bubbleSubtotal + Order::extraSubtotal;
	float vatValue = subTotal * vat;

	std::cout << "\nSubtotal: " << currencySymbol << subTotal << std::endl;
	std::cout << "Vat value: " << currencySymbol << vatValue << std::endl;
	std::cout << "Total: " << currencySymbol << subTotal + vatValue << std::endl;
}

std::string getTeaName(int teaNum)
{
	switch(teaNum)
	{
		case 1 : return Teas::blackTeaStr;
		case 2 : return Teas::passionFruitTeaStr;
		case 3 : return Teas::lemonTeaStr;
		case 4 : return Teas::mangoTeaStr;
		case 5 : return Teas::honeyLemonTeaStr;
		default: return "Unknown Tea";
	}
}

float  getTeaPrice(std::string teaName)
{
	if (teaName == Teas::blackTeaStr)
	{
		return Teas::blackTeaPrice;
	}
	else if (teaName == Teas::passionFruitTeaStr)
	{
		return Teas::passionFruitTeaPrice;
	}
	else if (teaName == Teas::lemonTeaStr)
	{
		return Teas::lemonTeaPrice;
	}
	else if (teaName == Teas::mangoTeaStr)
	{
		return Teas::mangoTeaPrice;
	}
	else if (teaName == Teas::honeyLemonTeaStr)
	{
		return Teas::honeyLemonTeaPrice;
	}
	else
	{
		return 0;
	}
}

bool processTeaOption(int menuNumber)
{

    if (menuNumber == 0)
	{
   } else
	{
		switch (menuNumber)
		{
			case 1 : Order::teas += Teas::blackTeaStr + "\n";
				 Order::teaSubtotal += Teas::blackTeaPrice;
				 break;
			case 2 : Order::teas += Teas::passionFruitTeaStr + "\n";
				 Order::teaSubtotal += Teas::passionFruitTeaPrice;
				 break;
            case 3 : Order::teas += Teas::lemonTeaStr + "\n";
				 Order::teaSubtotal += Teas::lemonTeaPrice;
				 break;
			case 4 : Order::teas += Teas::mangoTeaStr + "\n";
				 Order::teaSubtotal += Teas::mangoTeaPrice;
				 break;
            case 5 : Order::teas += Teas::honeyLemonTeaStr + "\n";
				 Order::teaSubtotal += Teas::honeyLemonTeaPrice;
				 break;
            default:
                 displayInvalidOption(menuNumber);
                 return false;
		}
	}

	return true;
}

std::string getBubbleName(int bubbleNum)
{
	switch(bubbleNum)
	{
		case 1 : return Bubbles::litchiPopStr;
		case 2 : return Bubbles::strawberryPopStr;
		case 3 : return Bubbles::pomegranatePopStr;
		case 4 : return Bubbles::blueberryPopStr;
		case 5 : return Bubbles::passionFruitPopStr;
		default: return "Unknown Bubble";
	}
}

float  getBubblePrice(std::string bubbleName)
{
	if (bubbleName == Bubbles::litchiPopStr)
	{
		return Bubbles::litchiPopPrice;
	}
	else if (bubbleName == Bubbles::strawberryPopStr)
	{
		return Bubbles::strawberryPopPrice;
	}
	else if (bubbleName == Bubbles::pomegranatePopStr)
	{
		return Bubbles::pomegranatePopPrice;
	}
	else if (bubbleName == Bubbles::blueberryPopStr)
	{
		return Bubbles::blueberryPopPrice;
	}
	else if (bubbleName == Bubbles::passionFruitPopStr)
	{
		return Bubbles::passionFruitPopPrice;
	}
	else
	{
		return 0;
	}
}

bool processBubbleOption(int menuNumber)
{

    if (menuNumber == 0)
	{
    }else
	{
		switch (menuNumber)
		{
			case 1 : Order::bubbles += Bubbles::litchiPopStr + "\n";
				 Order::bubbleSubtotal += Bubbles::litchiPopPrice;
				 break;
			case 2 : Order::bubbles += Bubbles::strawberryPopStr + "\n";
				 Order::bubbleSubtotal += Bubbles::strawberryPopPrice;
				 break;
            case 3 : Order::bubbles += Bubbles::pomegranatePopStr + "\n";
				 Order::bubbleSubtotal += Bubbles::pomegranatePopPrice;
				 break;
			case 4 : Order::bubbles += Bubbles::blueberryPopStr + "\n";
				 Order::bubbleSubtotal += Bubbles::blueberryPopPrice;
				 break;
            case 5 : Order::bubbles += Bubbles::passionFruitPopStr + "\n";
				 Order::bubbleSubtotal += Bubbles::passionFruitPopPrice;
				 break;
            default:
                 displayInvalidOption(menuNumber);
                 return false;
		}
	}

	return true;
}

std::string getExtrasName(int extraNum)
{
	switch(extraNum)
	{
		case 1 : return Extras::mangoSlushStr;
		case 2 : return Extras::coffeeSlushStr;
		case 3 : return Extras::extraIceStr;
		case 4 : return Extras::freshTaroStr;
		case 5 : return Extras::almondPearlsStr;
		default: return "Unknown Extra";
	}
}

float  getExtrasPrice(std::string extraName)
{
	if (extraName == Extras::mangoSlushStr)
	{
		return Extras::mangoSlushPrice;
	}
	else if (extraName == Extras::coffeeSlushStr)
	{
		return Extras::coffeeSlushPrice;
	}
	else if (extraName == Extras::extraIceStr)
	{
		return Extras::extraIcePrice;
	}
	else if (extraName == Extras::freshTaroStr)
	{
		return Extras::freshTaroPrice;
	}
	else if (extraName == Extras::almondPearlsStr)
	{
		return Extras::almondPearlsPrice;
	}
	else
	{
		return 0;
	}
}

bool processExtrasOption(int menuNumber)
{

    if (menuNumber == 0)
	{
	} else
	{
		switch (menuNumber)
		{
			case 1 : Order::extras += Extras::mangoSlushStr + "\n";
				 Order::extraSubtotal += Extras::mangoSlushPrice;
				 break;
			case 2 : Order::extras += Extras::coffeeSlushStr + "\n";
				 Order::extraSubtotal += Extras::coffeeSlushPrice;
				 break;
            case 3 : Order::extras += Extras::extraIceStr + "\n";
				 Order::extraSubtotal += Extras::extraIcePrice;
				 break;
			case 4 : Order::extras += Extras::freshTaroStr + "\n";
				 Order::extraSubtotal += Extras::freshTaroPrice;
				 break;
            case 5 : Order::extras += Extras::almondPearlsStr + "\n";
				 Order::extraSubtotal += Extras::almondPearlsPrice;
				 break;
            default:
                 displayInvalidOption(menuNumber);
                 return false;
		}
	}

	return true;
}

bool processOrder(int num)
{
    switch (num)
    {
        case 0 : return false;
        case 1 : displayTeaMenus();
                 processTeaOption(getMenuOption());
                 break;
        case 2 : displayBubbleMenu();
                 processBubbleOption(getMenuOption());
                 break;
        case 3 : displayExtraMenu();
                 processExtrasOption(getMenuOption());
                 break;
        default: displayInvalidOption(num);
    }


    return true;
}

void formOrder()
{
    resetOrder();
    displayWelcome();

    displayMainMenu();

    while (processOrder(getMenuOption()))
    {
        displayMainMenu();
    }

    processBill();

    displayGoodBye();
}
