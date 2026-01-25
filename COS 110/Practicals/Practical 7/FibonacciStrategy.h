#ifndef FIBONACCISTRATEGY_H
#define FIBONACCISTRATEGY_H
#include "Storage.h"

template <class T>
class FibonacciStrategy : public Storage<T>
{
    public:
        FibonacciStrategy(int size); // Function 1
        virtual void addData(T value); // Function 2
        virtual void removeData(T value); // Function 3
        virtual int getIndex(T value); // Function 4
};


#include "FibonacciStrategy.cpp"
#endif /* FIBONACCISTRATEGY_H */