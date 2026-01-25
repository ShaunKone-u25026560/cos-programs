#include "InvalidSizeException.h"
#include "InvalidIndexException.h"
#include "ElementNotInListException.h"

template <class T>
Array<T>::Array(int size) // Function 1
{
    if (size <= 0)
        throw InvalidSizeException(size);
    this->size = size;
    data = new T*[this->size]; //////////////// May have to move this to happen BEFORE you check for size

    for (int i = 0; i < this->size; i++)
    {
        data[i] = NULL;
    }
}

template <class T>
Array<T>::~Array() // Function 2
{
    if (data)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i])
            {
                delete data[i];
            }
        }

        delete[] data;
    }
}

template <class T>
int Array<T>::numElements() const // Function 3
{
    int count = 0;

    if (data)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i])
                ++count;
        }
    }

    return count;
}

template <class T>
Array<T>::operator int() const // Function 4
{
    return this->size;
}

template <class T>
Array<T>& Array<T>::operator+=(T& d) // Function 5
{

    bool inserted = false;

    if (data)
    {
        for (int i = 0; i < size && !inserted; i++)
        {
            if (data[i] == NULL)
            {
                data[i] = new T(d);
                inserted = true;
            }
        }

        if (!inserted)
        {
            int newSize = size * 2;

            T** newData = new T*[newSize];

            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }

            delete[] data;

            for (int i = size; i < newSize; i++)
            {
                newData[i] = NULL;
            }

            size = newSize;
            data = newData;

            this->operator+=(d);
        }
    }

    return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(T& d) // Function 6
{
    int index = -1;

    if (data)
    {
        for (int i = 0; i < size && index == -1; i++)
        {
            if (data[i])
            {
                if (*(data[i]) == d) // Assuming that the element has a opeartor overload for != or == operator
                    index = i;
            }
        }

        if (index != -1) // Value was found in Array
        {
            // Value is removed from array
            delete data[index];
            data[index] = NULL;

            // Check to see if arary is half full AFTER removing
            int halfArraySize = size / 2;
            int newSize = 0; // Size remains the same if the number of elements after removal is greater than or equal to half the size fo the array

            if (this->numElements() < halfArraySize)
            {
                // If it IS half full, set new array size
                newSize = halfArraySize;

                // Values are removed from Array, then reassigned through creation of new array
                T** newData = new T*[newSize];

                for (int i = 0, j = 0; i < size; i++)
                {
                    if (data[i])
                    {
                        newData[j] = data[i];
                        ++j;
                    }
                }

                for (int i = this->numElements(); i < newSize; i++) // Re-Adding the NULL values into newData
                {
                    newData[i] = NULL;
                }

                delete[] data;
                size = newSize;
                data = newData;
            }
        }else
            throw ElementNotInListException();
    }else
        throw ElementNotInListException();

    return *this;
}

template <class T>
const T& Array<T>::operator[](int index) const // Function 7
{
    if (index >= 0 && index < size)
    {
        if (data && data[index])
            return *(data[index]);
        else
            throw InvalidIndexException(index, true);
    }

    throw InvalidIndexException(index);
}

template <class T>
T& Array<T>::operator[](int index) // Function 8
{
    if (index >= 0 && index < size)
    {
        if (data && data[index])
            return *(data[index]);
        else
            throw InvalidIndexException(index, true);
    }

    throw InvalidIndexException(index);
}

template <class T>
Array<T>* Array<T>::clone() // Function 9
{
    Array<T>* result = new Array<T>(this->size);

    for (int i = 0; i < result->size; i++)
    {
        if (data[i])
            result->data[i] = new T(*(data[i]));
        else
            result->data[i] = NULL;
    }

    return result;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array) // Function 10
{
    if (array.data)
    {
        int arrSize = array.size;

        for (int i = 0; i < arrSize; i++)
        {
            if (array.data[i])
                out << *(array.data[i]);
            else
                out << "NULL";

            if (i != arrSize - 1)
                out << ",";
        }
    }

    return out;
}

template <class T>
template <class U> ////////////////////////// Might have to remove this and change the below const "U" to cont "T"
bool Array<T>::operator==(const U& rhs) const // Function 11
{

    /* Alternative that works WAY better, just output the array's of both using the << operator and place
        the results in stringstreams and then compare the two string's, they should be the same in order for
        this to be valid */

    /* If you have to consider NULL, use this:
    for (int i = 0; i < this->size; i++)
        {
            try
            {
                    if ((*this)[i] != rhs[i])
                        return false;
                }catch (InvalidIndexException&)
                {
                    return false;
                }

            }catch (InvalidIndexException&)
            {
                try
                {
                    rhs[i];
                    return false;
                }catch (InvalidIndexException&)
                {  If we manage to catch both of these, it means both are likely NULL  }
            }
    */

    if ( this->size == int(rhs)) // Check to see if sizes match
    {
        for (int i = 0; i < this->size; i++)
        {
            try
            {
                if ((*this)[i] != rhs[i])
                    return false;
            }catch (InvalidIndexException& err)
            {
                    return false;
            }
        }
    }else
    {
        return false;
    }

    return true;
}
