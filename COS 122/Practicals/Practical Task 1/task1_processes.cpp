#include "Matrix.h"

void task1_processes(const char* matrixFile1, const char* matrixFile2)
{
    // Create two input matrices & result matrix
        Matrix matrix1, matrix2;

    // Load input matrices from textfiles
    if (matrix1.loadFromFile(matrixFile1) && matrix2.loadFromFile(matrixFile2) && matrix1.getSize() == matrix2.getSize())
    {
        // Start of process-based matrix multiplication
        std::cout << "\nStarting process-based matrix multiplication:" << std::endl;

        // Create a resultMatrix with getSize() size to store the resulting computation
        Matrix resultMatrix(matrix1.getSize());

        pid_t pid; // To hold process ID

        // Create child process in loop
        for (int i = 0; i < matrix1.getSize(); i++)
        {

            pid = fork(); // Create child process and get process ID

            if (pid == 0) // If it is a child process
            {
                Matrix result(matrix1.getSize()); // To hold result of child's row computing

                // Print meassage indicating: Process id and Row number
                process_printStatus(getpid(), i, false);

                // Compute the corresponding row (i) of the result matrix
                result.matrixCalculator(matrix1, matrix2, i);

                // Write computed row to temporary file
                // Create temporary File for writing results to with parent process id as marking characteristic
                std::stringstream ss;
                ss << getppid() << "MatrixRow" << i << ".txt";

                std::string tempFileName = ss.str(); // Stores each file name in this format: "[ParentProcessID]MatrixRow[i].txt"
                ss.clear();
                ss.str("");

                std::fstream tempFile(tempFileName.c_str(), std::ios::app | std::ios::out); // Creates file or opens it for writing at end

                // Writing to file, individual values are seperated by ' ' space.
                for (int j = 0; j < matrix1.getSize(); j++) // inputs row into ss
                {
                    ss << result.getElement(i, j);
                    if (j != matrix1.getSize() - 1)
                        ss << " ";
                }

                // writes computed row to temporary File
                tempFile << ss.str();

                tempFile.close(); // closes temporary File

                // Print message indicating: Completion of computation
                process_printStatus(getpid(), i, true);

                // Terminate child process creating a Zombie
                _exit(EXIT_SUCCESS);
            }
        }

        // Now in the main parent process
        while (wait(NULL) > 0); // Wait for all child processes to complete by looping until all have been reaped


        // Read all temporary files
        // Get the files using their unique names
        for (int i = 0; i < matrix1.getSize(); i++)
        {
            std::stringstream out, element;
            out << getpid() << "MatrixRow" << i << ".txt";

            std::string tempFileName = out.str(); // Stores each file name in this format: "[ParentProcessID]MatrixRow[i].txt"
            out.clear();
            out.str("");
            std::fstream tempFileRead(tempFileName.c_str(), std::ios::in);

            // Will use stringstream to get individual space delineated values into the resultMatrix
            std::string line = "", word = "";
            int value = 0;
            std::getline(tempFileRead, line); // Gets row from matrix
            out.str(line); // Wraps string in out

            for (int k = 0; k < matrix1.getSize(); k++)
            {
                std::getline(out, word, ' '); // Gets the values in the row
                element.str(word);
                element >> value;

                resultMatrix.setElement(i, k, value); // Sets entire row

                element.clear();
                element.str("");
            }

            // Delete temporary file
            tempFileRead.close();
            unlink(tempFileName.c_str());
        }
        // Print resulting matrix size
        std::cout << "\nResulting Matrix (Process-based) size: " << matrix1.getSize() << "x" << matrix1.getSize() << std::endl;
        resultMatrix.print();

    }else // Matrices aren't compatible for Multiplication: Print error message and terminate
    {
        std::cout << "Matrices are incompatible for multiplication" << std::endl;
        return;
    }

}
