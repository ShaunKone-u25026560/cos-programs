#include "testingFramework.h"
#include "ForwardStrategy.h"
#include "ReverseStrategy.h"
#include "RandomStrategy.h"
#include "FibonacciStrategy.h"
#include "Storage.h"

void testAll()
{
    std::cout << "==================== TESTING FRAMEWORK ====================" << std::endl;
    std::cout << "Random Strategy\n====================\n..." << std::endl;
    RandomStrategy<char> randomStrat(6);
    randomStrat.addData('a');
    randomStrat.addData('b');
    randomStrat.addData('c');
    randomStrat.addData('d');
    randomStrat.removeData('d');
    randomStrat.removeData('e');
    std::cout << "Get index of e = " << randomStrat.getIndex('e') << ". Expected (-1)" << std::endl;
    std::cout << "Get index of b = " << randomStrat.getIndex('b') << ". Expected (Unknown)" << std::endl;

    std::cout << std::endl;
    std::cout << "Forward Strategy\n====================\n..." << std::endl;
    ForwardStrategy<char> forwardStrat(6);
    forwardStrat.addData('a');
    forwardStrat.addData('b');
    forwardStrat.addData('c');
    forwardStrat.addData('d');
    forwardStrat.removeData('d');
    forwardStrat.removeData('e');
    std::cout << "Get index of e = " << forwardStrat.getIndex('e') << ". Expected (-1)"<< std::endl;
    std::cout << "Get index of b = " << forwardStrat.getIndex('b') << ". Expected (1)" << std::endl;

    std::cout << std::endl;
    std::cout << "Reverse Strategy\n====================\n..." << std::endl;
    ReverseStrategy<char> reverseStrat(6);
    reverseStrat.addData('a');
    reverseStrat.addData('b');
    reverseStrat.addData('c');
    reverseStrat.addData('d');
    reverseStrat.removeData('d');
    reverseStrat.removeData('e');
    std::cout << "Get index of e = " << reverseStrat.getIndex('e') << ". Expected (-1)" << std::endl;
    std::cout << "Get index of b = " << reverseStrat.getIndex('b') << ". Expected (4)" << std::endl;

    std::cout << std::endl;
    std::cout << "Fibonacchi Strategy\n====================\n..." << std::endl;
    FibonacciStrategy<char> fibStrat(6);
    fibStrat.addData('a');
    fibStrat.addData('b');
    fibStrat.addData('c');
    fibStrat.addData('d');
    fibStrat.removeData('d');
    fibStrat.removeData('e');
    std::cout << "Get index of e = " << fibStrat.getIndex('e') << ". Expected (-1)" << std::endl;
    std::cout << "Get index of b = " << fibStrat.getIndex('b') << ". Expected (Unknown)" << std::endl;

    std::cout << "==================== TESTING FRAMEWORK END ====================" << std::endl;
}
