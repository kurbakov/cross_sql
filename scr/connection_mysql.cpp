#include "../include/connection_mysql.h"

MySQL::MySQL(std::string Host, std::string Port, std::string DB, std::string Login, std::string Password) : 
    login(Login), password(Password), host(Host), port(Port), database(DB)
{
}

MySQL::~MySQL()
{
}

void MySQL::open_connection()
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

void MySQL::close_connection()
{
	mysql_free_result(res);
	mysql_close(conn);
}

void MySQL::execute(std::string query)
{
	mysql_free_result(res);
	if (mysql_query(conn, query.c_str())) 
	{
    	std::cout << "QUERY failed!" << "\n";
    	exit(0);
	}

	res = mysql_store_result(conn);
}

std::vector<std::string> MySQL::get_column_names()
{
	std::vector<std::string> result;
	MYSQL_FIELD *field;
	while((field = mysql_fetch_field(res)))
	{
		result.push_back(field->name);
	}

	return result;
}

void MySQL::print_table()
{
	MYSQL_ROW row;
	int cols = mysql_num_fields(res);

	while ((row = mysql_fetch_row(res)))
	{
		for(int i = 0; i < cols; i++) 
			std::cout << row[i] << " ";
		
		std::cout << "\n";
	}
}

