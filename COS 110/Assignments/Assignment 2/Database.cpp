#include "Database.h"
#include "Column.h"
#include "BooleanColumn.h"
#include "CharacterColumn.h"
#include "IntegerColumn.h"
#include "RealValueColumn.h"
#include "TextColumn.h"
#include "Element.h"


Database::Database() // Function 1
        : numColumns(-1), databaseName("Database")
{
    columns = NULL;
}

Database& Database::operator<<(std::string str) // Function 2
{
    if (columns)
    {
        // Add values in strings "Deliniated by ',' to each column in turn
        std::stringstream ss(str);
        std::string value = "";

        for (int i = 0; i < numColumns; i++)
        {
            if (columns[i])
            {
                std::getline(ss, value, ',');
                *(columns[i]) += value;
            }
        }
    }

    return *this;
}

Database::~Database() // Function 3
{
    if (columns)
    {
        for (int i = 0; i < numColumns; i++)
        {
            if (columns[i])
                delete columns[i];
        }

        delete[] columns;
    }
}

Database::Database(const Database& other) // Function 4
{
        this->numColumns = other.numColumns;
        this->databaseName = other.databaseName;

        // Copy over all columns
        if (other.columns)
        {
            this->columns = new Column*[this->numColumns];

            for (int i = 0; i < this->numColumns; i++)
            {
                this->columns[i] = ((other.columns)[i])->clone();
            }
        }
}

Database* Database::buildFromSchema(std::string schema, std::string name) // Function 5 (Static)
{
    // Create a Database object
    Database* newDatabase = new Database();
    newDatabase->databaseName = name;
    newDatabase->numColumns = 0;

    // If the passed in schema is empty: return
    if (schema.empty())
    {
        newDatabase->columns = new Column*[0];

        return newDatabase;
    }

    newDatabase->columns = NULL;

    // Populate from schema the columns
    std::stringstream scheme(schema);
    std::string col = "", colName = "", colType = "";
    int index = 0;

    while (std::getline(scheme, col ,','))
    {
        std::stringstream item(col);

        std::getline(item, colName, ':');
        std::getline(item, colType, ':');

        // Create a new temporary Column array
        Column** tempColumns = new Column*[index + 1];

        // Assign the newDatabases columns data to this new one
        for (int i = 0; i < index; i++)
        {
            tempColumns[i] = newDatabase->columns[i];
        }

        // Add new column to temprary Column array
        if (colType == "bool")
        {
            tempColumns[index] = new BooleanColumn(colName, 0);
        }
        else if (colType == "char")
        {
            tempColumns[index] = new CharacterColumn(colName, 0);
        }
        else if (colType == "int")
        {
            tempColumns[index] = new IntegerColumn(colName, 0);
        }
        else if (colType == "real")
        {
            tempColumns[index] = new RealValueColumn(colName, 0);
        }
        else
        {
            tempColumns[index] = new TextColumn(colName, 0);
        }

        // Delete old database at the array
        if (newDatabase->columns)
            delete[] newDatabase->columns;

        // Assign the tempColumns back to the newDatabase's columns
        newDatabase->columns = tempColumns;

        index++;
    }

    // Index now holds the size of the completed columns array
    newDatabase->numColumns = index;

    return newDatabase;
}

Database* Database::buildFromFile(std::string schema, std::string fileName, char deliminator, std::string name)  // Function 6 (Static)
{
    // Use the buildFromSchema Function to create a new database
    Database* newDatabase = buildFromSchema(schema, name);

    if (newDatabase->numColumns > 0 && newDatabase->columns)
    {
        // Populate newDatabase with contents of passed in file
        // Open the file
        std::ifstream file(fileName.c_str());
        std::string line = "", item = "";

        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            int index = 0;

            while (std::getline(ss, item, deliminator) && index < newDatabase->numColumns)
            {
                *(newDatabase->columns[index]) += item;
                index++;
            }

            ss.str("");
            ss.clear();
        }

        file.close();
    }

    return newDatabase;
}

