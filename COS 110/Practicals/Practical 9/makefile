CFLAGS = -Wall -Werror -g
CC = g++
TARGET = main
FILES = CircularList.cpp main.cpp testingFramework.cpp

coverage:
	g++ --coverage -c main.cpp
	g++ --coverage -c testingFramework.cpp

	g++ --coverage *.o -o $(TARGET)
	./$(TARGET)
	gcov -f -m -r -j $(FILES)

memoryCheck:
	valgrind -s --leak-check=full --track-origins=yes --keep-stacktraces=alloc-and-free ./main

$(TARGET): main.o testingFramework.o
	$(CC) $(CFLAGS) main.o testingFramework.o -o $(TARGET)

main.o: main.cpp testingFramework.h
	$(CC) $(CFLAGS) -c main.cpp

testingFramework.o: testingFramework.cpp testingFramework.h CircularList.h
	$(CC) $(CFLAGS) -c testingFramework.cpp

run:
	./$(TARGET)

zipFile:
	zip u25026560.zip $(FILES) testingFramework.h
reset:
	rm -f  *.o *.gcov.json.gz *.gcda *.gcno main u25026560.zip
