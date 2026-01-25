# u25026560
CFLAGS = -Wall -Werror -g
CC = g++ -std=c++11
TARGET = main
FILES = main.cpp Matrix.cpp task1_processes.cpp task1_threads.cpp task1_printstatus.cpp
OBJECTS = Matrix.o task1_processes.o task1_threads.o task1_printstatus.o main.o
TASKNO = 2 # The task number to run in the "main" function in main.cpp Either 1 or 2

# Linking all the object code
all: $(OBJECTS)
	$(CC) $(CFLAGS) *.cpp -o $(TARGET)

# Dependencies
Matrix.o: Matrix.h
task1_processes.o: Matrix.h
task1_threads.o: Matrix.h
task1_printstatus.o: Matrix.h

%.o: %.cpp
	$(CC) $< $(CFLAGS) -c -o $@

run:
	./$(TARGET) $(TASKNO)

coverage:
	g++ --coverage -c *.cpp
	g++ --coverage *.o -o $(TARGET)
	./$(TARGET) $(TASKNO)
	gcov -f -m -r -j $(FILES)

memoryCheck:
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --keep-stacktraces=alloc-and-free ./$(TARGET) $(TASKNO)

zipFile:
	zip u25026560.zip $(FILES) Matrix.h matrix1A.txt matrix2A.txt makefile

clean:
	rm -f $(OBJECTS) $(TARGET) *.gcov.json.gz *.gcda *.gcno u25026560.zip

