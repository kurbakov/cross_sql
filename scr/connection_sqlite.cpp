#include "../include/connection_sqlite.h"

SQLite::SQLite(std::string DB) : 
	database(DB)
{
}

SQLite::~SQLite()
{
}

void SQLite::open_connection()
{
	rc = sqlite3_open(database.c_str(), &conn);
	
	if (rc != SQLITE_OK) {    
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(conn));
		sqlite3_close(conn);
        exit(0);
    }
}

void SQLite::close_connection()
{
	sqlite3_free(err_msg);
	sqlite3_finalize(res);
	sqlite3_close(conn);
}


void SQLite::execute(std::string query)
{
    if(sqlite3_prepare_v2(conn, query.c_str(), -1, &res, 0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(res);
        int result = 0;

        while(true)
        {
            result = sqlite3_step(res);
            
            if(result == SQLITE_ROW)
            {
                std::vector<std::string> values;
                for(int col = 0; col < cols; col++)
                    values.push_back((char*)sqlite3_column_text(res, col));

                data.push_back(values);
            }
            else
                break;
        }
    }

    return;
}

std::vector<std::string> SQLite::get_column_names()
{
    std::vector<std::string> result;
    int cols = sqlite3_column_count(res);

    for (int i = 0; i < cols; ++i)
    {
        result.push_back( (char*)sqlite3_column_name(res, i) );
    }
    return result;
}

void SQLite::print_table()
{
    for (int i = 0; i < data.size(); ++i)
    {
        for (int k = 0; k < data[i].size(); ++k)
            std::cout << data[i][k] << " ";
        
        std::cout << "\n";
    }
}

