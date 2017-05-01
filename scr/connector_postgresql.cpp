#include <../include/connector_postgresql.h>

namespace CROSS{

	Postgres::Postgres(char* Login, char* Password, char* Host, char* Port, char* Database)
	{
		login = Login;
		password = Password;
		host = Host;
		port = Port;
		database = Database;
	}

	Postgres::~Postgres(){}

	void Postgres::open_connection(){}
	void Postgres::close_connection(){}

	void Postgres::execute(char* query){}

	std::vector<char*> Postgres::get_column_names();	
	std::list<std::vector<char*> > Postgres::get_rows(int n);

} // close namespace CROSS