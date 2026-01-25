#include <iostream>
#include "Iterative.h"

int main()
{
	char s1[] = "tomcat";

	char s2[] = "warthog";

	char rev[7] = "";

	std::cout << "The length of the string is: " << Iterative::length(&s1[0]) << std::endl;
	std::cout << "The character at position 3: " << Iterative::find(&s2[0], 3) << std::endl;
	std::cout << "Does it contain a: " << Iterative::contains(&s1[0], 'a') << std::endl;
	std::cout << "Does it contain b: " << Iterative::contains(&s1[0], 'b') << std::endl;
	Iterative::printout(&s1[0]);
	Iterative::reverseWord(&s2[0], &rev[0]);
	std::cout << "Number of occurences of t: " << Iterative::countOccurrences(&s1[0], 't') << std::endl;
	std::cout << "Most frequent letter: "  << Iterative::mostFrequentLetter(&s1[0]) << std::endl;
	Iterative::printInReverse(&s2[0]);
	std::cout << "Last Letter: " << Iterative::findLastLetter(&s1[0]) << std::endl;

	char s[] = "deed";

	std::cout << "Is this a palindrome: "  << Iterative::isPalindrome(&s[0]) << std::endl;
	std::cout << "Is this a palindrome: " << Iterative::isPalindrome(&s1[0]) << std::endl;;

	std::cout << "Number of characters between positions: " << Iterative::charactersBetween(&s1[0], &s1[4]) << std::endl;
	std::cout << "Number of characters between positions: " << Iterative::charactersBetween(&s1[0], &s2[0]) << std::endl;

	return 0;
}
