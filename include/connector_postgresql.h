#include <vector>
#include <list>

#include <libpq-fe.h>
// http://zetcode.com/db/postgresqlc/

namespace CROSS{

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

	public:
		Postgres(char*, char*, char*, char*, char*);
		~Postgres();

		void open_connection();
		void close_connection();

		void execute(char*);

		std::vector<char*> get_column_names();
		std::list<std::vector<char*> > get_rows(int n);
	};
	
} // close namespace CROSS




