CC = g++
c11 = -std=c++11
EXE = ps4a

all:
	make $(EXE)
ps4a: ringbuffer.o test.o
	$(CC) ringbuffer.o test.o -o $(EXE) $(c11)
ringbuffer.o: ringbuffer.cpp ringbuffer.hpp
	$(CC) -c ringbuffer.cpp -o ringbuffer.o $(c11)
test.o: test.cpp ringbuffer.hpp
	$(CC) -c test.cpp -o test.o $(c11)
clean:
	\rm *.o $(EXE) *~
