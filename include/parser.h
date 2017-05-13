#ifndef PARSER_H
#define PARSER_H

#pragma once

#include <map>
#include <vector>
#include <sstream>


class Parser
{
private:
    std::string _raw_data;

    std::map<std::string, std::string> _queries;
    std::vector<std::string> _select_columns;
    std::string _main_table;
    std::vector<std::string> join;
    std::vector<std::string> where;

    void set_queries();
    void set_select_columns();
    void set_from();
    void set_join();
    void set_where();

    void clean_string();

public:
    Parser(std::string);
    ~Parser();

    void print_data();
};

#endif