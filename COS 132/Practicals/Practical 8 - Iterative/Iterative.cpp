#include <iostream>

namespace Iterative
{
	int length(const char *start)
	{
		int len = 0;

		while (*start != '\0')
		{
			len++;
			start++;
		}

		return len;
	}

	char find(const char *start, int index)
	{
		// May have to remove the recursion on this length(start)
		if (index < 0 || index >= length(start))
		{
			return '\0';
		}else
		{
			return *(start + index);
		}
	}

	bool contains(const char *start, char letter)
	{
		while (*start != '\0')
		{
			if (*start == letter)
				return true;
			start++;
		}

		return false;
	}

	void printout(const char *start)
	{
		// May be asking to print each character on a serperate line
		while (*start != '\0')
		{
			std::cout << *start;
			start++;
		}

		std::cout << std::endl;
	}

	void reverseWord(char *start, char *result)
	{
		char *finish = start;
		while (*finish != '\0')
		{
			finish++;
		}
		finish--;

		do{
			*result = *finish;
			finish--;
			result++;
			start++;
		} while (*start != '\0');
	}

	int countOccurrences(const char *start, char c)
	{
		int count = 0;

		while (*start != '\0')
		{
			if (*start == c)
				count++;
			start++;
		}

		return count;
	}

	char mostFrequentLetter(const char *start)
	{
		int freq[256] = {0};
		const char* begin = start;

		char most = *start;

		int count = 0;
		int index;

		while (*start != '\0')
		{
		    index = *start;

			freq[index]++;
			start++;
		}

		while (*begin != '\0')
		{
		    index = *begin;
			if (freq[index] > count)
			{
				count = freq[index];
				most = *begin;
			}
				begin++;
		}

		return most;
	}

	void printInReverse(const char* start)
	{
		const char *finish = start;
                while (*finish != '\0')
                {
                        finish++;
                }
                finish--;

                do{
                        std::cout << *finish;
                        finish--;
                        start++;
                } while (*start != '\0');

		std::cout << std::endl;
	}

	char* findLastLetter(char* start)
	{
		while (*start != '\0')
		{
			start++;
		}
		start--;

		return start;
	}

	const char* findLastLetter(const char* start)
	{
		while (*start != '\0')
                {
                        start++;
                }
                start--;

                return start;
	}

	bool isPalindrome(const char* start)
	{
        	const char *finish = start;

        	while (*finish != '\0')
        	{
                	finish++;
        	}
        	finish--;

        	while (start < finish)
        	{
                	if (*start == *finish)
                	{
                    		start++;
                    		finish--;
               	 	}else
                	    return false;
        		}

        	return true;
	}


	int charactersBetween(const char* p1, const char* p2)
	{
        	int count = 0;

        	while (count < 100)
        	{
                	if (*(p1 + count) == *p2)
                        	return count;
                	count++;
        	}

        	return count;
	}
} // namespace Iterative
