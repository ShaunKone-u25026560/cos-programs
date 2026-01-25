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

    public:
        friend class Query;
};

#endif /* DATABASE_H */
