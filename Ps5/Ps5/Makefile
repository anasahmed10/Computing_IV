CC = g++
SFML = -lsfml-system

all: ps5

ps5: main.o ed.o
	$(CC) main.o ed.o -o ps5 $(SFML)

main.o: main.cpp ed.hpp
	$(CC) -c main.cpp ed.hpp

ed.o: ed.cpp ed.hpp
	$(CC) -c ed.cpp ed.hpp

clean:
	rm *.o
	rm *~
	rm ps5
