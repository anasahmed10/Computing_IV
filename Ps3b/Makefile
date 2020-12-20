CC= g++
CFLAGS= -Wall -Werror -ansi -pedantic
GFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
c11 = -std=c++11

all:	
	make NBody
NBody: body.o main.o
	g++ body.o main.o -o NBody $(GFLAGS) $(c11)
body.o: body.cpp body.hpp 
	g++ -c body.cpp -o body.o $(CFLAGS) $(c11)
main.o: main.cpp body.hpp
	g++ -c main.cpp -o main.o $(CFLAGS) $(c11)
clean:
	rm *.o *NBody *~ 
