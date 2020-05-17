prog2: main.cpp minmax.cpp minmax.h
	g++ -c minmax.cpp
	g++ -c main.cpp
	g++ minmax.o main.o -o prog2.out
