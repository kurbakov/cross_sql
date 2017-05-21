#include "connection_manager.h"


Connection_manager::Connection_manager(){}

Connection_manager::~Connection_manager()
{
	for (auto it=connection_pool.begin(); it!=connection_pool.end(); ++it)
		delete it->second;
}

bool Connection_manager::add_connection(std::string name, std::string type, std::string host, std::string port, std::string db, std::string login, std::string password)
{
	if(name.empty() || name.length() == 0)
		return false;
	
	if(type.compare("mysql") == 0)
		connection_pool[name] = new Mysql_connection(host, port, db, login, password);

	else if(type.compare("postgres") == 0)
		connection_pool[name] = new Postgres_connection(host, port, db, login, password);

	else
		return false;

	return true;
}

bool Connection_manager::delete_connection(std::string connection_name)
{
	std::map<std::string, Connection*>::iterator it;
	it = connection_pool.find(connection_name);

	if(it != connection_pool.end())
	{
		delete it->second;
		connection_pool.erase(it);

		return true;
	}

	return false;
}

bool Connection_manager::execute(std::string name, std::string query)
{
	std::map<std::string, Connection*>::iterator it;
	it = connection_pool.find(name);

	if(it!=connection_pool.end())
		it->second->execute(query);
	else
		return false;

	return true;
}

bool Connection_manager::print_table(std::string name)
{
	std::map<std::string, Connection*>::iterator it;
	it = connection_pool.find(name);

	if(it!=connection_pool.end())
		it->second->print_table();
	else
		return false;

	return true;
}

std::vector<std::string> Connection_manager::get_column_names(std::string name)
{
	std::vector<std::string> column_names;

	std::map<std::string, Connection*>::iterator it;
	it = connection_pool.find(name);

	if(it!=connection_pool.end())
		column_names = it->second->get_column_names();
	
	return column_names;
}
