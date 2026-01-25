#include <iostream>
#include "ConcurrentSorting.h"

int main(){
    std::vector<int> example({3,2,1});
    initBuffer(example);
    concurrentSort();
    printResults();
    return 0;
}
