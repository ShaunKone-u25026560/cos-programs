#include <iostream>

template <class T>
ForwardStrategy<T>::ForwardStrategy(int size) // Function 1
                    : Storage<T>(size)
{}

template <class T>
void ForwardStrategy<T>::addData(T value) // Function 2
{
    if (this->data)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i] == NULL)
            {
                this->data[i] = new T(value);
                return;
            }
        }
    }
}

template <class T>
void ForwardStrategy<T>::removeData(T value) // Function 3
{
    if (this->data)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i] != NULL)
            {
                if (*this->data[i] == value)
                {
                    delete this->data[i];
                    this->data[i] = NULL;
                    return;
                }
            }
        }
    }
}

template <class T>
int ForwardStrategy<T>::getIndex(T value) // Function 4
{
    if (this->data)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i])
            {
                if (*this->data[i] == value)
                {
                    return i;
                }
            }
        }
    }

    return -1;
}
