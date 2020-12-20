CC = g++
CFLAGS = -g -Wall -Werror -std=c++11 -pedantic
BOOST = -lboost_unit_test_framework

all: ps6 mmtest

ps6: textGen.o model.o
	$(CC) textGen.o model.o -o ps6

mmtest: mmtest.o model.o
	$(CC) mmtest.o model.o -o mmtest $(BOOST)

TextGenerator.o: textGen.cpp model.hpp
	$(CC) -c textGen.cpp model.hpp $(CFLAGS)

MarkovModel.o: model.cpp model.hpp
	$(CC) -c model.cpp  model.hpp $(CFLAGS)

mmtest.o: mmtest.cpp
	$(CC) -c mmtest.cpp $(BOOST)

clean:
	rm *.o
	rm *~
	rm ps6
	rm mmtest
