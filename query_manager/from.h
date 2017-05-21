#ifndef FROM_H
#define FROM_H

#pragma once

#include <string>

class From{
public:
	From();
	~From();

	size_t parse(std::string);
	std::string* get_from_table();

private:
	std::string* from_table;
};


#endif // FROM_H