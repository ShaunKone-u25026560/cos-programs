CFLAGS = -Wall -Werror -g
CC = g++ -std=c++98
TARGET = main
FILES = Arena.cpp Tile.cpp TileException.cpp Threat.cpp BoobyTrappedTile.cpp LethalTile.cpp EndTile.cpp Player.cpp Pacifist.cpp Villain.cpp main.cpp testingFramework.cpp

coverage:
	g++ --coverage -c *.cpp

	g++ --coverage *.o -o main
	./main
	gcov -f -m -r -j $(FILES)

memoryCheck:
	valgrind -s --leak-check=full --track-origins=yes --keep-stacktraces=alloc-and-free ./main
compile:
	$(CC) $(CFLAGS) *.cpp -o $(TARGET)
	./main
run:
	./main

zipFile:
	zip u25026560.zip $(FILES) testingFramework.h arena.txt
reset:
	rm -f  *.o *.gcov.json.gz *.gcda *.gcno main u25026560.zip
