#ifndef FORWARDSTRATEGY_H
#define FORWARDSTRATEGY_H
#include "Storage.h"

template <class T>
class ForwardStrategy : public Storage<T>
{
    public:
        ForwardStrategy(int size); // Function 1
        virtual void addData(T value); // Function 2
        virtual void removeData(T value); // Function 3
        virtual int getIndex(T value); // Function 4
};

#include "ForwardStrategy.cpp"
#endif /* FORWARDSTRATEGY_H */