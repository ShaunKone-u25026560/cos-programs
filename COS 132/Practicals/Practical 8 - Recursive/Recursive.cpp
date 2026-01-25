#include <iostream>

namespace Recursive
{
    int length(const char *str)
    {
        if (*str == '\0')
        {
            return 0;
        }else
        {
            return length(++str) + 1;
        }
    }

    char find(const char *str, int index)
    {
        if (index == 0)
            return *str;
        else
            return find(++str, --index);
    }

    bool contains(const char *str, char letter)
    {
        if (*str != '\0')
        {
            if (*str == letter)
                return true;
            else
                return contains(++str, letter);
        }else
        {
            return false;
        }

    }

    void print(char x)
    {
        std::cout << x;
    }

    void printout(const char *str)
    {
        if (*str != '\0')
        {
            print(*str);
            printout(++str);
        }
        else
            std::cout << std::endl;
    }

    char enterResults(char* x)
    {
        if (*(x + 1) != '\0')
        {
            return enterResults(++x);
        }else
        {
            char temp = *x;
            *x = '\0';
            return temp;
        }
    }

    void reverseWord(char *str, char *result)
    {
        if (*(str + 1) != '\0')
        {
            *result = enterResults(str);
            reverseWord(str, ++result);
        }else
        {
            *result = *str;
        }

    }

    int countOccurrences(const char *str, char c)
    {
        if (*str != '\0')
        {
            if (*str == c)
                return countOccurrences(++str, c) + 1;

            return countOccurrences(++str, c);
        }else
        {
            return 0;
        }
    }

    void printIR(const char* x, const char* start)
    {
        int index = length(x);

        if (index != 0)
        {
            std::cout << *(start + (--index));
            printIR(++x, start);
        }else
        {
            std::cout << std::endl;
        }
    }

    void printInReverse(const char* str)
    {
        printIR(str, str);
    }

    char* findLastLetter(char* str)
    {
        if (*(str + 1) != '\0')
        {
            return findLastLetter(++str);
        }else
        {
            return str;
        }
    }

    const char* findLastLetter(const char* str)
    {
        if (*(str + 1) != '\0')
        {
            return findLastLetter(++str);
        }else
        {
            return str;
        }
    }

    void helper(const char* p1, const char* p2, int& count)
    {
        if (count >= 100)
        {
            count = 100;
            return;
        }

        if (p1 == p2)
        {
            return;
        }
        ++count;
            helper(p1 + 1, p2, count);
    }

    int charactersBetween(const char* p1, const char* p2)
    {
        int count = 0;
        helper(p1, p2, count);
        return count;
    }
} // namespace Recursive
