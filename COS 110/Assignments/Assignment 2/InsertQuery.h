#ifndef INSERTQUERY_H
#define INSERTQUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Query.h"
#include "Database.h"

class InsertQuery : public Query
{
    private:
        std::string* params; // Member 1
        int numParams; // Member 2
    public:
        InsertQuery(std::string query); // Function 1
        InsertQuery(std::string* params, int numParams); // Function 2
        virtual ~InsertQuery(); // Function 3
        virtual QueryResponse* operator()(Database& db); // Function 4
        virtual bool operator!=(const Database& db) const; // Function 5
        virtual operator std::string() const; // Function 6
};

#endif /* INSERTQUERY_H */
