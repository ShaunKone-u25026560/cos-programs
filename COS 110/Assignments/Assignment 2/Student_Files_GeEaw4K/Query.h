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



#include "Database.h"

#endif /* QUERY_H */
