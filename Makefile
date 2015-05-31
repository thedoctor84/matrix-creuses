all: matCreuse testMatCreuse

testMatCreuse: libmatcreuse.a test.cpp
	g++ -o testMatCreuse test.cpp -I . -L . -lmatcreuse

matCreuse: libmatcreuse.a main.cpp
	g++ -o matCreuse main.cpp -I . -L . -lmatcreuse

libmatcreuse.a : Matrice.o Operation.o pickfich.o Mat_aleatoire.o flots.o 
	ar rv libmatcreuse.a Matrice.o Operation.o pickfich.o Mat_aleatoire.o flots.o 

Matrice.o: Matrice.cpp Matrice.h
	g++ -o Matrice.o -c Matrice.cpp
 
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
	rm -rf *.o libmatcreuse.a matCreuse testMatCreuse