QueryResponse* Database::processQuery(Query* query) // Function 7
{
    if (query != NULL)
        return (*query)(*this);
    else
        return NULL;
}

Database& Database::operator=(const Database& other) // Function 8
{
    // Check for self-assignment
    if (this == &other)
        return *this;

    if (this->columns)
    {
        for (int i = 0; i < this->numColumns; i++)
        {
            if (this->columns[i])
            {
                delete this->columns[i];
            }
        }

        delete[] this->columns;
    }
    this->numColumns = other.numColumns;
    this->databaseName = other.databaseName;

    // Copy over columns
    if (other.columns)
    {
        this->columns = new Column*[this->numColumns];

        for (int i = 0; i < this->numColumns; i++)
        {
            if (other.columns[i])
            {
                this->columns[i] = (other.columns[i])->clone();
            }else
                this->columns[i] = NULL;
        }
    }else
        this->columns = NULL;

    return *this;
}

Database& Database::operator+=(const Column* column) // Function 9
{
    bool nameExists = false;
    if (column)
    {
        // Check ot see if same anme already exists
        for (int i = 0; i < numColumns; i++)
        {
            if (std::string(*column) == std::string(*(this->columns[i])))
                nameExists = true;
        }

        if (!nameExists)
        {
            Column** tempColumns = new Column*[numColumns + 1];

            for (int i = 0; i < numColumns; i++)
            {
                tempColumns[i] = columns[i];
            }

            tempColumns[numColumns] = column->clone();
            delete[] columns;
            columns = tempColumns;
            numColumns++;
        }
    }

    return *this;
}

Database Database::operator+(const Column* column) const // Function 10
{
    Database dbCopy;

    dbCopy = *this;
    dbCopy += column;

    return dbCopy;
}

Database& Database::operator-=(const Column* column) // Function 11
{
    int index = -1;
    if (column)
    {
        // Check ot see if same anme already exists
        for (int i = 0; i < numColumns; i++)
        {
            if (std::string(*column) == std::string(*(this->columns[i])))
                index = i;
        }

        if (index != -1)
        {
            if (numColumns >= 1)
            {
                Column** tempColumns = new Column*[numColumns - 1];

                for (int i = 0, j = 0; i < numColumns; i++)
                {
                    if (i != index)
                    {
                        tempColumns[j] = columns[i];
                        j++;
                    }
                }

                delete columns[index];
                delete[] columns;
                columns = tempColumns;
                numColumns--;
            }else
            {
                numColumns = 0;
                delete[] columns;
            }
        }
    }

    return *this;
}

Database Database::operator-(const Column* column) const // Function 12
{
    Database dbCopy;

    dbCopy = *this;
    dbCopy -= column;

    return dbCopy;
}

Database& Database::operator+=(std::string line) // Function 13
{
    if (columns)
    {
        // Receive string representation
        std::stringstream ss(line);
        std::stringstream item;

        // Insert into database
        std::string col = "", colName = "", colValue = "";

        while(std::getline(ss, col ,','))
        {
            item.str(col);
            std::getline(item, colName, ':');
            std::getline(item, colValue, ':');
            int index = 0;
            bool found = false;

            // Add new value to column
            while (index < numColumns && !found) // Loops if matching column not found
            {
                if (columns[index])
                {
                    if (colName == std::string(*(columns[index])))
                    {
                        found = true;
                        index--;
                    }
                }
                index++;
            }

            if (found) // meaning a match was found
                *(columns[index]) += colValue;

            item.str("");
            item.clear();
        }
    }

    // return current database
    return *this;
}

Database Database::operator+(std::string line) const // Function 14
{
    Database dbCopy;

    dbCopy = *this;
    dbCopy += line;

    return dbCopy;
}

const Column* Database::operator[](int column) const // Function 15
{
    if (column >= 0 && column < numColumns && columns)
        return columns[column];
    else
        return NULL;
}

