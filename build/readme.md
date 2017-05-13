current dependencies:
- Qt as the main Framework

MySQL:  
CXXINCLUDE=`mysql_config --cflags --libs`

PostgreSQL:  
CXXINCLUDE=-I/usr/local/Cellar/postgresql/9.6.2/include  
CXXLINKING=-lpq

SQLite:  
CXXLINKING=-lsqlite3
