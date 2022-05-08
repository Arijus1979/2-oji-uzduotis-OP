run: main.o 1strategija.o 2strategija.o
	g++ -o programa.exe main.o 1strategija.o 2strategija.o -O3

1strategija.o: 1strategija.cpp Strukturos.h
	g++ -c 1strategija.cpp

2strategija.o: 2strategija.cpp Strukturos.h
	g++ -c 2strategija.cpp 

main.o: main.cpp Strukturos.h
	g++ -c main.cpp 

clean:
	del *.o
