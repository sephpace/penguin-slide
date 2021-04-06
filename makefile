.Phony: all clean

all: penguin_slide

penguin_slide: src/main.o src/Model/GameWorld.o src/Model/Player.o src/View/GameWindow.o src/Controller/GameController.o
	g++ src/main.o src/Model/GameWorld.o src/Model/Player.o src/View/GameWindow.o src/Controller/GameController.o -o penguin_slide -lsfml-graphics -lsfml-window -lsfml-system

src/main.o: src/main.cpp
	g++ -c src/main.cpp -o src/main.o

model: src/Model/GameWorld.cpp src/Model/Player.cpp
	g++ -c src/Model/GameWorld.cpp src/Model/Player.cpp

view: src/View/GameWindow.cpp
	g++ -c src/View/GameWindow.cpp

controller: src/Controller/GameController.cpp
	g++ -c src/Controller/GameController.cpp

clean:
	rm -rf penguin_slide
	rm -rf src/main.o
	rm -rf src/Model/GameWorld.o
	rm -rf src/Model/Player.o
	rm -rf src/View/GameWindow.o
	rm -rf src/Controller/GameController.o
