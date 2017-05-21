#ifndef SELECT_H
#define SELECT_H

#pragma once

#include <vector>
#include <sstream>

class Select
{
public:
    Select();
    ~Select();

    size_t parse(std::string);
    std::vector<std::string> get_select_columns();

private:
    std::vector<std::string> select_columns;
};

#endif // SELECT_H