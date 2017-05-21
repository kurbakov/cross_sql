#ifndef POSTRGES_CONNECTION_H
#define POSTRGES_CONNECTION_H

#pragma once

#include <vector>
#include <iostream>

#include <libpq-fe.h>       // postgresAPI

#include "connection.h"


class Postgres_connection : public Connection
{
private:
	PGconn* conn;
    PGresult* res;
    
    std::string login;
    std::string password;
    std::string host;
    std::string port;
    std::string database;

    void open_connection();
    void close_connection();

public:
	Postgres_connection(std::string, std::string, std::string, std::string, std::string);
	~Postgres_connection();

	void execute(std::string query) final;
	void print_table() final;
	std::vector<std::string> get_column_names() final;
};

#endif // POSTRGES_CONNECTION_H