main: QueryResponse.o BooleanElement.o CharacterElement.o Column.o IntegerElement.o RealElement.o TextElement.o BooleanColumn.o CharacterColumn.o Query.o IntegerColumn.o RealValueColumn.o TextColumn.o Database.o InsertQuery.o RemoveQuery.o SearchQuery.o UpdateQuery.o 
	g++ -g -std=c++98 -Wall -Werror QueryResponse.o BooleanElement.o CharacterElement.o Column.o IntegerElement.o RealElement.o TextElement.o BooleanColumn.o CharacterColumn.o Query.o IntegerColumn.o RealValueColumn.o TextColumn.o Database.o InsertQuery.o RemoveQuery.o SearchQuery.o UpdateQuery.o  main.cpp -o main

QueryResponse.o : QueryResponse.h QueryResponse.cpp 
	g++ -g -std=c++98 -Wall -Werror -c QueryResponse.cpp -o QueryResponse.o

BooleanElement.o : BooleanElement.h BooleanElement.cpp 
	g++ -g -std=c++98 -Wall -Werror -c BooleanElement.cpp -o BooleanElement.o

CharacterElement.o : CharacterElement.h CharacterElement.cpp 
	g++ -g -std=c++98 -Wall -Werror -c CharacterElement.cpp -o CharacterElement.o

Column.o : Column.h Column.cpp 
	g++ -g -std=c++98 -Wall -Werror -c Column.cpp -o Column.o

IntegerElement.o : IntegerElement.h IntegerElement.cpp 
	g++ -g -std=c++98 -Wall -Werror -c IntegerElement.cpp -o IntegerElement.o

RealElement.o : RealElement.h RealElement.cpp 
	g++ -g -std=c++98 -Wall -Werror -c RealElement.cpp -o RealElement.o

TextElement.o : TextElement.h TextElement.cpp 
	g++ -g -std=c++98 -Wall -Werror -c TextElement.cpp -o TextElement.o

BooleanColumn.o : BooleanColumn.h BooleanColumn.cpp Column.o BooleanElement.o 
	g++ -g -std=c++98 -Wall -Werror -c BooleanColumn.cpp -o BooleanColumn.o

CharacterColumn.o : CharacterColumn.h CharacterColumn.cpp Column.o CharacterElement.o 
	g++ -g -std=c++98 -Wall -Werror -c CharacterColumn.cpp -o CharacterColumn.o

Query.o : Query.h Query.cpp QueryResponse.o Column.o 
	g++ -g -std=c++98 -Wall -Werror -c Query.cpp -o Query.o

IntegerColumn.o : IntegerColumn.h IntegerColumn.cpp Column.o IntegerElement.o 
	g++ -g -std=c++98 -Wall -Werror -c IntegerColumn.cpp -o IntegerColumn.o

RealValueColumn.o : RealValueColumn.h RealValueColumn.cpp Column.o RealElement.o 
	g++ -g -std=c++98 -Wall -Werror -c RealValueColumn.cpp -o RealValueColumn.o

TextColumn.o : TextColumn.h TextColumn.cpp Column.o TextElement.o 
	g++ -g -std=c++98 -Wall -Werror -c TextColumn.cpp -o TextColumn.o

Database.o : Database.h Database.cpp Column.o Query.o QueryResponse.o 
	g++ -g -std=c++98 -Wall -Werror -c Database.cpp -o Database.o

InsertQuery.o : InsertQuery.h InsertQuery.cpp QueryResponse.o Query.o Database.o 
	g++ -g -std=c++98 -Wall -Werror -c InsertQuery.cpp -o InsertQuery.o

RemoveQuery.o : RemoveQuery.h RemoveQuery.cpp QueryResponse.o Query.o Database.o 
	g++ -g -std=c++98 -Wall -Werror -c RemoveQuery.cpp -o RemoveQuery.o

SearchQuery.o : SearchQuery.h SearchQuery.cpp QueryResponse.o Query.o Database.o 
	g++ -g -std=c++98 -Wall -Werror -c SearchQuery.cpp -o SearchQuery.o

UpdateQuery.o : UpdateQuery.h UpdateQuery.cpp QueryResponse.o Query.o Database.o 
	g++ -g -std=c++98 -Wall -Werror -c UpdateQuery.cpp -o UpdateQuery.o

clean:
	rm -f *.o main

run: main
	./main
mem:
	valgrind --leak-check=full ./main
