.Phony: main model view controller clean

penguin_slide: main.o GameWorld.o Player.o GameWindow.o GameController.o
	g++ $(DEBUG) main.o GameWorld.o Player.o GameWindow.o GameController.o -o penguin_slide -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	g++ -c $(DEBUG) src/main.cpp

GameWorld.o Player.o: src/Model/*.cpp src/Model/*.hpp
	g++ -c $(DEBUG) src/Model/GameWorld.cpp src/Model/Player.cpp

GameWindow.o: src/View/*.cpp src/View/*.hpp
	g++ -c $(DEBUG) src/View/GameWindow.cpp

GameController.o: src/Controller/*.cpp src/Controller/*.hpp
	g++ -c $(DEBUG) src/Controller/GameController.cpp

clean:
	rm -rf penguin_slide
	rm -rf *.o	

debug: DEBUG = -g
debug: clean penguin_slide
