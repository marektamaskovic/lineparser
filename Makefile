CXX=g++
CXXFLAGS= -Wall -Wextra -pedantic -std=c++11
OBJECTS= ConfigParser.o main.o
EXEC=lineparser

all: $(OBJECTS)
	$(CXX) $(CXXFLAGSX) $^ -o $(EXEC)
clean:
	rm *.o
