CC = g++
c11 = -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:
	make ps4b
ps4b: ringbuffer.o stringsound.o guitarsim.o 
	$(CC) ringbuffer.o stringsound.o guitarsim.o -o ps4b $(SFML) $(c11)
guitarsim.o: guitarsim.cpp stringsound.hpp
	$(CC) -c guitarsim.cpp -o guitarsim.o $(SFML) $(c11)
stringsound.o:
	$(CC) -c stringsound.cpp -o stringsound.o $(c11)
ps4a: ringbuffer.o test.o
	$(CC) ringbuffer.o test.o -o ps4a $(c11)
ringbuffer.o: ringbuffer.cpp ringbuffer.hpp
	$(CC) -c ringbuffer.cpp -o ringbuffer.o $(c11)
test.o: test.cpp ringbuffer.hpp
	$(CC) -c test.cpp -o test.o $(c11)
clean:
	\rm *.o $(EXE) *~
