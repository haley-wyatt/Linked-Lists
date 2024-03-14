#Name: Wyatt Haley
#Class: Data Structures
#File name: makefile

CXX = g++
CFLAGS = -Wall -Werror
SRC = driver.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = listinterface.h linkedlist.h node.h

.PHONY: all clean

all: executable

executable: $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) executable
