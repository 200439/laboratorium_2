__start__: program
	./program

program: tablica.o zegar.o main.o
	c++ main.o tablica.o zegar.o -o program

tablica.o: tablica.cpp
	c++ -c tablica.cpp -o tablica.o

zegar.o: zegar.cpp
	c++ -c zegar.cpp -o zegar.o

main.o: main.cpp
	c++ -c main.cpp -o main.o
