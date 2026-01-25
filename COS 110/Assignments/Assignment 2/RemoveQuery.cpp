#include "RemoveQuery.h"

RemoveQuery::RemoveQuery(std::string query) // Function 1
            : column(""), value("")
{
    if (!query.empty())
    {
        std::stringstream qry(query);
        std::getline(qry, column, ':');
        std::getline(qry, value, ':');
    }
}

RemoveQuery::~RemoveQuery() // Function 2
{}

QueryResponse* RemoveQuery::operator()(Database& db) // Function 3
{
    // Check if query is valid for passed in database
    if (*this != db)
        return NULL;

    // Delete the first row in the database where value == column element
    // Start by checking to see which index the value matches the column element at (use operator() in Column) and put that into a tempColumn variable
    Column* tempColumn = getColumn(db, column);
    // NB DONT MAKE THIS NEW VARIABLE POINT ANYWHERE ELSE
    Column** tempColumns = getColumns(db);

    int numCols = getNumberOfColumns(db);
    if (tempColumn != NULL && tempColumns != NULL && numCols > 0)
    {
        // getting the index of the element in "column" with the same value as "value"
        int index = (*tempColumn)(value);

        // Then using that index use operator-= for every Column in columns array of db to remove an entire "Row"
        for (int i = 0; i < numCols; i++)
        {
            ////////////if (tempColumns[i])
            ////////////{
                *(tempColumns[i]) -= index;
            ////////////}
        }

        // If Query was successful and row was removed, reutrn QueryResponse Object
        QueryResponse* response = new QueryResponse("Row successfully removed");
        return response;
    }

    // If Query was successful and row was NOT removed, reutrn QueryResponse Object
    QueryResponse* response = new QueryResponse("No rows were removed");
    return response;
}

bool RemoveQuery::operator!=(const Database& db) const // Function 4
{
    if (db[column] == NULL)
        return true;

    return false;
}

RemoveQuery::operator std::string() const // Function 5
{
    std::stringstream result;
    result << "DELETE FROM DATABASE WHERE " << column << " = " << value;

    return result.str();
}
