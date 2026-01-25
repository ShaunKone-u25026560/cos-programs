#include "testingFramework.h"
#include "CircularList.h"

void testAll()
{
    std::cout << "=================================================\n";
    std::cout << "Testing Framework: " << std::endl;
    std::cout << "=================================================\n";

    // Construct a list
    CircularList<double> d;

    cout << "Size of double linked list " << int(d) << ". Should be 0" << std::endl;

    cout << "Is data contained in list " << d[3.5] << ". Should be 0 for false" << std::endl;
    d += 10.4;
    d += 7.8;
    cout << "Is data contained in list " << d[7.8] << ". Should be 1 for true" << std::endl;
    d += 7.8;
    d += 11.5;

    d -= 3.4;
    d -= 7.8;
    d -= 7.8;
    d -= 11.5;
    d -= 10.4;
}
