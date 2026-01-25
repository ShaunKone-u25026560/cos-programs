#include "Matrix.h"

std::mutex threadLock;

// Helper function for thread computing
void computeMatrixRow(Matrix* resultMatrix, const Matrix* matrix1, const Matrix* matrix2, int rowIndex)
{
    {
        std::lock_guard<std::mutex> lock(threadLock);
        // Print Message indicating thread ID and row Number when row beings to be computed
        thread_printStatus(std::this_thread::get_id(), rowIndex, false);
    }

    // Computes all entries in corresponding row of the result matrix
    resultMatrix->matrixCalculator((*matrix1), (*matrix2), rowIndex);

    {
        std::lock_guard<std::mutex> lock(threadLock);
        // Prints message indicating completion
        thread_printStatus(std::this_thread::get_id(), rowIndex, true);
    }
}


void task1_threads(const char* matrixFile1, const char* matrixFile2)
{
    // Create two input matrices & result matrix
        Matrix matrix1, matrix2;

    // Load input matrices from textfiles
    if (matrix1.loadFromFile(matrixFile1) && matrix2.loadFromFile(matrixFile2) && matrix1.getSize() == matrix2.getSize())
    {
        // Start of thread-based matrix multiplication
        std::cout << "\nStarting thread-based matrix multiplication:" << std::endl;

        // Create a resultMatrix with getSize() size to store the resulting computation
        Matrix resultMatrix(matrix1.getSize());

        int size = matrix1.getSize();
        // Create an array of threads with a scope outside of the for loop that will then be created in the for loop
        std::thread* workers = new std::thread[size];

        // Create worker thread in loop
        for (int i = 0; i < size; i++)
        {
            // Create worker threads
            workers[i] = std::thread(computeMatrixRow, &resultMatrix, &matrix1, &matrix2, i);
        }

        // Main thread should now join all these threads after the last thread has been created, so we dont execute anything until ALL threads have finished
        for (int i = 0; i < size; i++)
        {
            workers[i].join();
        }

        delete[] workers;

        // In main thread after last thread has been constructed:
        // Print resulting matrix size in main thread
        std::cout << "\nResulting Matrix (Thread-based) size: " << size << "x" << size << std::endl;
        resultMatrix.print();

    }else // Matrices aren't compatible for Multiplication: Print error message and terminate
    {
        std::cout << "Matrices are incompatible for multiplication" << std::endl;
        return;
    }
}
