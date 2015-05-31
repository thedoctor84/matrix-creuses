#ifndef _MATRICE_H_
#define _MATRICE_H_

#include <iostream>

using namespace std;

class Matrice
{
	string fichier;
	map<pair<int, int>, int> M;
	int dimL;
	int dimC;
	int nbrElemNN;

	public:
    	Matrice(string);
		~Matrice();
		void Set_dimL(int);
		void Set_dimC(int);
		void Set_map(map<pair<int, int>, int>);
		int  Get_dimL();
		int  Get_dimC();
		map<pair<int, int>, int> Get_map();
		bool Insertion(int x, int y, int valeur);
		bool Affichage();
};

Matrice Addition		(string nom, Matrice& A, Matrice& B);
Matrice Soustraction	(string nom, Matrice& A, Matrice& B);
Matrice Multiplication	(string nom, Matrice& A, Matrice& B);
Matrice Transposee		(string nom, Matrice& A);


#endif
