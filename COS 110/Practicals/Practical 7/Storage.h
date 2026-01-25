#ifndef STORAGE_H
#define STORAGE_H

template <class T>

class Storage
{
    protected:
        T** data; // Member 1
        int size; // Member 2
    public:
        Storage(int size); // Function 1
        virtual ~Storage(); // Function 2
        void print(); // Function 3
        virtual void addData(T value) = 0; // Function 4
        virtual void removeData(T value) = 0; // Function 5
        virtual int getIndex(T value) = 0; // Function 6
};

#include "Storage.cpp"
#endif /* STORAGE_H */