#ifndef REMOVEQUERY_H
#define REMOVEQUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Query.h"
#include "Database.h"

class RemoveQuery : public Query
{
    private:
        std::string column; // Member 1
        std::string value; // Member 2
    public:
        RemoveQuery(std::string query); // Function 1
        virtual ~RemoveQuery(); // Function 2
        virtual QueryResponse* operator()(Database& db); // Function 3
        virtual bool operator!=(const Database& db) const; // Function 4
        virtual operator std::string() const; // Function 5
};

#endif /* REMOVEQUERY_H */
