#ifndef RANDOMSTRATEGY_H
#define RANDOMSTRATEGY_H
#include "Storage.h"

template <class T>
class RandomStrategy : public Storage<T>
{
    private:
        static int a;
        static int c;
        static int m;
    public:
        RandomStrategy(int size); // Function 1
        virtual void addData(T value); // Function 2
        virtual void removeData(T value); // Function 3
        virtual int getIndex(T value); // Function 4
};

#include "RandomStrategy.cpp"
#endif /* RANDOMSTRATEGY_H */