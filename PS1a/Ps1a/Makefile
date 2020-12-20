CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
ALLOBJ = fiblsfr.o 
EXE = ps1a test

all: $(ALLOBJ)
	$(CC) $(ALLOBJ) -o ps1a
test: test.o
	$(CC) -o test test.cpp
clean:
	\rm *.o $(EXE)
