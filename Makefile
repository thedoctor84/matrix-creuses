all: main.o MC.o
	g++ main.o MC.o -o MC
 
main.o: main.cpp MC.h
	g++ -c main.cpp -o main.o
 
MC.o: MC.cpp
	g++ -c MC.cpp -o MC.o
 
clean:
	rm -rf *.o
 
mrproper: clean
	rm -rf test