const Column* Database::operator[](std::string column) const // Function 16
{
    if (columns)
    {
        for (int i = 0; i < numColumns; i++)
        {
            if (columns[i])
            {
                if (column == std::string(*(columns[i])))
                    return columns[i];
            }
        }
    }

    return NULL;
}

Column* Database::operator[](int column) // Function 17
{
    if (column >= 0 && column < numColumns && columns)
        return columns[column];
    else
        return NULL;
}

Column* Database::operator[](std::string column) // Function 18
{
    if (columns)
    {
        for (int i = 0; i < numColumns; i++)
        {
            if (columns[i])
            {
                if (column == std::string(*(columns[i])))
                    return columns[i];
            }
        }
    }

    return NULL;
}

const bool Database::operator[](const Column& column) const // Function 19
{
    if (columns)
    {
        for (int i = 0; i < numColumns; i++)
        {
            if (columns[i])
            {
                if (std::string(column) == std::string(*(columns[i])))
                    return true;
            }
        }
    }

    return false;
}

bool Database::operator!() const // Function 20
{
    if (numColumns >= 0 && columns) // 1 & 2
    {
        for (int i = 0; i < numColumns; i++)
        {
            if (columns[i]) // 3
            {
                if ( !(!(*(columns[i]))) ) // 4
                {
                    return true;
                }else
                {
                    if ( i != numColumns - 1 )
                    {
                        if (int(*(columns[i])) != int(*(columns[i + 1]))) // 5
                            return true;
                    }
                }

            }else
                return true;
        }

    }else
        return true;

    return false; // Database is Valid
}

bool Database::operator==(const Database& other) const // Function 21
{
    if (this->numColumns == other.numColumns) // 1
    {
        if (this->columns && other.columns)
        {
            for (int i = 0; i < numColumns; i++)
            {
                if ( (*(this->columns[i])) != (*(other.columns[i])) ) // 2
                    return false;
            }

        }else if ( (this->columns && !other.columns) || (!this->columns && other.columns) ) // 2
            return false;

    }else
        return false;

    return true; // Databases are equal
}

bool Database::operator!=(const Query& query) const // Function 22
{
    return (query != *this);
}

std::ostream& operator<<(std::ostream &os, const Database &db) // Function 23
{
    if (!db)
        os << "Invalid Database";
    else
    {
        if (db.columns)
        {

            for (int i = 0; i < db.numColumns; i++) // Output names of each column for first line
            {
                os << std::string(*(db.columns[i])) << ",";
            }
            os << std::endl;

            // Output the element in each row coming from each column
            int numElements = int(*(db.columns[0]));

            for (int i = 0; i < numElements; i++)
            {
                for (int j = 0; j < db.numColumns; j++)
                {
                    const Element* item = (*(db.columns[j]))[i];
                    os << std::string(*item);
                    os << ",";
                }
                os << std::endl; ///////////////////////////////// May have to account for the last line having no newline
            }
        }
    }

    return os;
}

std::ofstream& operator<<(std::ofstream &outFile, const Database &db) // Function 24
{
    if (!db)
        outFile << "Invalid Database";
    else
    {
        if (db.columns)
        {
            outFile << "|";
            for (int i = 0; i < db.numColumns; i++) // Output names of each column for first line
            {
                outFile << std::string(*(db.columns[i])) << "|";
            }
            outFile << std::endl;
            outFile << "|-|-|-|" << std::endl;
            outFile << "|";
            // Output the element in each row coming from each column
            for (int i = 0; i < db.numColumns; i++)
            {
                for (int j = 0; j < int(*(db.columns[i])); j++)
                {
                    const Element* item = (*(db.columns[i]))[j];
                    outFile << std::string(*item) << "|";
                }
                outFile << std::endl; ///////////////////////////////// May have to account for the last line having no newline
            }
        }
    }

    return outFile;
}

std::ifstream& operator>>(std::ifstream &inFile, Database &db) // Function 25
{
    // make sure the inFile is at the beginning of the file
    inFile.clear();
    inFile.seekg(0);

    std::string line = "";

    while (std::getline(inFile,line))
    {
        db << line;
    }

    return inFile;
}
