#include <iostream>

template <class T>
int RandomStrategy<T>::a = 1103515245;
template <class T>
int RandomStrategy<T>::c = 12345;
template <class T>
int RandomStrategy<T>::m = 2147483648;

template <class T>
RandomStrategy<T>::RandomStrategy(int size)
                    : Storage<T>(size)
{}

template <class T>
void RandomStrategy<T>::addData(T value) // Function 2
{
    int r = this->size; // the random number initialised to size of array

    if (this->data)
    {
        for (int i = 0; i < 3 * this->size; i++)
        {
            // generate random number
            r = (a*r + c) % m;

            if (r < 0)
                r *= -1;

            int index = r % this->size;
            if (this->data[index] == NULL)
            {
                this->data[index] = new T(value);
                return;
            }
        }
    }
}

template <class T>
void RandomStrategy<T>::removeData(T value) // Function 3
{
    int r = this->size;

    if (this->data)
    {
        for (int i = 0; i < 3 * this->size; i++)
        {
            // generate random number
            r = (a*r + c) % m;

            if (r < 0)
                r *= -1;

            int index = r % this->size;
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
int RandomStrategy<T>::getIndex(T value) // Function 4
{
    int r = this->size;

    if (this->data)
    {
        for (int i = 0; i < 3 * this->size; i++)
        {
            // generate random number
            r = (a*r + c) % m;

            if (r < 0)
                r *= -1;

            int index = r % this->size;
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
