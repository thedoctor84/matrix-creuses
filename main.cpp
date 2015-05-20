#include <iostream>
#include <map>
#include "Operation.h"
#include "flots.h"
#include "Mat_aleatoire.h"
#define YELLOW "\033[01;33m"
using namespace std;

int main()
{
	map <pair<int, int>, int> A;
	map <pair<int, int>, int> B;

	map <pair<int, int>, int>::iterator it;
	pair<int, int> M;

	for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j>4) A.insert(pair<pair<int, int>, int> (make_pair(i,j), 1));
            else    A.insert(pair<pair<int, int>, int> (make_pair(i,j), 2));
            B.insert(pair<pair<int, int>, int> (make_pair(i,j), 2));
        }
    }

    cout << YELLOW << "\n> MATRICE A : \n\n";
    Affiche(A,10,10);

    cout << YELLOW << "\n> MATRICE B : \n\n";
    Affiche(B,10,10);

    cout << YELLOW << "\n> TRANSPOSEE : \n\n";
    Affiche(TRANSPOSEE(A,10,10),10,10);

   	cout << YELLOW << "\n> ADDITION : \n\n";
    Affiche(ADDITION(A,10,10,B,10,10),10,10);

    cout << YELLOW << "\n> MULTIPLICATION : \n\n";
    Affiche(MULTIPLICATION(A,10,10,B,10,10),10,10);

    cout << YELLOW << "\n> SOUSTRACTION : \n\n";
    Affiche(SOUSTRACTION(A,10,10,TRANSPOSEE(A,10,10),10,10),10,10);


    cout << YELLOW << "\n> AFFICHAGE MAP ALEATOIRE : \n\n";
    int nbC = 0;
    int nbL = 0;

    srand (time(NULL));
    
    map <pair<int, int>, int> Alea = generer_mat_aleatoire(95,nbL,nbC);
    Affiche(Alea,nbL,nbC);

    Sauvegarde("frite",Alea,nbL,nbC);

	return 0; 
}
