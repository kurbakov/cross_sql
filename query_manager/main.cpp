#include <iostream>
#include <vector>
#include <map>

#include "query_manager.h"
#include "select.h"
#include "from.h"

int main()
{
    std::string str = " select a, b, c from {main query}::my_table where e != 'value' ";

    // call classes
    QueryManager* qm = new QueryManager;
    Select* s = new Select;
    From* f = new From;
    
    // initial parse
    qm->parse(str);

    // check subqueries
    auto queries = qm->get_queries();
    for(auto it = queries->begin(); it != queries->end(); it++)
        std::cout << it->first << " -- " << it->second << "\n";

    // clean query to build
    auto query = qm->get_raw_query();
    std::cout << *query << "\n";

    // parse select part
    size_t idx_select = s->parse(str);
    
    // remove parsed part of the string
    query->erase(0, idx_select);

    // check if data correct
    auto data = s->get_select_columns();
    for (auto el : data)
        std::cout << el <<"\n";

    // rest of the string to parse
    std::cout << *query << "\n";

    // parse from table value
    size_t idx_from = f->parse(*query);

    query->erase(0, idx_from);    

    // get FROM value
    auto from_table = f->get_from_table();
    std::cout << *from_table << "\n";

    // free memory
    delete f;
    delete s;
    delete qm;

    return 0;
}



