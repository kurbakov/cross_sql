#include "from.h"

From::From()
{
	from_table = new std::string;
}

From::~From()
{
	delete from_table;
}

size_t From::parse(std::string query)
{
	size_t from_index = query.find(" from ")+6;
    int idx = from_index;
    while(query[idx] != ' ' && idx < query.size()) idx++;

    from_table->assign( query.substr(from_index, idx-from_index) );
    return idx;
}

std::string* From::get_from_table()
{
	return from_table;
}