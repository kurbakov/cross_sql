#include <vector>
#include <list>

#include <sqlite3.h>
// http://zetcode.com/db/sqlitec/

namespace CROSS{
	class Sqlite
	{
	private:
		sqlite3 *conn;
		sqlite3_stmt *res;

	public:
		Sqlite();
		~Sqlite();

		void open_connection();
		void close_connection();

		void execute(char*);

		std::vector<char*> get_column_names();
		std::list<std::vector<char*> > get_rows(int n);
		
	};
}