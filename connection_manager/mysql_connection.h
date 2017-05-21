#ifndef MQSQL_CONNECTION_H
#define MQSQL_CONNECTION_H

#pragma once

#include <vector>
#include <iostream>

#include <my_global.h>		// mysql API
#include <mysql.h>			// mysql API

#include "connection.h"


class Mysql_connection : public Connection
{
private:
	MYSQL *conn;
	MYSQL_RES *res;
    
    std::string login;
    std::string password;
    std::string host;
    std::string port;
    std::string database;

    void open_connection();
    void close_connection();

public:
	Mysql_connection(std::string, std::string, std::string, std::string, std::string);
	~Mysql_connection();

	void execute(std::string) final;
	void print_table() final;
	std::vector<std::string> get_column_names() final;
};

#endif // MQSQL_CONNECTION_H