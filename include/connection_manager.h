#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#pragma once

#include <map>

class Connections
{
private:
	std::map<std::string, std::map<std::string, std::string>> connections;

public:
	Connections();
	~Connections();
	
	void add_connection(std::string, std::string, std::string, std::string, std::string, std::string);
	void delete_connection(std::string);

	std::string get_connection_type(std::string);
	std::string get_connection_login(std::string);
	std::string get_connection_pasword(std::string);
	std::string get_connection_host(std::string);
	std::string get_connection_port(std::string);
};

#endif