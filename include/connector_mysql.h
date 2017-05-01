#include <vector>
#include <list>

#include <sqlite3.h>
https://dev.mysql.com/doc/connector-cpp/en/connector-cpp-examples-complete-example-1.html

namespace CROSS{
	class Mysql
	{
	private:
		MYSQL *conn;
		MYSQL_RES *res;

	public:
		Mysql();
		~Mysql();

		void open_connection();
		void close_connection();

		void execute(char*);

		std::vector<char*> get_column_names();
		std::list<std::vector<char*> > get_rows(int n);
		
	};
}