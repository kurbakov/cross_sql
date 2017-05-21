CC					=	g++
CFLAGS				=	-Wall -std=c++14


SOURCES				=	main.cpp select.cpp query_manager.cpp from.cpp
OBJECTS				=	$(SOURCES:.cpp=.o)

EXECUTABLE			=	main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ 

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

select.o: select.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

query_manager.o: query_manager.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

from.o: from.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f *.o $(EXECUTABLE)