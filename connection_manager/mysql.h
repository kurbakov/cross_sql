#ifndef MQSQL_H
#define MQSQL_H

#pragma once

#include <vector>
#include <iostream>
#include <map>

#include <my_global.h>		// mysql API
#include <mysql.h>			// mysql API

#include "connection.h"

class MysqlIterator;

class MysqlConnection : public Connection
{
private:
	MYSQL *conn;
	MYSQL_RES *res;

	std::map<int, std::string> data_types; 	
	std::vector<std::pair<std::string, std::string> > ddl; 		// column name - column data type
    
    std::string login;
    std::string password;
    std::string host;
    std::string port;
    std::string database;

    int n_cols;
	int n_rows;

    void open_connection();
    void close_connection();

public:
	friend class MysqlIterator;

	MysqlConnection(std::string, std::string, std::string, std::string, std::string);
	~MysqlConnection();

	void execute(std::string);
	void make_ddl();

	MysqlIterator* createIterator() const;
};

class MysqlIterator{
private:
	const MysqlConnection* msql_conn;
	MYSQL_ROW row;

	int row_index;
	int col_index;

public:
	MysqlIterator(const MysqlConnection*);

	void first_row();
	void first_col();

	void set_row(int);
	void set_col(int);

	void next_row();
	void next_col();

	bool is_row_done();
	bool is_col_done();

	std::string get_current_value();
};

#endif // MQSQL_H