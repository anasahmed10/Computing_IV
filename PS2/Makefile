CC = g++
CFLAGS = -c -g -Og _ Wall -Werror -ansi -pedantic
OBJ = main.o PTree.o
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = PTree

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

clean:
	rm $(OBJ) $(EXE)
