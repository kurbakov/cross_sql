#include "mysql.h"


MysqlConnection::MysqlConnection(std::string Host, std::string Port, std::string DB, std::string Login, std::string Password) : 
login(Login), password(Password), host(Host), port(Port), database(DB)
{
	// maping is mabe based on test. No literature found!
	data_types[3] = "INT";
	data_types[1] = "TINYINT";
	data_types[2] = "SMALLINT";
	data_types[9] = "MEDIUMINT";
	data_types[8] = "BIGINT";
	data_types[4] = "FLOAT";
	data_types[5] = "DOUBLE";
	data_types[246] = "DECIMAL";
	data_types[10] = "DATE";
	data_types[12] = "DATETIME";
	data_types[7] = "TIMESTAMP";
	data_types[11] = "TIME";
	data_types[13] = "YEAR";
	data_types[254] = "CHAR";
	data_types[253] = "VARCHAR";
	data_types[252] = "TEXT";
}

MysqlConnection::~MysqlConnection()
{
	mysql_free_result(res);
}

void MysqlConnection::open_connection()
{
	conn = mysql_init(NULL);
	
	if (conn == NULL)
	{
    	fprintf(stderr, "mysql_init() failed\n");
    	exit(1);
	}
	
	if (mysql_real_connect(conn, host.c_str(), login.c_str(), password.c_str(), database.c_str(), std::stoi(port), NULL, 0) == NULL) 
	{
    	fprintf(stderr, "%s\n", mysql_error(conn));
    	mysql_close(conn);
    	exit(1);
	} 
}

void MysqlConnection::close_connection()
{
	mysql_close(conn);
}

void MysqlConnection::execute(std::string query)
{
	// mysql_free_result(res);
	open_connection();

	if (mysql_query(conn, query.c_str())) 
	{
    	std::cout << "QUERY failed!" << "\n";
    	exit(0);
	}

	res = mysql_store_result(conn);
	n_cols = mysql_num_fields(res);
	n_rows = mysql_num_rows(res);

	close_connection();
}

MysqlIterator* MysqlConnection::createIterator() const
{
  return new MysqlIterator(this);
}


void MysqlConnection::make_ddl()
{
	MYSQL_FIELD *field;
	while((field = mysql_fetch_field(res)))
	{
		std::string filed_name = field->name;
		std::string field_type = data_types[field->type];
		std::pair<std::string, std::string> p = std::make_pair(filed_name, field_type);
		ddl.push_back(p);
	}
}

MysqlIterator::MysqlIterator(const MysqlConnection* mysql_connection)
{
  msql_conn = mysql_connection;
}

void MysqlIterator::first_row()
{
  row_index = 0;
  row = mysql_fetch_row(msql_conn->res);
}

void MysqlIterator::first_col()
{
  col_index = 0;
}

void MysqlIterator::next_row()
{
  row_index++;
  row = mysql_fetch_row(msql_conn->res);
}

void MysqlIterator::next_col()
{
  col_index++;
}

bool MysqlIterator::is_row_done()
{
  return msql_conn->n_rows > row_index;
}

bool MysqlIterator::is_col_done()
{
  return msql_conn->n_cols > col_index;
}

std::string MysqlIterator::get_current_value()
{
  return row[col_index];
}
