#include "SearchQuery.h"

SearchQuery::SearchQuery(std::string query) // Function 1
            : column(""), value("")
{
    if (!query.empty())
    {
        std::stringstream qry(query);
        std::getline(qry, column, ':');
        std::getline(qry, value, ':');
    }
}

SearchQuery::~SearchQuery() // Function 2
{}

QueryResponse* SearchQuery::operator()(Database& db) // Function 3
{
    // Check if query is valid for passed in database
    if (*this != db)
        return NULL;

    // Search for element in specifiec "column" that matches "value", get that index
    // Start by checking to see which index the value matches the column element at (use operator() in Column) and put that into a tempColumn variable
    Column* tempColumn = getColumn(db, column);

    if (tempColumn != NULL)
    {
        // getting the index of the element in "column" with the same value as "value"
        int index = (*tempColumn)(value);

        if (index != -1) // If Query was successful and match was found, reutrn QueryResponse Object
        {
            std::stringstream values;
            // Then using that index get every value and add it to a string
            int numCols = getNumberOfColumns(db);
            // NB DONT MAKE THIS NEW VARIABLE POINT ANYWHERE ELSE
            Column** tempColumns = getColumns(db);

            for (int i = 0; i < numCols; i++)
            {
                const Element* val = (*(tempColumns[i]))[index];
                values << std::string(*val);

                if (i != numCols - 1)
                    values << ",";
            }

            QueryResponse* response = new QueryResponse(values.str());
            return response;
        }
    }

    // If Query was successful but match was not found, reutrn QueryResponse Object
    QueryResponse* response = new QueryResponse("No records found");
    return response;
}

bool SearchQuery::operator!=(const Database& db) const // Function 4
{
    if (db[column] == NULL)
        return true;

    return false;
}

SearchQuery::operator std::string() const // Function 5
{
    std::stringstream result;
    result << "SELECT FROM DATABASE WHERE " << column << " = " << value;

    return result.str();
}
