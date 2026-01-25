#ifndef REVERSESTRATEGY_H
#define REVERSESTRATEGY_H
#include "Storage.h"

template <class T>
class ReverseStrategy : public Storage<T>
{
    public:
        ReverseStrategy(int size); // Function 1
        virtual void addData(T value); // Function 2
        virtual void removeData(T value); // Function 3
        virtual int getIndex(T value); // Function 4
};

#include "ReverseStrategy.cpp"
#endif /* REVERSESTRATEGY_H */