#include <iostream>

#include "StatsInterface.h"
#include "StatsCalculator.h"

using namespace std;

int main(){
    STATSCALCULATOR::setFileName("studentData.txt");
    STATSCALCULATOR::processFile();

    printValueF("The average of the data points is: ", getAverageOfDataPoints());
    printValueB("2 is contained in the list of data points: ", isTheValueInTheListRev(2));
    printValueS("The list contains: ", getListOfPointsInOrder());
    printStart();
    printEnd();
    // Testing


    printMoveToNext();
    printAverage();
    printValue();

    
}

/*
The expected output is: 
The average of the data points is: 7.75
2 is contained in the list of data points: 0
The list contains: 1 5 10 15 
START: 0
END: 3
*/
