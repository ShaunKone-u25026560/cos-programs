#ifndef SEARCHQUERY_H
#define SEARCHQUERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "QueryResponse.h"
#include "Query.h"
#include "Database.h"

class SearchQuery : public Query
{
    private:
        std::string column; // Member 1
        std::string value; // Member 2
    public:
        SearchQuery(std::string query); // Function 1
        virtual ~SearchQuery(); // Function 2
        virtual QueryResponse* operator()(Database& db); // Function 3
        virtual bool operator!=(const Database& db) const; // Function 4
        virtual operator std::string() const; // Function 5
};

#endif /* SEARCHQUERY_H */
