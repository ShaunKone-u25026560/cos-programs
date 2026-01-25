#include "QueryResponse.h"

QueryResponse::QueryResponse(std::string msg)
            : message(msg)
{}


std::ostream& operator<<(std::ostream& os, const QueryResponse& query)
{
    os << query.message;

    return os;
}
