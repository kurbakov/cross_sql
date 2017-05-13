#ifndef CONNECTION_MYSQL_H
#define CONNECTION_MYSQL_H

#pragma once

#include <vector>
#include <my_global.h>
#include <mysql.h>
// http://stackoverflow.com/questions/4157644/how-do-i-convert-a-string-to-a-char-in-c


class MySQL
{
private:
	MYSQL *conn;
	MYSQL_RES *res;
    std::string login;
    std::string password;
    std::string host;
    std::string port;
    std::string database;

public:
	MySQL(std::string, std::string, std::string, std::string, std::string);
	~MySQL();

    void open_connection();
    void close_connection();
    void execute(std::string);
    std::vector<std::string> get_column_names();
    void print_table();
};

#endif


