#include "FibonacciStrategy.h"
#include "ForwardStrategy.h"
#include "RandomStrategy.h"
#include "ReverseStrategy.h"
#include "Storage.h"
#include "testingFramework.h"

using namespace std;

// Output in out.txt

int main(int argc, char* argv[]) {

    testAll();

    RandomStrategy<int> randStrat(5);
    randStrat.addData(0);
    randStrat.addData(1);
    randStrat.addData(2);
    randStrat.print();

    FibonacciStrategy<string> fibStrat(5);
    fibStrat.addData("Hello");
    fibStrat.addData("COS110");
    fibStrat.addData("World");
    fibStrat.addData("!");
    fibStrat.print();
    return 0;
}
