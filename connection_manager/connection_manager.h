#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "connection.h"
#include "mysql_connection.h"
#include "postgres_connection.h"

class Connection_manager 
{
private:
	std::map<std::string, Connection*> connection_pool;

public:
	Connection_manager();
	~Connection_manager();
	
	bool add_connection(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
	bool delete_connection(std::string);

	bool execute(std::string name,  std::string);
	bool print_table(std::string name);
	std::vector<std::string> get_column_names(std::string name);
};

#endif // CONNECTION_MANAGER_H