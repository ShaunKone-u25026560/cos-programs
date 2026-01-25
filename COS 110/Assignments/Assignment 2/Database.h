#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Column.h"
#include "Query.h"
#include "QueryResponse.h"


class Database;
std::ostream &operator<<(std::ostream &, const Database &);
std::ofstream &operator<<(std::ofstream &, const Database &);
std::ifstream &operator>>(std::ifstream &, Database &);

class Database
{
    private:
        int numColumns; // Member 1
        std::string databaseName; // Member 2
        Column** columns; // Member 3
        Database(); // Function 1
        Database& operator<<(std::string str); // Function 2
    public:
        friend class Query;
        ~Database(); // Function 3
        Database(const Database& other); // Function 4
        static Database* buildFromSchema(std::string schema, std::string name = "Database"); // Function 5
        static Database* buildFromFile(std::string schema, std::string fileName, char deliminator = ',', std::string name = "Database");  // Function 6
        QueryResponse* processQuery(Query* query); // Function 7
        Database& operator=(const Database& other); // Function 8
        Database& operator+=(const Column*); // Function 9
        Database operator+(const Column*) const; // Function 10
        Database& operator-=(const Column*); // Function 11
        Database operator-(const Column*) const; // Function 12
        Database& operator+=(std::string line); // Function 13
        Database operator+(std::string line) const; // Function 14
        const Column* operator[](int column) const; // Function 15
        const Column* operator[](std::string column) const; // Function 16
        Column* operator[](int column); // Function 17
        Column* operator[](std::string column); // Function 18
        const bool operator[](const Column& column) const; // Function 19
        bool operator!() const; // Function 20
        bool operator==(const Database&) const; // Function 21
        bool operator!=(const Query&) const; // Function 22
        friend std::ostream &operator<<(std::ostream &, const Database &); // Function 23
        friend std::ofstream &operator<<(std::ofstream &, const Database &); // Function 24
        friend std::ifstream &operator>>(std::ifstream &, Database &); // Function 25
};

#endif /* DATABASE_H */
