#include "select.h"

Select::Select() {}
Select::~Select() {}

size_t Select::parse(std::string query)
{
    std::size_t select_index = query.find(" select ");
    std::size_t from_index = query.find(" from ");

    std::string select_string = query.substr(select_index+8, from_index-select_index-7); // 'SELECT ' -> 7  chars before the connection name
    select_string.erase(std::remove_if(select_string.begin(), select_string.end(), isspace), select_string.end());

    std::stringstream ss(select_string);
    std::string temp;

    while(std::getline(ss, temp, ','))
        select_columns.push_back(temp);

    return from_index;
}

std::vector<std::string> Select::get_select_columns()
{
    return select_columns;
}