#include "Matrix.h"
#include <iostream>

// Do not change or add anything additional to this file as it will be overwritten during grading.

// Process status printing function
void process_printStatus(long id, int rowIndex, bool complete) {
    if (!complete) //based on process activity status print appropriate message
        std::cout << "Process " << id << " calculating row " << rowIndex << std::endl;
    else
        std::cout << "Process " << id << " completed row " << rowIndex << std::endl;
}

// Thread status printing function
void thread_printStatus(std::thread::id id, int rowIndex, bool complete) {
    if (!complete) //based on thread activity status print appropriate message
        std::cout << "Thread " << id << " calculating row " << rowIndex << std::endl;
    else
        std::cout << "Thread " << id << " completed row " << rowIndex << std::endl;
}
