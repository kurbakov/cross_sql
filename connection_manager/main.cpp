#include <iostream>

#include "connection_manager.h"


int main(int argc, char **argv)
{
	std::string my_query1 = "select a, b, c from {query1}::main_table join {query2}::join_table on column1 == column2 OR column1 != column3 and column4 == column5";
	std::string my_query2 = "select column1, column2, column3 from {query for main table}::main_table join {query for join1}::join_table1 on column1 = join_column1 and column2 != join_column2 join {query for join2}::join_table2 on column1 = join_column3 or column2 > join_column4 where column1 = 'some value' and column2 != 'value' or column3 <= 10";

	Connection_manager* sql = new Connection_manager();

	sql->add_connection("name_postgres", "postgres", "127.0.0.1", "5432", "postgres", "LOGIN", "PASSWORD");
	sql->execute("name_postgres", "select * from test.test_table;");
	
	sql->add_connection("name_mysql", "mysql", "127.0.0.1", "3306", "test", "LOGIN", "PASSWORD");
	sql->execute("name_mysql", "select * from test_table;");
	
	sql->print_table("name_postgres");

	std::vector<std::string> v = sql->get_column_names("name_postgres");
	for(unsigned int i=0; i<v.size(); i++)
		std::cout << v[i] << "\n";

	sql->delete_connection("name_postgres");
	sql->delete_connection("name_mysql");
	
	delete sql;

	return 0;
}