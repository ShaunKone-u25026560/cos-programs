# u25026560
CFLAGS = -Wall -Werror -g
CC = g++ -std=c++11
TARGET = main
FILES = main.cpp ConcurrentSorting.cpp
OBJECTS = ConcurrentSorting.o main.o

# Linking all the object code
all: $(OBJECTS)
	$(CC) $(CFLAGS) *.cpp -o $(TARGET)

# Dependencies
ConcurrentSorting.o: ConcurrentSorting.h
main.o: ConcurrentSorting.h

%.o: %.cpp
	$(CC) $< $(CFLAGS) -c -o $@

run:
	./$(TARGET)

coverage:
	g++ --coverage -c *.cpp
	g++ --coverage *.o -o $(TARGET)
	./$(TARGET)
	gcov -f -m -r -j $(FILES)

memoryCheck:
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --keep-stacktraces=alloc-and-free ./$(TARGET) $(TASKNO)

zipFile:
	zip u25026560.zip $(FILES) ConcurrentSorting.h makefile

clean:
	rm -f $(OBJECTS) $(TARGET) *.gcov.json.gz *.gcda *.gcno u25026560.zip
