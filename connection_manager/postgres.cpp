#include "postgres.h"

PostgresConnection::PostgresConnection(std::string Host, std::string Port, std::string DB, std::string Login, std::string Password) :
	login(Login), password(Password), host(Host), port(Port), database(DB)
	{
		open_connection();
		res = PQexec(conn, "select OID, typname from pg_type;");
		int n = PQntuples(res);
		for(unsigned int i=0; i<n; i++ )
		{
			int id = std::atoi( PQgetvalue(res, i, 0) );
			std::string data_type = PQgetvalue(res, i, 1);

			data_types[id] = data_type;
		}
	}

PostgresConnection::~PostgresConnection(){}

void PostgresConnection::open_connection()
{
  std::string conn_string = "user="+login+" password="+password+" dbname="+database+" host="+host+" port="+port;
  conn = PQconnectdb(conn_string.c_str());
  if (PQstatus(conn) == CONNECTION_BAD){std::cout << PQerrorMessage(conn) << "\n";}
}

void PostgresConnection::close_connection()
{
  PQfinish(conn);
}

void PostgresConnection::execute(std::string query)
{
	open_connection();
	res = PQexec(conn, query.c_str());
	if (PQresultStatus(res) != PGRES_TUPLES_OK){std::cout << "QUERY failed!" << "\n";}
	close_connection();

	n_rows = PQntuples(res);
	n_cols = PQnfields(res);
}

PostgresIterator* PostgresConnection::createIterator() const
{
  return new PostgresIterator(this);
}

void PostgresConnection::make_ddl()
{
	for(unsigned int i=0; i<n_cols; i++)
	{
		std::pair<std::string, std::string> p = std::make_pair(PQfname(res, i), data_types[(int) PQftype(res, i)]);
		ddl.push_back(p);
	}
}

std::string PostgresConnection::get_value(int row_index, int col_index) const
{
  return PQgetvalue(res, row_index, col_index);
}

PostgresIterator::PostgresIterator(const PostgresConnection* postgres_connection)
{
  psql_conn = postgres_connection;
}

void PostgresIterator::first_row()
{
  row_index = 0;
}

void PostgresIterator::first_col()
{
  col_index = 0;
}

void PostgresIterator::set_row(int idx)
{
  row_index = idx;
}

void PostgresIterator::set_col(int idx)
{
  col_index = idx;
}

void PostgresIterator::next_row()
{
  row_index++;
}

void PostgresIterator::next_col()
{
  col_index++;
}

bool PostgresIterator::is_row_done()
{
  return psql_conn->n_rows > row_index;
}

bool PostgresIterator::is_col_done()
{
  return psql_conn->n_cols > col_index;
}

std::string PostgresIterator::get_current_value()
{
  return psql_conn->get_value(row_index, col_index);
}
