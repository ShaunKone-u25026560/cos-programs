#include "Query.h"

Column* Query::getColumn(Database& db, std::string column) const // Function 1
{
    //Return Column from Column** columns whose columnName == column
    if (db.columns)
    {
        for (int i = 0; i < db.numColumns; i++)
        {
            if (db.columns[i])
            {
                if ( std::string(*(db.columns[i])) == column)
                    return db.columns[i];
            }
        }
    }

    // Return Column OR NULL
    return NULL;
}

Column**& Query::getColumns(Database& db) const // Function 2
{
    return db.columns;
}

int Query::getNumberOfColumns(const Database& db) const // Function 3
{
    return db.numColumns;
}

std::string Query::getDatabase(const Database& db) const // Function 4
{
    return db.databaseName;
}

Query::~Query() // Function 5
{}

std::ostream& operator<<(std::ostream& out, const Query& q) // Function 9
{
    out << std::string(q);
    out << std::endl;

    return out;
}
