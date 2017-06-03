#ifndef POSTRGES_H
#define POSTRGES_H

#pragma once

#include <vector>
#include <map>

#include <libpq-fe.h>       			// postgresAPI

#include "connection.h"

class PostgresIterator;

class PostgresConnection : public Connection
{
private:
		PGconn* conn;
    PGresult* res;

		std::map<int, std::string> data_types; 										// mapping data type ID and data type name
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

		std::string get_value(int row_index, int col_index) const;

public:
		friend class PostgresIterator;

		PostgresConnection(std::string, std::string, std::string, std::string, std::string);
		~PostgresConnection();

		void execute(std::string query);
		void make_ddl();

    PostgresIterator* createIterator() const;
};

class PostgresIterator{
private:
	const PostgresConnection* psql_conn;

	int row_index;
	int col_index;

public:
	PostgresIterator(const PostgresConnection*);

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

#endif // POSTRGES_H
