#include <iostream>

template <class T>
Storage<T>::Storage(int size) // Function 1
{
    if (size < 0)
        this->size = 0;
    else
        this->size = size;

    this->data = new T*[this->size];

    for (int i = 0; i < this->size; i++)
    {
        this->data[i] = NULL;
    }
}

template <class T>
Storage<T>::~Storage() // Function 2
{
    if (this->data)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i])
                delete this->data[i];
        }

        delete[] this->data;
    }
}

template <class T>
void Storage<T>::print() // Function 3
{
    std::cout << "[";

    if (this->data)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i])
            {
                std::cout << *(this->data[i]);
            }else
                std::cout << "-";

            if (i != this->size - 1)
                std::cout << ",";
        }
    }

    std::cout << "]" << std::endl;
}
