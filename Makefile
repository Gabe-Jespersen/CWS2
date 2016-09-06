CC = g++
CFLAGS = -pg -std=c++11 -Wall -lncurses -pthread
INSTALLPATH = ./
EXECUTABLE = cws2

all: cws2

cws2: main.o person.o util.o tribe.o
	$(CC) $(CFLAGS) main.o person.o util.o tribe.o -o $(EXECUTABLE)

main.o: main.cpp tribe.hpp
	$(CC) $(CFLAGS) -c main.cpp

person.o: person.cpp person.hpp util.hpp
	$(CC) $(CFLAGS) -c person.cpp

util.o: util.cpp util.hpp
	$(CC) $(CFLAGS) -c util.cpp

tribe.o: tribe.cpp tribe.hpp util.hpp person.hpp
	$(CC) $(CFLAGS) -c tribe.cpp


install:
	cp ./$(EXECUTABLE) $(INSTALLPATH)

uninstall:
	rm ./$(EXECUTABLE) $(INSTALLPATH)

clean:
	rm -rf *.o $(EXECUTABLE)
