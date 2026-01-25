#include "Brainhurt.h"
#include "Tape.h"

/*
========== Output in out.txt ==========
*/

int main() {
    /*
        Adds two numbers together and prints the output. Afterwards it prints out "Hello"

        This version hard codes the numbers. This is how you should also do testing for Fitchfork , since cin won't work on Fitchfork
    */
    Brainhurt b(7);
    std::stringstream in, out;
    in << 20 << std::endl
       << 50 << std::endl;
    b(",>,[<+>-]<.", in, out);
    // b(",>,[<+>-]<.", cin, cout); Only use these for local testing... this will break the testing task on Fitchfork
    b("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.", in, out);
    std::cout << out.str();
    return 0;
}
