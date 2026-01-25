CFLAGS = -Werror -Wall
CC = g++ -g -std=c++98
TARGET = main
FILES = Exception.cpp InvalidIndexException.cpp InvalidSizeException.cpp ElementNotInListException.cpp \
	OutOfBoundsException.cpp TooManyPrintersDeleted.cpp PrinterNotInitialized.cpp Array.cpp List.cpp \
	DLList.cpp Stack.cpp Queue.cpp Iterator.cpp Printer.cpp main.cpp testingFramework.cpp
HFILES = Exception.h InvalidIndexException.h InvalidSizeException.h ElementNotInListException.h \
	OutOfBoundsException.h TooManyPrintersDeleted.h PrinterNotInitialized.h Array.h List.h DLList.h \
	Stack.h Queue.h Iterator.h Printer.h

main:
	$(CC) $(CFLAGS) Exception.cpp InvalidIndexException.cpp InvalidSizeException.cpp \
	ElementNotInListException.cpp  OutOfBoundsException.cpp TooManyPrintersDeleted.cpp \
	PrinterNotInitialized.cpp testingFramework.cpp main.cpp -o $(TARGET)

coverage:
	g++ --coverage -c Exception.cpp
	g++ --coverage -c ElementNotInListException.cpp
	g++ --coverage -c InvalidIndexException.cpp
	g++ --coverage -c InvalidSizeException.cpp
	g++ --coverage -c OutOfBoundsException.cpp
	g++ --coverage -c PrinterNotInitialized.cpp
	g++ --coverage -c TooManyPrintersDeleted.cpp
	g++ --coverage -c main.cpp
	g++ --coverage -c testingFramework.cpp

	g++ --coverage *.o -o $(TARGET)
	./$(TARGET)
	gcov -f -m -r -j $(FILES)

memoryCheck:
	valgrind -s --leak-check=full --track-origins=yes --keep-stacktraces=alloc-and-free ./$(TARGET)

compile:
	$(CC) $(CFLAGS) *.cpp -o $(TARGET)
	./main

zipFile:
	zip u25026560.zip $(FILES) testingFramework.h test.txt

reset:
	rm -f  *.o *.gcov.json.gz *.gcda *.gcno main u25026560.zip

run:
	./main

retry:
	@clear
	@make reset
	@make main
	@make memoryCheck
