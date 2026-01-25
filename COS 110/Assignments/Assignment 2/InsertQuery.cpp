#include "InsertQuery.h"

InsertQuery::InsertQuery(std::string query) // Function 1
{
    if (!query.empty())
    {
        std::stringstream qry(query);
        std::string colName = "", colData = "", param;

        numParams = 0;
        while (std::getline(qry, param, ','))
        {
            numParams++;
        }

        qry.str("");
        qry.clear();

        params = new std::string[numParams];
        qry.str(query);

        for (int i = 0; i < numParams; i++)
        {
            std::getline(qry, param, ',');

            params[i] = param;
        }

    }else
    {
        numParams = 0;
        params = NULL;
    }
}

InsertQuery::InsertQuery(std::string* params, int numParams) // Function 2
{
    if (numParams < 0 || params == NULL)
        this->numParams = 0;
    else
        this->numParams = numParams;

    this->params = new std::string[this->numParams];

    for (int i = 0; i < this->numParams; i++)
    {
        this->params[i] = params[i];
    }
}

InsertQuery::~InsertQuery() // Function 3
{
    if (params)
    {
        delete[] params;
    }
}

QueryResponse* InsertQuery::operator()(Database& db) // Function 4
{
    if (numParams <= 0 || getNumberOfColumns(db) <= 0 || *this != db)
    {
        return NULL;
    }

    Column* tempColumn;
    std::stringstream item;
    std::string colName = "", colData = "";

    for (int i = 0; i < numParams; i++)
    {
        item.str(params[i]);
        std::getline(item, colName, ':');
        std::getline(item, colData, ':');

        tempColumn = getColumn(db, colName);

        *tempColumn += colData;

        item.str("");
        item.clear();
    }

    QueryResponse* response = new QueryResponse("Row successfully inserted");

    return response;
}

bool InsertQuery::operator!=(const Database& db) const // Function 5
{
    bool cannotBePerformed = false;

    if (numParams != getNumberOfColumns(db))
    {
        cannotBePerformed = true;
    }else
    {
        std::stringstream item;
        std::string colName = "";

        for (int i = 0; i < numParams; i++)
        {
            item.str(params[i]);
            std::getline(item, colName, ':');

            if (db[colName] == NULL)
                cannotBePerformed = true;

            item.str("");
            item.clear();
        }
    }

    return cannotBePerformed;
}

InsertQuery::operator std::string() const // Function 6
{
    std::stringstream result;
    result << "INSERT INTO DATABASE (";

    for (int i = 0; i < numParams; i++)
    {
        result << params[i];

        if (i != numParams - 1)
            result << ",";
    }

    result << ")";

    return result.str();
}
