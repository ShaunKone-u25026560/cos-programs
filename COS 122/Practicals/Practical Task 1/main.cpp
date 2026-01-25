#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Matrix Multiplication Calculator" << std::endl;
    std::cout << "================================" << std::endl;

    if (argc > 1)
	{
	    int task = atoi(argv[1]);
	    if (task == 1)
	    {
                // Run Task 1.1 - Process execution
                std::cout << "\n=== TASK 1.1: PROCESS-BASED MATRIX MULTIPLICATION ===" << std::endl;
                task1_processes("matrix1A.txt", "matrix2A.txt"); // replace with: OG(task1_processes("matrixFile1.txt", "matrixFile2.txt")) || NEW(task_1)
            } else if (task == 2)
            {
                // Run Task 1.2 - Thread execution
                std::cout << "\n=== TASK 1.2: THREAD-BASED MATRIX MULTIPLICATION ===" << std::endl;
                task1_threads("matrix1A.txt", "matrix2A.txt");
            }
            else
	    {
		std::cout << "Invalid subtask specified" << std::endl;
	    }
	} else
	{
	    std::cout << "No subtask specified" << std::endl;
	}
    return 0;
}
