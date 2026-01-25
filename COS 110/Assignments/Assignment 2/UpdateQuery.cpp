#include "UpdateQuery.h"

UpdateQuery::UpdateQuery(std::string query) // Function 1
            : column(""), value(""), oldvalue("")
{
    if (!query.empty())
    {
        std::stringstream qry(query);
        std::getline(qry, column, ':');
        std::string temp = "";
        std::getline(qry, temp, ':');

        qry.str("");
        qry.clear();
        qry.str(temp);

        std::getline(qry, oldvalue, ';');
        std::getline(qry, value, ';');
    }
}

UpdateQuery::~UpdateQuery() // Function 2
{}

QueryResponse* UpdateQuery::operator()(Database& db) // Function 3
{
    // Check if query is valid for passed in database
    if (*this != db)
        return NULL;

    // Search for a row where the element in the specified column matches oldvalue
    // Once found, update that elements data to value
    Column* tempColumn = getColumn(db, column);

    if (tempColumn != NULL)
    {
        int index = (*tempColumn)(oldvalue);

        if (index != -1) // If Query was successful and old value was found, reutrn QueryResponse Object
        {
            (*tempColumn)(oldvalue, value); // Update element in row and specific column

            QueryResponse* response = new QueryResponse("Updated a row");
            return response;
        }
    }

    // If Query was successful but match was not found, reutrn QueryResponse Object
    QueryResponse* response = new QueryResponse("No row was updated");
    return response;
}

bool UpdateQuery::operator!=(const Database& db) const // Function 4
{
    if (db[column] == NULL)
        return true;

    return false;
}

UpdateQuery::operator std::string() const // Function 5
{
    std::stringstream result;
    result << "UPDATE DATABASE SET " << column << " = " << value << " WHERE " << column << " = " << oldvalue;

    return result.str();
}
