CFLAGS = -Wall -Werror -g
CC = g++
TARGET = main
FILES = Operator.cpp PlusOperator.cpp MinusOperator.cpp MultiplyOperator.cpp Calculator.cpp main.cpp

coverage:
	g++ --coverage -c main.cpp
	g++ --coverage -c testingFramework.cpp

	g++ --coverage *.o -o $(TARGET)
	./$(TARGET)
	gcov -f -m -r -j $(FILES)

memoryCheck:
	valgrind -s --leak-check=full --track-origins=yes --keep-stacktraces=alloc-and-free ./main

$(TARGET):
	$(CC) $(CFLAGS) main.cpp -o $(TARGET)

run:
	./$(TARGET)

zipFile:
	zip u25026560.zip $(FILES)
reset:
	rm -f  *.o *.gcov.json.gz *.gcda *.gcno main u25026560.zip
