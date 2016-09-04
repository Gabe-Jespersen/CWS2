CC = g++
CFLAGS = -g -std=c++11 -Wall
INSTALLPATH = ./
EXECUTABLE = cws2

all: cws2

cws2: main.o world.o person.o util.o
	$(CC) $(CFLAGS) main.o world.o person.o util.o -o $(EXECUTABLE)

main.o: main.cpp world.hpp
	$(CC) $(CFLAGS) -c main.cpp

world.o: world.cpp world.hpp
	$(CC) $(CFLAGS) -c world.cpp

person.o: person.cpp person.hpp util.hpp
	$(CC) $(CFLAGS) -c person.cpp

util.o: util.cpp util.hpp
	$(CC) $(CFLAGS) -c util.cpp


install:
	cp ./$(EXECUTABLE) $(INSTALLPATH)

uninstall:
	rm ./$(EXECUTABLE) $(INSTALLPATH)

clean:
	rm -rf *.o $(EXECUTABLE)
