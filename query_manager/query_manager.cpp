#include "query_manager.h"

QueryManager::QueryManager()
{
    _raw_data = new std::string;
    _queries = new std::map<std::string, std::string>;
}

QueryManager::~QueryManager()
{
    delete _raw_data;
    delete _queries;
}

bool QueryManager::parse(std::string input)
{
    _raw_data->assign( input );
    std::transform(_raw_data->begin(), _raw_data->end(), _raw_data->begin(), ::tolower);

    set_queries();
    clean_string();

    return true;
}

std::string* QueryManager::get_raw_query()
{
    return _raw_data;
}

std::map<std::string, std::string>* QueryManager::get_queries() {
    return _queries;
}

void QueryManager::set_queries()
{
    std::vector<unsigned int> query_start;
    std::vector<unsigned int> query_end;

    std::vector<unsigned int> connection_name_start;
    std::vector<unsigned int> connection_name_end;

    for (unsigned int i = 0; i < _raw_data->length(); i++)
    {
        if (_raw_data->at(i) == '{'){
            query_start.push_back(i + 1);
            while(_raw_data->at(i) != '}' && i<_raw_data->length()) i++;

            query_end.push_back(i);
            connection_name_start.push_back(i+3); // '}::' 3 chars before the connection name

            while(_raw_data->at(i) != ' ' && i<_raw_data->length()) i++;

            connection_name_end.push_back(i);
        }
    }

    // populate queries map <connection_name, query2run>
    for (unsigned int i = 0; i < query_end.size(); i++)
    {
        _queries->insert(std::pair<std::string, std::string>(
                _raw_data->substr(connection_name_start[i], connection_name_end[i] - connection_name_start[i]),
                _raw_data->substr(query_start[i], query_end[i] - query_start[i])));
    }

    return;
}

void QueryManager::clean_string()
{
    std::vector<unsigned int> start;
    std::vector<unsigned int> end;
    for(unsigned int i=0; i < _raw_data->size(); i++)
    {
        if(_raw_data->at(i) == '{' && i<_raw_data->length()) {
            start.push_back(i);

            while (_raw_data->at(i) != '}' && i<_raw_data->length()) i++;
            end.push_back(i);
        }
    }
    while(!start.empty() && !end.empty())
    {
        _raw_data->erase(start.back(), end.back()-start.back()+3);

        start.pop_back();
        end.pop_back();
    }
}
