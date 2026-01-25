#include "PrinterNotInitialized.h"
#include "InvalidIndexException.h"
#include "TooManyPrintersDeleted.h"

template < template <class> class Iterable, class T>
Printer<Iterable, T>* Printer<Iterable, T>::printer = NULL;
template < template <class> class Iterable, class T>
int Printer<Iterable, T>::numberOfRequests = 0;

template < template <class> class Iterable, class T >
Printer<Iterable, T>& Printer<Iterable, T>::requestPrinter() // Function 1
{
    if (!printer)
        printer = new Printer<Iterable, T>();

    ++numberOfRequests;

    return *printer;
}

template < template <class> class Iterable, class T >
void Printer<Iterable, T>::returnPrinter() // Function 2
{
    --numberOfRequests;

    if (numberOfRequests == 0)
    {
        delete printer;
        printer = NULL;
    }else if (numberOfRequests < 0)
            throw TooManyPrintersDeleted();

}

template < template <class> class Iterable, class T >
void Printer<Iterable, T>::insertDocument(T& data) // Function 3
{
    if (!printer)
        throw PrinterNotInitialized();

    printerQueue += data;
}

template < template <class> class Iterable, class T >
void Printer<Iterable, T>::printToStream(std::ostream& out) // Function 4
{
    printerQueue.setStart();

    try{
            while (!printerQueue.isAtEnd())
            {
                T currentValue = T(printerQueue);
                // catch InvalidIndexExceptions
                out << currentValue << std::endl;

                printerQueue -= currentValue; ///////////////////////// May have to check this: Should we actually remove the element?

                // Iterate through the printer's queue
                // ++printerQueue; //////////////////////// May have to change if post and pre for Iterator were changed
            }
        }catch (InvalidIndexException& e)
        {
            out << "NULL" << std::endl;
        }
}

template < template <class> class Iterable, class T >
void Printer<Iterable, T>::printToFile(std::fstream& f) // Function 5
{
    printerQueue.setStart();

    while (!printerQueue.isAtEnd())
    {
        T currentValue = T(printerQueue);

        f << currentValue << std::endl;

        printerQueue -= currentValue; ///////////////////////// May have to check this: Should we actually remove the element?
        // Iterate through the printer's queue
        // ++printerQueue; //////////////////////// May have to change if post and pre for Iterator were changed
    }
}

template < template <class> class Iterable, class T >
int Printer<Iterable, T>::numberOfDocuments() // Function 6
{
    int size = 0;
    printerQueue.setStart();

    while (!printerQueue.isAtEnd())
    {
        ++size;
        // Iterate through the printer's queue
        ++printerQueue; //////////////////////// May have to change if post and pre for Iterator were changed
    }

    return size;
}

template < template <class> class Iterable, class T >
bool Printer<Iterable, T>::isInQueue(T& data) // Function 7
{
    printerQueue.setStart();

    while (!printerQueue.isAtEnd())
    {
        if (T(printerQueue) == data)
            return true;
        // Iterate through the printer's queue
        ++printerQueue; //////////////////////// May have to change if post and pre for Iterator were changed
    }

    return false;
}

template < template <class> class Iterable, class T >
Printer<Iterable, T>::Printer() // Function 8
{}
