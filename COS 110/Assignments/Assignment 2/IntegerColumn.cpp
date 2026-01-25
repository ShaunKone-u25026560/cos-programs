#include "IntegerColumn.h"

IntegerColumn::IntegerColumn(std::string columnName, int columnSize) // Function 1
                : Column(columnName, columnSize)
{
    // Initialise The array member to have columnSize number "Null" elements
    array = new IntegerElement*[this->columnSize];

    for (int i = 0; i < this->columnSize; i++)
    {
        array[i] = NULL;
    }
}

IntegerColumn::~IntegerColumn() // Function 2
{
    if (array)
    {
        for (int i = 0; i < columnSize; i++)
        {
            if (array[i])
            {
                delete array[i];
            }
        }

        delete[] array;
        array = NULL;
    }


}

IntegerColumn* IntegerColumn::clone() const // Function 3
{
    IntegerColumn* clone = new IntegerColumn(columnName, columnSize);

    if (array)
    {
        for (int i = 0; i < columnSize; i++)
        {
            if (array[i])
            {
                *clone += std::string(*array[i]);
            }
        }
    }

    return clone;
}

IntegerColumn& IntegerColumn::operator+=(std::string data) // Function 4 / 9
{
    if (this->array) // If array exists, append
    {
        // Create a element using "data"
        IntegerElement* newElement = new IntegerElement(data);

        // Create a copy of the array with the added size
        int newColumnSize = this->columnSize + 1;
        IntegerElement** newArray = new IntegerElement*[newColumnSize];

        // Copy over all values from the old array
        for (int i = 0; i < this->columnSize; i++)
        {
            // Copy over the address in the array
            newArray[i] = this->array[i];
        }

        // Add the new element
        newArray[newColumnSize - 1] = newElement;

        // Delete the old array
        delete[] this->array;

        // Point the old array to the new array
        this->array = newArray;
        columnSize = newColumnSize;

        // Make new Array point to nothing
        newArray = NULL;
    }else
    {
        // If array does not exist, create a new one and append element to it
        this->array = new IntegerElement*[1];
        this->array[0] = new IntegerElement(data);

        columnSize = 1;
    }

    return *this;
}

IntegerColumn& IntegerColumn::operator-=(std::string data) // Function 5 / 10
{
    // Remove the passed in data from the column

    // Find the passed in data by iterating through the array using a while loop with the data == to array as the condition
    if (this->array) // If array exists, remove
    {
        int index = 0;

        for (int i = 0; i < columnSize; i++)
        {
            if (this->array[index])
            {
                if (*(this->array[index]) != data)
                    index++;
            }else
                index++;
        }

        // Remove the offending element
        // Decrease columnSize variable by 1 if the index is less than or equal to the columnSize-1
        if (index < columnSize)
        {

                // Create a copy of the array with the decreased size
                int newColumnSize = this->columnSize - 1;
                IntegerElement** newArray = new IntegerElement*[newColumnSize];

                // Copy over all values from the old array except the offending one
                for (int i = 0, j = 0; i < this->columnSize; i++)
                {
                    // Copy over the address in the array
                    if (i != index)
                    {
                        newArray[j] = this->array[i];
                        j++;
                    }
                }

                // Delete the value at that specific index
                delete this->array[index];
                delete[] this->array;

                // Point the old array to the new array
                this->array = newArray;
                columnSize = newColumnSize;

                // Make new Array point to nothing
                newArray = NULL;
        }
    }

    return *this;
}

IntegerColumn& IntegerColumn::operator-=(int index) // Function 6 / 11
{
    // Remove the passed in index from the column

    // Find the passed in data by iterating through the array using a while loop with the data == to array as the condition
    if (this->array && index >= 0 && index < columnSize && columnSize > 0) // If array exists and index is valid, remove
    {

        // Create a copy of the array with the decreased size
        int newColumnSize = this->columnSize - 1;
        IntegerElement** newArray = new IntegerElement*[newColumnSize];

        // Copy over all values from the old array except the offending one
        for (int i = 0, j = 0; i < this->columnSize; i++)
        {
            // Copy over the address in the array
            if (i != index)
            {
                newArray[j] = this->array[i];
                j++;
            }
        }

        // Delete the value at that specific index
        delete this->array[index];
        delete[] this->array;

        // Point the old array to the new array
        this->array = newArray;
        columnSize = newColumnSize;

        // Make new Array point to nothing
        newArray = NULL;
    }

    return *this;
}

int IntegerColumn::operator()(std::string data) const // Function 7 / 12
{
    // Iterate through array to find the passed in data
    if (array)
    {
        int index = 0;

        for (int i = 0; i < columnSize; i++)
        {
            if (this->array[index])
            {
                if (*(this->array[index]) != data)
                    index++;
            }else
                index++;
        }

        if (index >= columnSize || columnSize <= 0)
            return -1;
        else
            return index;
    }else
        return -1;

}

IntegerColumn& IntegerColumn::operator()(std::string value, std::string newValue) // Function 8 / 13
{
    if (array)
    {
        // Iterate through column to find the index
        int index = 0;

        for (int i = 0; i < columnSize; i++)
        {
            if (this->array[index])
            {
                if (*(this->array[index]) != value)
                    index++;
            }else
                index++;
        }

        if (index < columnSize)
        {
            // Update only the first occurence of the element the same as "value" to "newValue"
            delete this->array[index];
            this->array[index] = new IntegerElement(newValue);
        }
    }

    // Return current object
    return *this;
}

const IntegerElement* IntegerColumn::operator[](int pos) const // Function 9/ 14
{
    // If index is invalid return NULL
    if (pos < 0 || pos >= columnSize)
        return NULL;
    else
        return this->array[pos];
}

const IntegerElement* IntegerColumn::operator[](std::string value) const// Function 10 / 15
{
    // Iterate through array to find the passed in data
    if (array)
    {
        int index = 0;

        for (int i = 0; i < columnSize; i++)
        {
            if (this->array[index])
            {
                if (*(this->array[index]) != value)
                    index++;
            }else
                index++;
        }

        if (index >= columnSize || columnSize <= 0)
            return NULL;
        else
            return this->array[index];
    }else
        return NULL;
}

bool IntegerColumn::operator!() const// Function 11 / 16
{
    bool isValid = false;
    // Check to see if Column is valid using 3 criteria
    if (array != NULL && columnSize >= 0) // 1. Array should NOT be NULL 2. The columnSize >= 0
    {
        isValid = true;

        // 3. The column should be full i.e. not have any gaps meaning no NULL Elements in array
        for (int i = 0; i < columnSize; i++)
        {
            if (!array[i]) // If array is null, set isValid to false
                isValid = false;
        }
    }

    return isValid;
}
