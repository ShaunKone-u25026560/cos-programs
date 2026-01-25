#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Iterator.h"

template < template <class> class Iterable, class T >
class Printer{
    private:
        static Printer<Iterable, T>* printer; // Member 1
        static int numberOfRequests; // Member 2
        Iterator<Iterable, T> printerQueue; // Member 3
    public:
        static Printer<Iterable, T>& requestPrinter(); // Function 1
        static void returnPrinter(); // Function 2
        void insertDocument(T& data); // Function 3
        void printToStream(std::ostream& out); // Function 4
        void printToFile(std::fstream& f); // Function 5 
        int numberOfDocuments(); // Function 6
        bool isInQueue(T& data); // Function 7
    private:
        Printer(); // Function 8
};

#include "Printer.cpp"

#endif /* PRINTER_H */