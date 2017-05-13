#include "../include/parser.h"

Parser::Parser(std::string input)
{
    _raw_data = input;
    std::transform(_raw_data.begin(), _raw_data.end(), _raw_data.begin(), ::tolower);

    set_queries();
    set_select_columns();
    set_from();
    set_join();
    set_where();
}

Parser::~Parser()
{
}

void Parser::clean_string()
{
    std::vector<unsigned int> start;
    std::vector<unsigned int> end;
    for(unsigned int i=0; i < _raw_data.size(); i++)
    {
        if(_raw_data[i] == '{')
            start.push_back(i);

        if(_raw_data[i] == '}')
            end.push_back(i);
    }
    while(!start.empty() && !end.empty())
    {
        _raw_data.erase(start.back(), end.back()-start.back()+3);

        start.pop_back();
        end.pop_back();
    }
}

void Parser::set_queries()
{
    std::vector<unsigned int> query_start;
    std::vector<unsigned int> query_end;

    std::vector<unsigned int> connection_name_start;
    std::vector<unsigned int> connection_name_end;

    for (unsigned int i = 0; i < _raw_data.length(); i++)
    {
        if (_raw_data[i] == '{')
            query_start.push_back(i + 1);

        else if (_raw_data[i] == '}')
        {
            query_end.push_back(i);
            connection_name_start.push_back(i+3); // '}::' 3 chars before the connection name

            while(_raw_data[i] != ' ' && i<_raw_data.length()) i++;

            connection_name_end.push_back(i);
        }
    }

    // populate queries map <connection_name, query2run>
    for (unsigned int i = 0; i < query_end.size(); i++)
    {
        _queries.insert(std::pair<std::string, std::string>(
                _raw_data.substr(connection_name_start[i], connection_name_end[i] - connection_name_start[i]),
                _raw_data.substr(query_start[i], query_end[i] - query_start[i])));
    }

    clean_string();

    return;
}

void Parser::set_select_columns()
{
    std::size_t select_index = _raw_data.find("select ");
    std::size_t from_index = _raw_data.find(" from ");

    std::string select_string = _raw_data.substr(select_index+7, from_index-select_index-7); // 'SELECT ' -> 7  chars before the connection name
    select_string.erase(std::remove_if(select_string.begin(), select_string.end(), isspace), select_string.end());

    std::stringstream ss(select_string);
    std::string temp;

    while(std::getline(ss, temp, ','))
        _select_columns.push_back(temp);

    return;
}

void Parser::set_from()
{
    size_t from_index = _raw_data.find("from")+5;
    int idx = from_index;
    while(_raw_data[idx] != ' ' && idx < _raw_data.size()) idx++;

    _main_table = _raw_data.substr(from_index, idx-from_index);
    return;
}

void Parser::set_join()
{
    std::vector<int> join_start;
    for(int i=0; i<_raw_data.size()-6; i++)
    {
        if(_raw_data.substr(i, 6).compare(" join ") == 0)
            join_start.push_back(i);
    }
    for(unsigned int i=0; i<join_start.size()-1; i++)
    {
        join.push_back(_raw_data.substr(join_start[i]+1, join_start[i+1]-join_start[i]-1));
    }

    if(join_start.size()>=1)
    {
        int last_join_start = join_start.back();
        int last_join_end = last_join_start;
        if(_raw_data.find(" where ") == -1)
        {
            join.push_back(_raw_data.substr(last_join_start + 1));
        }
        else
        {
            while (_raw_data.substr(last_join_end, 7).compare(" where ") != 0 && last_join_end < _raw_data.size() - 7)
                last_join_end++;

            join.push_back(_raw_data.substr(last_join_start + 1, last_join_end - last_join_start));
        }
    }

    return;
}

void Parser::set_where()
{
    int from_index = _raw_data.find(" where ");

    if(from_index == -1)
        return;
    else
        from_index += 7;

    where.push_back( _raw_data.substr(from_index) );
    return;
}
