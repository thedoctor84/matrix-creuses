#include <iostream>
#include <map>
#include "Matrice.h"
#include "Operation.h"
#include "Flots.h"
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

Matrice::~Matrice() {}

bool Matrice::Insertion(int x, int y, int valeur)
{
	if (x < 0 || y < 0 || x > dimL || y > dimC) return false;

	for (it = M.begin(); it != M.end(); it++)
	{
		if(it->first.first == x && it->first.second == y)
		{
			M.erase(it);
		}
	}

	M.insert(pair<pair<int, int>, int> (make_pair(x, y), valeur));
	Sauvegarde(fichier, M, dimL, dimC);
	return true;
}

bool Matrice::Affichage()
{
	if(nbrElemNN < 0) return false;
	
	Affiche(M, dimL, dimC);
	return true;
}

void Matrice::Set_dimL(int dim) {dimL = dim;}

void Matrice::Set_dimC(int dim) {dimC = dim;}

int  Matrice::Get_dimL() {return dimL;}

int  Matrice::Get_dimC() {return dimC;}


Matrice& Addition(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A->Get_dimL() != B->Get_dimL() || A->Get_dimC() != B->Get_dimC()) return NULL;
	map<pair<int, int>, int> temp = ADDITION(A.M, A->Get_dimL(), A->Get_dimC(), B->M, B->Get_dimL(), B->Get_dimC());
	X.M = temp;
	X->Set_dimL(A->Get_dimL());
	X->Set_dimC(B->Get_dimC());
	Sauvegarde(nom, temp, X->Get_dimL(), X->Get_dimC());
	return X;
}

Matrice& Soustraction(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A->Get_dimL() != B->Get_dimL() || A->Get_dimC() != B->Get_dimC()) return NULL;
	map<pair<int, int>, int> temp = SOUSTRACTION(A.M, A->Get_dimL(), A->Get_dimC(), B->M, B->Get_dimL(), B->Get_dimC());
	X.M = temp;
	X->Set_dimL(A->Get_dimL());
	X->Set_dimC(B->Get_dimC());
	Sauvegarde(nom, temp, X->Get_dimL(), X->Get_dimC());
	return X;
}

Matrice& Multiplication(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A->Get_dimC() != B->Get_dimL()) return NULL;

	map<pair<int, int>, int> temp = MULTIPLICATION(A.M, A->Get_dimL(), A->Get_dimC(), B->M, B->Get_dimL(), B->Get_dimC());
	X.M = temp;
	X->Set_dimL(A->Get_dimL());
	X->Set_dimC(B->Get_dimC());
	Sauvegarde(nom, temp, X->Get_dimL(), X->Get_dimC());
	return X;
}

Matrice& Transposee(string nom, Matrice& A)
{
	Matrice X(nom);
	map<pair<int, int>, int> temp = TRANSPOSEE(A.M);
	X.M = temp;
	X->Set_dimL(A->Get_dimL());
	X->Set_dimC(A->Get_dimC());
	Sauvegarde(nom, temp, X->Get_dimL(), X->Get_dimC());
	return X;
}
