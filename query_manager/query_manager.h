#ifndef QUERY_MANAGER_H
#define QUERY_MANAGER_H

#pragma once

#include <vector>
#include <map>
#include <string>

class QueryManager
{
public:
    QueryManager();
    ~QueryManager();

    bool parse(std::string);
    std::string* get_raw_query();
    std::map<std::string, std::string>* get_queries();


private:
    std::string* _raw_data;
    std::map<std::string, std::string>* _queries;

    void set_queries();
    void clean_string();

};

#endif // QUERY_MANAGER_H