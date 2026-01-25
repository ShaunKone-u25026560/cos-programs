#include <iostream>
#include "Recursive.h"

int main()
{
    char s1[] = "tomcat";
    char s2[] = "warthog";


    char s[] = " ";

    std::cout << Recursive::length(&s1[0]) << std::endl;
    std::cout << "Does the string contain it: " << Recursive::contains(&s2[0], 'a');

    Recursive::reverseWord(&s1 [0], &s[0]);
    std::cout << "Reversed Word: ";
    Recursive::printout(&s[0]);

    std::cout << s;

    std::cout << "Occurences letter appears: " << Recursive::countOccurrences(&s1[0], 'e') << std::endl;
    Recursive::printInReverse(&s1[0]);

    std::cout << "Last Letter: " << Recursive::findLastLetter(&s2[0]) << std::endl;


    std::cout << "Number of characters inbetween pointers: " << Recursive::charactersBetween(&s1[0], &s1[4]) << std::endl;
    std::cout << "Number of characters inbetween pointers: " << Recursive::charactersBetween(&s1[0], &s2[0]) << std::endl;

	return 0;
}
