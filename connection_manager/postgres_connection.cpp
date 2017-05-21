#include "postgres_connection.h"


Postgres_connection::Postgres_connection(std::string Host, std::string Port, std::string DB, std::string Login, std::string Password) : 
login(Login), password(Password), host(Host), port(Port), database(DB){}

Postgres_connection::~Postgres_connection()
{}

void Postgres_connection::open_connection()
{
    std::string conn_string = "user="+login+" password="+password+" dbname="+database+" host="+host+" port="+port;
    conn = PQconnectdb(conn_string.c_str());

    if (PQstatus(conn) == CONNECTION_BAD) 
    {
        std::cout << "We were unable to connect to the database." << "\n";
        std::cout << PQerrorMessage(conn) << "\n";
        
        exit(1);
    }
    return;
}

void Postgres_connection::close_connection()
{
    PQfinish(conn);
}

void Postgres_connection::execute(std::string query)
{
	open_connection();
	res = PQexec(conn, query.c_str());
	if (PQresultStatus(res) != PGRES_TUPLES_OK) 
    {
        std::cout << "QUERY failed!" << "\n";
        exit(1);
    }

	close_connection();
}

void Postgres_connection::print_table()
{
    int rows = PQntuples(res);
    int cols = PQnfields(res);
    
    for(unsigned int i=0; i<rows; i++){

        for(unsigned int k=0; k<cols; k++)
            std::cout << PQgetvalue(res, i, k) << " ";
        
        std::cout << "\n";
    }
}

std::vector<std::string> Postgres_connection::get_column_names()
{
    int ncols = PQnfields(res);
    std::vector<std::string> column_names;

    for (int i=0; i<ncols; i++) 
    {
        column_names.push_back( PQfname(res, i) );
    }

    return column_names;
}