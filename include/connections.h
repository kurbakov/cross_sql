
namesapce CROSS{

	enum ConnType {MySQL, PostgreSQL, SQLite}

	class Connections
	{
	private:
		std::map<char*, char*>* connection;
		std::map<char* std::map<char*, char*> >* saved_connections;

	public:
		Connections();
		~Connections();

		void create_connection();
		void save_connection();
		void delete_connection(char*);
		
		void set_connection_name(char*);
		void set_connection_type(ConnType);
		void set_host(char*)
		void set_port(char*);
		void set_login(char*);
		void set_pass(char*);

		ConnType get_connection_type(char*);
		char* get_host(char*)
		char* get_port(char*);
		char* get_login(char*);
		char* get_pass(char*);

	};
}