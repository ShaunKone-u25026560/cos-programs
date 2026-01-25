#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Column.h"
#include "Element.h"

class Database;

class Query;
std::ostream& operator<<(std::ostream& out, const Query& q);

class Query
{
    protected:
        Column* getColumn(Database& db, std::string column) const; // Function 1
        Column**& getColumns(Database&) const; // Function 2
        int getNumberOfColumns(const Database&) const; // Function 3
        std::string getDatabase(const Database&) const; // Function 4
    public:
        virtual ~Query(); // Function 5
        virtual QueryResponse* operator()(Database& db) =0; // Function 6
        virtual bool operator!=(const Database& db) const =0; // Function 7
        virtual operator std::string() const =0; // Function 8
        friend std::ostream& operator<<(std::ostream& out, const Query& q); // Function 9
};

#include "Database.h"

#endif /* QUERY_H */
