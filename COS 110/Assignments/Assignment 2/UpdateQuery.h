#ifndef UPDATEQUERY_H
#define UPDATEQUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Query.h"
#include "Database.h"

class UpdateQuery : public Query
{
    private:
        std::string column; // Member 1
        std::string value; // Member 2
        std::string oldvalue; // Member 3
    public:
        UpdateQuery(std::string query); // Function 1
        virtual ~UpdateQuery(); // Function 2
        virtual QueryResponse* operator()(Database& db); // Function 3
        virtual bool operator!=(const Database& db) const; // Function 4
        virtual operator std::string() const; // Function 5
};

#endif /* UPDATEQUERY_H */
