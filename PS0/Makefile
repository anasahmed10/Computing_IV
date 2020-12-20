CC = g++
CFLAGS = -c -g -Og _ Wall -Werror -ansi -pedantic
OBJ = main.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system
EXE = ps0

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(SFML)

clean:
	rm $(OBJ) $(EXE)
