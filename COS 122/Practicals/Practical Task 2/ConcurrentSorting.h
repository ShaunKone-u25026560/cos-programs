#ifndef CONCURRENTSORTING_H
#define CONCURRENTSORTING_H
#include <vector>
#include <iostream>
#include <thread>

/*Given*/
extern std::vector<int> buffer;
extern std::vector<int> originalBuffer;
extern std::vector<std::thread> threadPool;
extern std::vector<int> indices;
extern int currentPhase;
extern int totalSwaps;
extern int totalThreadsUsed;
extern std::string buffertoString();

/*Implement the below functions in ConcurrentSorting.cpp*/
extern void initBuffer(std::vector<int>&);
extern bool isSorted();
extern int maxSwapsExpected();
extern int maxPhasesExpected();
extern void clearThreadPool();
extern void setIndices();
extern void swap(int, int);
extern void SetAndRunThreads();
extern void concurrentSort();
extern void printResults();

#endif
