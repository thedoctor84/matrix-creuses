#ifndef _MATRICE_H_
#define _MATRICE_H_

#include <iostream>

using namespace std;

class Matrice
{
	string nomMatrice;
	map lamatrice;

	public:
    Matrice();
	~Matrice();
};

Matrice ADDITION(Matrice A, Matrice B);
Matrice SOUSTRACTION(Matrice A, Matrice B);
Matrice MULTIPLICATION(Matrice A, Matrice B);
Matrice TRANSPOSEE(Matrice A);
bool 	INSERER_VALEUR(Matrice A,int coordonneeX, int coordonneeY, int valeur);
void	AFFICHAGE(Matrice A);

#endif;
