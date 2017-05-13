#ifndef CONNECTION_POSTGRES_H
#define CONNECTION_POSTGRES_H

#pragma once

#include <vector>
#include <libpq-fe.h>
// http://zetcode.com/db/postgresqlc/


class PostgreSQL
{
private:
    PGconn* conn;
    PGresult* res;

    std::string login;
    std::string password;
    std::string host;
    std::string port;
    std::string database;

public:
    Postgres(std::string, std::string, std::string, std::string, std::string);
    ~Postgres();

    void open_connection();
    void close_connection();

    void execute(std::string);

    std::vector<std::string> get_column_names();
    void print_table();
};

#endif