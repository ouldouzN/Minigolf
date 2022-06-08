CC = g++ -std=c++11
CCFLAGS +=  -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
COMPILE_FLAGS = $(FLAGS) -c 

minigolf.out :main.o game.o ball.o map.o barrier.o rsdl.o
	$(CC) main.o game.o rsdl.o map.o barrier.o ball.o $(CCFLAGS) -o minigolf.out

main.o: rsdl.hpp main.cpp game.hpp map.hpp barrier.hpp ball.hpp
	$(CC) -c main.cpp -o main.o

game.o: rsdl.hpp game.hpp map.hpp ball.hpp barrier.hpp game.cpp 
	$(CC) -c game.cpp -o game.o

map.o: rsdl.hpp  map.hpp map.cpp
	$(CC) -c map.cpp -o map.o

barrier.o:rsdl.hpp map.hpp ball.hpp  barrier.hpp barrier.cpp
	$(CC) -c barrier.cpp -o barrier.o

ball.o: rsdl.hpp barrier.hpp map.hpp ball.hpp ball.cpp
	$(CC) -c ball.cpp -o ball.o

rsdl.o: rsdl.hpp rsdl.cpp
	$(CC) -c rsdl.cpp -o rsdl.o

.PHONY: clean
clean:
	rm -r *.o
