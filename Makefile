OBJS = main.cpp Ship.cpp Bullet.cpp Alien.cpp AlienSquad.cpp

CC = g++
COMPILER_FLAGS = -w -std=c++17 -Iheaders/

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2pp

OBJ_NAME = game.out

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
