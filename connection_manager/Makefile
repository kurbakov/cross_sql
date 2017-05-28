CC					=	g++
CFLAGS				=	-Wall -std=c++14

MSQL_INCLUDES		=	`mysql_config --cflags --libs`
PSQL_INCLUDES		=	-I/usr/local/Cellar/postgresql/9.6.2/include
PSQL_LIBS			=	-lpq

SOURCES				=	main.cpp mysql_connection.cpp postgres.cpp connection_manager.cpp
OBJECTS				=	$(SOURCES:.cpp=.o)

EXECUTABLE			=	main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(MSQL_INCLUDES) $(PSQL_INCLUDES) $(OBJECTS) -o $@ $(PSQL_LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) $(MSQL_INCLUDES) $(PSQL_INCLUDES) -c $< -o $@

mysql_connection.o: mysql_connection.cpp
	$(CC) $(CFLAGS) $(MSQL_INCLUDES) -c $< -o $@

postgres.o: postgres.cpp
	$(CC) $(CFLAGS) $(PSQL_INCLUDES) -c $< -o $@ $(PSQL_LIBS)

connection_manager.o: connection_manager.cpp
	$(CC) $(CFLAGS) $(MSQL_INCLUDES) -c $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)