#include "../include/connection_postgres.h"

PostgreSQL::PostgreSQL(std::string Host, std::string Port, std::string DB, std::string Login, std::string Password) : 
    login(Login), password(Password), host(Host), port(Port), database(DB)
{
}

PostgreSQL::~PostgreSQL()
{
}

void PostgreSQL::open_connection()
{
    std::string conn_string = "user="+login+" password="+password+" dbname="+database+" host="+host+" port="+port;
    conn = PQconnectdb(conn_string.c_str());

    if (PQstatus(conn) == CONNECTION_BAD) 
    {
        std::cout << "We were unable to connect to the database." << "\n";
        std::cout << PQerrorMessage(conn) << "\n";
        
        exit(0);
    }
    else
        std::cout << "Connection is open." << "\n";
    return;
}

void PostgreSQL::close_connection()
{
    PQclear(res);
    PQfinish(conn);
}

void PostgreSQL::execute(std::string query)
{
    PQclear(res);
    
    res = PQexec(conn, query.c_str());
    if (PQresultStatus(res) != PGRES_TUPLES_OK) 
    {
        std::cout << "QUERY failed!" << "\n";
        exit(0);
    }
}

std::vector<std::string> PostgreSQL::get_column_names()
{
    int ncols = PQnfields(res);
    std::vector<std::string> result;

    for (int i=0; i<ncols; i++) 
    {
        result.push_back( PQfname(res, i) );
    }

    return result;
}

void PostgreSQL::print_table()
{
    int rows = PQntuples(res);
    int cols = PQnfields(res);
    
    for(unsigned int i=0; i<rows; i++){

        for(unsigned int k=0; k<cols; k++)
            std::cout << PQgetvalue(res, i, k) << " ";
        
        std::cout << "\n";
    }
}
