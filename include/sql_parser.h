namesapce CROSS{
	class Sql_parser
	{
	private:
		std::map<char*, char*>* queries;
		std::map<char*, std::list<char*>>* select_keys; // connection - keys
		char* from_key;
		/* where conditions, join conditions */

	public:
		Sql_parser(char*);
		~Sql_parser();

		std::map<char* std::map<char*, char*> >* get_queries();
		
	};
}