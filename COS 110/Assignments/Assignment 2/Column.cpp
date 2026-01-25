#include "Column.h"
#include "BooleanColumn.h"
#include "CharacterColumn.h"
#include "IntegerColumn.h"
#include "RealValueColumn.h"
#include "TextColumn.h"

Column::Column(std::string columnName, int columnSize) // Function 1
{
    if (columnSize < 0)
        this->columnSize = 0;
    else
        this->columnSize = columnSize;

    this->columnName = columnName;
}

Column* Column::createColumnFromSchema(std::string schema) // Function 2
{
    std::string columnSchemaName = "", columnType = "", columnTypeLower = "", item = "";

    std::stringstream ss(schema);
    std::getline(ss, item, ':');
    columnSchemaName = item;
    std::getline(ss, item, ':');
    columnType = item;

    // ColumnType must be made lowercase
    int length = columnType.length();
    for (int i = 0; i < length; i++)
    {
        if (columnType[i] >= 65 && columnType[i] <= 90)
            columnTypeLower += columnType[i] + 32;
        else
            columnTypeLower += columnType[i];
    }

    if (columnTypeLower == "bool")
    {
        return new BooleanColumn(columnSchemaName, 0);
    }else if (columnTypeLower == "char")
    {
        return new CharacterColumn(columnSchemaName, 0);
    }else if (columnTypeLower == "int")
    {
        return new IntegerColumn(columnSchemaName, 0);
    }else if (columnTypeLower == "real")
    {
        return new RealValueColumn(columnSchemaName, 0);
    }else
    {
        return new TextColumn(columnSchemaName, 0);
    }
}

Column::operator int() const // Function 3
{
    return this->columnSize;
}

Column::operator std::string() const // Function 4
{
    return this->columnName;
}

bool Column::operator==(const Column& col) const // Function 5
{
    bool isSame = true;

    if (this == &col)
        return true;
    else
    {
        if (this->columnName == col.columnName && this->columnSize == col.columnSize)
        {

            for (int i = 0; i < this->columnSize; i++)
            {
                if (std::string(*((*this)[i])) != std::string(*(col[i])))
                    isSame = false;
            }
        }else
            isSame = false;
    }

    return isSame;
}

bool Column::operator!=(const Column& col) const // Function 6
{
    return !((*this) == col);
}

Column::~Column() // Function 7
{
    // No Dynmaic Memory To deallocate
}
