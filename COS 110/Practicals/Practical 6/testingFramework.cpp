#include "testingFramework.h"

void testAll()
{
    // Header
    std::cout << "========================\nTESTING FRAMEWORK\n========================" << std::endl;

    // TileException
    std::cout << "Testing TileException\n========================\n";
    try
    {
        std::string message = "***Tile exception Test message: Exception successfuly thrown***";
        if (true)
            throw TileException(message);
    }catch (TileException tileExcept)
    {
        std::cout << tileExcept.getMessage() << std::endl;
    }

    // Footer (End)
    std::cout << "========================\nTESTING FRAMEWORK END\n========================" << std::endl;

}
