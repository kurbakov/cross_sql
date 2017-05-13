#ifndef CONNECTION_SQLITE_H
#define CONNECTION_SQLITE_H

#pragma once

#include <vector>
#include <sqlite3.h>
#include <stdio.h>
// http://zetcode.com/db/sqlitec/
// http://www.dreamincode.net/forums/topic/122300-sqlite-in-c/


class SQLite
{
private:
    sqlite3* conn;
    sqlite3_stmt* res;
    int rc;
    char *err_msg;
    std::string database;
    std::vector<std::vector<std::string>> data;

public:
    SQLite(std::string);
    ~SQLite();

    void open_connection();
    void close_connection();
    void execute(std::string);
    std::vector<std::string> get_column_names();
    void print_table();
};

#endif

