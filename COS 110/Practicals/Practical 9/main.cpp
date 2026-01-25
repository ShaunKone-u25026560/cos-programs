#include <sstream>
#include <string>

#include "CircularList.h"
#include "testingFramework.h"

/*
    Output in out.txt
*/
int main(int argc, char* argv[]) {
    CircularList<int> l;
    l += 10;
    l += 5;
    l += 3;
    cout << l;
    l -= 5;
    cout << l;

    testAll();
    return 0;
}
