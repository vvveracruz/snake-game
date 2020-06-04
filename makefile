SOURCES = src/main.cpp src/game.cpp
OBJECTS = $(SOURCES:.c=.o)

run:
	g++ -c $(SOURCES) -Iinclude
	g++ $(OBJECTS) -o sfml-app -Llib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=lib && ./sfml-app

.PHONY: clean

clean:
	rm sfml-app
	rm *.o
