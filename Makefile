all: main

main: main.o Operation.o pickfich.o Mat_aleatoire.o flots.o
	g++ -o test main.o Operation.o pickfich.o Mat_aleatoire.o flots.o
	
main.o: main.cpp Operation.h pickfich.h Mat_aleatoire.h flots.h
	g++ -o main.o -c main.cpp
 
Operation.o: Operation.cpp Operation.h
	g++ -o Operation.o -c Operation.cpp 
 
pickfich.o: pickfich.cpp pickfich.h
	g++ -o pickfich.o -c pickfich.cpp 

Mat_aleatoire.o: Mat_aleatoire.cpp Mat_aleatoire.h
	g++ -o Mat_aleatoire.o -c Mat_aleatoire.cpp 

flots.o: flots.cpp flots.h
	g++ -o flots.o -c flots.cpp 

clean:
	rm -rf *.o
 
mrproper: clean
	rm -rf test