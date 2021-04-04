.Phony: all clean

all: penguin_slide

penguin_slide: src/main.o src/view.o
	g++ src/main.o src/view.o -o penguin_slide -lsfml-graphics -lsfml-window -lsfml-system

src/main.o: src/main.cpp
	g++ -c src/main.cpp -o src/main.o

src/view.o: src/View/GameWindow.cpp
	g++ -c src/View/GameWindow.cpp -o src/view.o 

clean:
	rm -rf penguin_slide
	rm -rf src/main.o
	rm -rf src/view.o
