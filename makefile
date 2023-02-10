#Name: Wyatt Haley
#Class: Data Structures
#File name: makefile

all: executable

executable: driver.o
	g++ driver.o -o executable 

driver.o: linkedlist.h
	g++ -c driver.cpp

clean:
	rm *.o executable
