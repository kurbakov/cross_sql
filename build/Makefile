CXX=g++
CXXFLAGS=-Wall -std=c++14
CXXINCLUDE=-I/usr/local/Cellar/postgresql/9.6.2/include
CXXLINKING=-lpq

TARGET=../main
SOURCE=../main.cpp

all: main

main:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE) $(CXXINCLUDE) $(CXXLINKING)

clean:
	rm -f $(TARGET)

run:
	./$(TARGET)