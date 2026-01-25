#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <sys/wait.h>
#include <unistd.h>
#include <mutex>

// Do not change or add anything additional to this file as it will be overwritten during grading.

class Matrix {
private:
    int size;
    int** data;
    
public:
    Matrix();
    Matrix(int matrixSize);
    Matrix(const Matrix& other);
    ~Matrix();
    
    // Assignment operator
    Matrix& operator=(const Matrix& other);
    
    // Get the size of the matrix
    int getSize() const;
    
    // Load matrix from file
    bool loadFromFile(const char* filename);
    
    // Get element at position (row, col)
    int getElement(int row, int col) const;
    
    // Set element at position (row, col)
    void setElement(int row, int col, int value);
    
    //  Print matrix
    void print() const {
        if (data == NULL || size == 0) {
            std::cout << "Empty Matrix" << std::endl;
            return;
        }
    
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << data[i][j];
                if (j < size - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    
    // Main matrix multiplication function
    void matrixCalculator(const Matrix& matrix1, const Matrix& matrix2, int rowIndex);
};

// Process function declaration
void task1_processes(const char* matrixFile1, const char* matrixFile2);

// Process print status function declaration
void process_printStatus(long id, int rowIndex, bool complete);

// Thread function declaration
void task1_threads(const char* matrixFile1, const char* matrixFile2);

// Thread worker function declaration for thread function
void threadWorker(const Matrix& matrix1, const Matrix& matrix2, 
                  Matrix& result, int rowIndex, std::mutex* printMutex);

// Thread print status function declaration
void thread_printStatus(std::thread::id id, int rowIndex, bool complete);

#endif
