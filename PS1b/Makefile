CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
SFML = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
ALLOBJ = fiblsfr.o PhotoMagic.o
EXE = ps1a PhotoMagic

all: PhotoMagic

PhotoMagic: PhotoMagic.o
	$(CC) -Wall PhotoMagic.o  -o PhotoMagic $(SFML)
ps1a: fiblsfr.o
	$(CC) fiblsfr.cpp -c fiblsfr.o -o ps1a
clean:
	\rm *.o *~ $(EXE) output-file.png
