#include "OutOfBoundsException.h"

template <template <class> class Iterable, class T>
Iterator<Iterable, T>::Iterator() // Function 1
{
    currentPosition = 0;
}

template <template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator++(int i) // Function 2
{
    // Check that size allows for increasing postion
    int size = int(iterable);

    if (currentPosition >= size)
        throw OutOfBoundsException();

    if (currentPosition >= -1 && size > 0)
        ++currentPosition;

    return *this;
}

template <template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator++() // Function 3
{
    // Check that size allows for increasing postion
    int size = int(iterable);

    if (currentPosition >= size)
        throw OutOfBoundsException();

    if (currentPosition >= -1 && size > 0) /////////////////////// May ahve to change this, 2 and 4 & 5
        ++currentPosition;

    return *this;
}

template <template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator--(int i) // Function 4
{
    // Check that size allows for increasing postion
    int size = int(iterable);

    if (currentPosition < 0)
        throw OutOfBoundsException();

    if (currentPosition >= 0 && size > 0 && currentPosition < size)
        --currentPosition;

    return *this;
}

template <template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator--() // Function 5
{
    // Check that size allows for increasing postion
    int size = int(iterable);

    if (currentPosition < 0)
        throw OutOfBoundsException();

    if (currentPosition >= 0 && size > 0 && currentPosition < size)
        --currentPosition;

    return *this;
}

template <template <class> class Iterable, class T>
Iterator<Iterable, T>::operator T&() // Function 6
{
    return iterable[currentPosition];
}

template <template <class> class Iterable, class T>
void Iterator<Iterable, T>::setStart() // Function 7
{
    currentPosition = 0;
}

template <template <class> class Iterable, class T>
void Iterator<Iterable, T>::setEnd() // Function 8
{
    currentPosition = int(iterable);
}

template <template <class> class Iterable, class T>
bool Iterator<Iterable, T>::isAtStart() const // Function 9
{
    return (currentPosition == 0)? true : false;
}

template <template <class> class Iterable, class T>
bool Iterator<Iterable, T>::isAtEnd() const // Function 10
{
    return (currentPosition == int(iterable))? true : false;
}

template <template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator+=(T& data) // Function 11
{
    iterable += data;

    return *this;
}

template <template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator-=(T& data) // Function 12
{
    iterable -= data;

    return *this;
}
