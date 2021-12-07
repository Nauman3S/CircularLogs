CC = gcc
FLAGS=-lncurses -Wall
install:
	sudo apt-get install libncurses5-dev libncursesw5-dev
all: 
	$(CC)  -o CircularLogs.o CircularLogs/CircularLogs.cpp $(FLAGS)
run: 
	./CircularLogs.o
clean:
	rm -rf CircularLogs.o