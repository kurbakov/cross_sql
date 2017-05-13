#include "../include/connection_manager.h"

Connections::Connections(){}
Connections::~Connections(){}

void Connections::add_connection(std::string name, std::string type, std::string host, std::string port, std::string login, std::string pass)
{
	std::map<std::string, std::string> conn;
	conn["type"] = type;
	conn["host"] = host;
	conn["port"] = port;
	conn["login"] = login;
	conn["pass"] = pass;

	connections[name] = conn;
	return;
}

void Connections::delete_connection(std::string connection_name)
{
	std::map<std::string, std::map<std::string,std::string> >::iterator it;
	it = connections.find(connection_name);

	if(it != connections.end())
		connections.erase(it);
}

std::string Connections::get_connection_type(std::string name)
{
	if(connections.find(name) != connections.end())
		return connections[name]["type"];
	else
		return "BAD_CONNECTION";
}

std::string Connections::get_connection_login(std::string name)
{
	if(connections.find(name) != connections.end())
		return connections[name]["login"];
	else
		return "BAD_CONNECTION";
}

std::string Connections::get_connection_pasword(std::string name)
{
	if(connections.find(name) != connections.end())
		return connections[name]["pass"];
	else
		return "BAD_CONNECTION";
}

std::string Connections::get_connection_host(std::string name)
{
	if(connections.find(name) != connections.end())
		return connections[name]["host"];
	else
		return "BAD_CONNECTION";
}

std::string Connections::get_connection_port(std::string name)
{
	if(connections.find(name) != connections.end())
		return connections[name]["port"];
	else
		return "BAD_CONNECTION";
}
