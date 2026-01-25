#include <iostream>
#include <cmath>
#include <sstream>

template <class T>
FibonacciStrategy<T>::FibonacciStrategy(int size) // Function 1
                    : Storage<T>(size)
{}

template <class T>
void FibonacciStrategy<T>::addData(T value) // Function 2
{
    int v = 0, prev1 = 1, prev2 = 0, index = 0;

    if (this->data)
    {
        for (int i = 0; i < 3 * this->size; i++)
        {
            if (i != 0)
            {
                v = prev1 + prev2;
                if (i != 1)
                    prev2 = prev1;
                prev1 = v;

                index = v % this->size;
            }else
                index = 0;

            if (this->data[index] == NULL)
            {
                this->data[index] = new T(value);
                return;
            }
        }
    }
}

template <class T>
void FibonacciStrategy<T>::removeData(T value) // Function 3
{
    int v = 0, prev1 = 1, prev2 = 0, index = 0;

    if (this->data)
    {
        for (int i = 0; i < 3 * this->size; i++)
        {
            if (i != 0) // Continue sequence
            {
                v = prev1 + prev2;
                if (i != 1)
                    prev2 = prev1;
                prev1 = v;

                index = v % this->size; // make index
            }else
                index = 0;

            if (this->data[index] != NULL)
            {
                if (*this->data[index] == value)
                {
                    delete this->data[index];
                    this->data[index] = NULL;
                    return;
                }
            }
        }
    }
}

template <class T>
int FibonacciStrategy<T>::getIndex(T value) // Function 4
{
    int v = 0, prev1 = 1, prev2 = 0, index = 0;

    if (this->data)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (i != 0) // Continue sequence
            {
                v = prev1 + prev2;
                if (i != 1)
                    prev2 = prev1;
                prev1 = v;

                index = v % this->size; // make index
            }else
                index = 0;

            if (this->data[index])
            {
                if (*this->data[index] == value)
                {
                    return index;
                }
            }
        }
    }

    return -1;
}
