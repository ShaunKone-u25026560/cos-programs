main: ROBOTS.o main.o
	g++ ROBOTS.o main.o -o main

ROBOTS.o: ROBOTS.cpp ROBOTS.h
	g++ -c ROBOTS.cpp

main.o: main.cpp ROBOTS.h
	g++ -c main.cpp

clean:
	rm -f main *.o
