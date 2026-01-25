CFLAGS = -Wall -Werror -g
CC = g++ -std=c++98
TARGET = main
FILES = Tape.cpp Brainhurt.cpp main.cpp testingFramework.cpp

coverage:
	g++ --coverage -c *.cpp

	g++ --coverage *.o -o main
	./main
	gcov -f -m -r -j $(FILES)

memoryCheck:
	valgrind -s --leak-check=full --track-origins=yes --keep-stacktraces=alloc-and-free ./main
compile:
	$(CC) $(CFLAGS) *.cpp -o $(TARGET)
run:
	./main

zipFile:
	zip u25026560.zip $(FILES) testingFramework.h
reset:
	rm -f  *.o *.gcov.json.gz *.gcda *.gcno main u25026560.zip
