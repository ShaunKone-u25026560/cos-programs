#include "Matrix.h"
// If you wish to include any helper functions, please do so at the end of this file.

/*=================================================================================*/
// Default Constructor
Matrix::Matrix() : size(0), data(NULL) {
}

Matrix::Matrix(int matrixSize) : size(matrixSize), data(NULL) {
    if (size > 0) {
        data = new int*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new int[size];
            for (int j = 0; j < size; j++) {
                data[i][j] = 0;
            }
        }
    }
}

// Copy Constructor
Matrix::Matrix(const Matrix& other) : size(other.size), data(NULL) {
    if (size > 0) {
        data = new int*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new int[size];
            for (int j = 0; j < size; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        // Clean up existing data
        if (data != NULL) {
            for (int i = 0; i < size; i++) {
                delete[] data[i];
            }
            delete[] data;
        }

        // Copy size and allocate new memory
        size = other.size;
        if (size > 0) {
            data = new int*[size];
            for (int i = 0; i < size; i++) {
                data[i] = new int[size];
                for (int j = 0; j < size; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
    }
    return *this;
}

// Destructor
Matrix::~Matrix() {
    if (data != NULL) {
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

/*=================================================================================*/
/*======================= Implement the below functions ===========================*/
/*=================================================================================*/

// Get the size of the matrix
int Matrix::getSize() const {
    return size;
}

// Load matrix from file
bool Matrix::loadFromFile(const char* filename) {
    // size
    // Open file
    std::ifstream matrixFile;
    matrixFile.open(filename);

    if (!matrixFile.is_open()) // ERROR Handling 1: File cannot be opened
    {
        std::cout << "ERROR: File could not be opened" << std::endl;
        return false;
    }else
    {
        int numCols = 0, numRows = 0, matrixSize = 0;
        std::string line = "", values = "";
        std::stringstream ss, ww;

        // Read all rows and determine the number of columns
        while (std::getline(matrixFile, line) && numCols == matrixSize)
        {
            if (!line.empty()) // Do nothing if line is empty
            {
                numCols = 0;
                ss.str(line);
                while (std::getline(ss, values, ' '))
                {
                    numCols++;
                    /////////////////////////////////////////////////////////////////
                    // std::cout << "Value: " << values << std::endl;
                    /////////////////////////////////////////////////////////////////
                }

                if (numRows == 0)
                    matrixSize = numCols;

                /////////////////////////////////////////////////////////////////
                // std::cout << "MatrixSize [" << numRows << "] = " << matrixSize << " NumCols = " << numCols << std::endl;
                /////////////////////////////////////////////////////////////////

                numRows++;
                ss.clear();
                ss.str("");
            }
        }

        if (numCols != matrixSize || numRows != matrixSize) // ERROR Handling: Returns false if not square matrix
        {
            std::cout << "ERROR: Not a square matrix" << std::endl;
            matrixFile.close();
            return false;
        }

        // Allocate data
        // Return to beginning of file
        matrixFile.clear();
        matrixFile.seekg(0);

        if (data) // Remove old data if it still exists
        {
            for (int i = 0; i < this->size; i++)
            {
                if (data[i])
                    delete[] data[i];
            }
            delete[] data;
            data = NULL;
        }

        // Allocate memory & Data
        data = new int*[matrixSize];

        for (int i = 0; i < matrixSize; i++)
        {
            std::getline(matrixFile, line);
            ss.str(line);
            data[i] = new int[matrixSize];

            for (int j = 0; j < matrixSize; j++)
            {
                std::getline(ss, values, ' ');
                ww.str(values);
                ww >> data[i][j];
                ww.clear();
                ww.str("");
            }

            ss.clear();
            ss.str("");
        }

        this->size = matrixSize;
    }


    matrixFile.close();
    return true;
}

// Get element at position (row, col)
int Matrix::getElement(int row, int col) const {
    if (row < 0 || col < 0 || row >= this->size || col >= this->size || data == NULL)
    {
        return 0;
    }else
    {
        if (data[row]) // Checks to see if the row exists
        {
            return data[row][col];
        }else
        {
            return 0;
        }
    }
}

// Set element at position (row, col)
void Matrix::setElement(int row, int col, int value) {
    if (row >= 0 && col >= 0 && row < this->size && col < this->size && data)
    {
        if (data[row]) // Checks to see if the row exists
        {
            data[row][col] = value;
        }
    }
}

// Main matrix multiplication function
void Matrix::matrixCalculator(const Matrix& matrix1, const Matrix& matrix2, int rowIndex) {

    // Validate the rowIndex, validate that all matrices including THIS one have the correct size
    if (rowIndex >= 0 && rowIndex < this->size && matrix1.getSize() == this->size && matrix2.getSize() == this->size)
    {
        int result = 0;

        for (int j = 0; j < this->size; j++)
        {
            for (int k = 0; k < this->size; k++)
            {
                result += matrix1.getElement(rowIndex, k) * matrix2.getElement(k, j);
            }

            this->setElement(rowIndex, j, result);
            result = 0;
        }
    }

}

// Thread worker function for thread function
void threadWorker(const Matrix& matrix1, const Matrix& matrix2,
                  Matrix& result, int rowIndex, std::mutex* printMutex) {

    printMutex->lock(); // LOCK MUTEX
    std::cout << "Thread has begun" << std::endl; // Indicate thread has begun
    printMutex->unlock(); // UNLOCK MUTEX

    result.matrixCalculator(matrix1, matrix2, rowIndex); // Compute Row

    printMutex->lock(); // LOCK MUTEX
    std::cout << "Thread has completed" << std::endl; // Indicate thread has begun
    printMutex->unlock(); // UNLOCK MUTEX
}
