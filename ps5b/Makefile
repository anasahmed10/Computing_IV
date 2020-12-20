GuitarHero: ringbuffer.o guitarstring.o main.o
	g++ -o guitarhero main.o guitarstring.o ringbuffer.o -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window

main.o: ringbuffer.hpp guitarstring.hpp main.cpp
	g++ -c main.cpp -ansi -pedantic -Wall -Werror

GuitarString.o: ringbuffer.hpp guitarstring.hpp guitarstring.cpp
	g++ -c guitarstring.cpp -ansi -pedantic -Wall -Werror

ringBuffer.o: ringbuffer.hpp ringbuffer.cpp
	g++ -c ringbuffer.cpp -ansi -pedantic -Wall -Werror

clean:
	rm -f *.o *~ GuitarHero
