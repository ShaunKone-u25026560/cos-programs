#ifndef TESTINGFRAMEWORK_H
#define TESTINGFRAMEWORK_H

#include <iostream>
#include <sstream>
#include <string>
#include <iostream>

#include "Exception.h"
#include "Array.h"
#include "InvalidSizeException.h"
#include "ElementNotInListException.h"
#include "InvalidIndexException.h"
#include "TooManyPrintersDeleted.h"
#include "PrinterNotInitialized.h"
#include "DLList.h"
#include "Queue.h"
#include "Stack.h"
#include "Printer.h"

void testAll();
void testArray();
void testDLList();
void testQueue();
void testStack();
void testPrinter();

#endif /* TESTINGFRAMEWORK_H */
