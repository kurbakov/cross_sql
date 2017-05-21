#ifndef CONNECTION_H
#define CONNECTION_H

#pragma once

#include <vector>

class Connection
{
public:
	virtual ~Connection(){}

	virtual void execute(std::string query) = 0;
	virtual void print_table() = 0;
	virtual std::vector<std::string> get_column_names() = 0;
};

#endif // CONNECTION_H