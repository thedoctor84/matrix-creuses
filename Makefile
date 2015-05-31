all: matCreuse testMatCreuse

testMatCreuse: libmatcreuse.a Test.cpp
	g++ -o testMatCreuse Test.cpp -I . -L . -lmatcreuse

matCreuse: libmatcreuse.a main.cpp
	g++ -o matCreuse main.cpp -I . -L . -lmatcreuse

libmatcreuse.a : Matrice.o Operation.o Pickfich.o Mat_aleatoire.o Flots.o 
	ar rv libmatcreuse.a Matrice.o Operation.o Pickfich.o Mat_aleatoire.o Flots.o 

Matrice.o: Matrice.cpp Matrice.h
	g++ -o Matrice.o -c Matrice.cpp
 
Operation.o: Operation.cpp Operation.h
	g++ -o Operation.o -c Operation.cpp 
 
Pickfich.o: Pickfich.cpp Pickfich.h
	g++ -o Pickfich.o -c Pickfich.cpp 

Mat_aleatoire.o: Mat_aleatoire.cpp Mat_aleatoire.h
	g++ -o Mat_aleatoire.o -c Mat_aleatoire.cpp 

Flots.o: Flots.cpp Flots.h
	g++ -o Flots.o -c Flots.cpp 

clean:
	rm -rf *.o
 
mrproper: clean
	rm -rf *.o libmatcreuse.a matCreuse testMatCreuse
