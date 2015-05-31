#include <iostream>
#include <map>
#include "Matrice.h"
#include "Operation.h"
#include "flots.h"
#include "Pickfich.h"
#include "Mat_aleatoire.h"

using namespace std;

Matrice::Matrice(string nom)
{
	fichier = nom;
	if(!Chargement(fichier, M, dimL, dimC, nbrElemNN))
	{
		dimL = 0;
		dimC = 0;
		nbrElemNN = 0;
	}
}

Matrice::~Matrice() {delete M;}

bool Matrice::Insertion(int x, int y, int valeur)
{
	if (x < 0 || y < 0 || x > dimL || y > dimC) return false;

	M.insert(pair<pair<int, int>, int> (make_pair(x, y), valeur));
	Sauvegarde(fichier, M, dimL, dimC);
	return true;
}

bool Matrice::Affichage()
{
	if(nbrElemNN <= 0) return false;
	
	Affiche(M, dimL, dimC);
	return true;
}

Matrice& Addition(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A.dimL != B.dimL || A.dimC != B.dimC) return NULL;
	
	X.M = ADDITION(A.M, A.dimL, A.dimC, B.M, B.dimL, B.dimC);
	X.dimL = A.dimL;
	X.dimC = B.dimC;
	return X;
}

Matrice& Soustraction(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A.dimL != B.dimL || A.dimC != B.dimC) return NULL;
	
	X.M = SOUSTRACTION(A.M, A.dimL, A.dimC, B.M, B.dimL, B.dimC);
	X.dimL = A.dimL;
	X.dimC = B.dimC;
	return X;
}

Matrice& Multiplication(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A.dimC != B.dimL) return NULL;
	
	X.M = MULTIPLICATION(A.M, A.dimL, A.dimC, B.M, B.dimL, B.dimC);
	X.dimL = A.dimL;
	X.dimC = B.dimC;
	return X;
}

Matrice& Transposee(string nom, Matrice& A)
{
	X.M = TRANSPOSEE(A.M);
	X.dimL = A.dimL;
	X.dimC = A.dimC;
	return X;
}
