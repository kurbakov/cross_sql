#include <stdio.h>
#include <libpq-fe.h>


namespace project_z{

	// Class to connect to postgres and run a query
	class Postgres
	{
	private:
		PGconn* conn;
		PGresult* res;

		char* login;
		char* password;
		char* host;
		char* port;
		char* database;

		void clear_result();
		bool is_connection_open();

	public:
		Postgres(char*, char*, char*, char*, char*);
		~Postgres();

		void open_connection();
		void close_connection();

		void execute(char*);

		void help_function();
	};

	// delete it later
	void Postgres::help_function()
	{
		std::cout << login << '\n';
	}

	Postgres::Postgres(char* Login, char* Password, char* Host, char* Port, char* Database)
	{
		login = Login;
		password = Password;
		host = Host;
		port = Port;
		database = Database;
	}

	Postgres::~Postgres(){}

	void Postgres::clear_result(){}
	bool Postgres::is_connection_open()
	{
		return true;
	}

	void Postgres::open_connection(){}
	void Postgres::close_connection(){}

	void Postgres::execute(char* query){}


} // close namespace project_z




