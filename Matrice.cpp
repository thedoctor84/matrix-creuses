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
	int dimL = 0;
	int dimC = 0;
	int nbrElemNN = 0;
	if(!Chargement(fichier, M, dimL, dimC, nbrElemNN))
	{

	}
}

Matrice::~Matrice() {}

bool Matrice::Insertion(int x, int y, int valeur)
{
	if (x < 0 || y < 0 || x > dimL || y > dimC) return false;

	map <pair<int, int>, int>::iterator it;
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

void Set_map(map<pair<int, int>, int> X) {M = X;}

int  Matrice::Get_dimL() {return dimL;}

int  Matrice::Get_dimC() {return dimC;}

map<pair<int, int>, int>& Get_map() {return M;}

Matrice& Addition(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A.Get_dimL() != B.Get_dimL() || A.Get_dimC() != B.Get_dimC()) return NULL;
	map<pair<int, int>, int> temp = ADDITION(A.Get_map(), A.Get_dimL(), A.Get_dimC(), B.Get_map(), B.Get_dimL(), B.Get_dimC());
	X.Set_map(temp);
	X.Set_dimL(A.Get_dimL());
	X.Set_dimC(B.Get_dimC());
	Sauvegarde(nom, temp, X.Get_dimL(), X.Get_dimC());
	return X;
}

Matrice& Soustraction(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A.Get_dimL() != B.Get_dimL() || A.Get_dimC() != B.Get_dimC()) return NULL;
	map<pair<int, int>, int> temp = SOUSTRACTION(A.Get_map(), A.Get_dimL(), A.Get_dimC(), B.Get_map(), B.Get_dimL(), B.Get_dimC());
	X.Set_map(temp);
	X.Set_dimL(A.Get_dimL());
	X.Set_dimC(B.Get_dimC());
	Sauvegarde(nom, temp, X.Get_dimL(), X.Get_dimC());
	return X;
}

Matrice& Multiplication(string nom, Matrice& A, Matrice& B)
{
	Matrice X(nom);
	if(A.Get_dimC() != B.Get_dimL()) return NULL;

	map<pair<int, int>, int> temp = MULTIPLICATION(A.Get_map(), A.Get_dimL(), A.Get_dimC(), B.Get_map(), B.Get_dimL(), B.Get_dimC());
	X.Set_map(temp);
	X.Set_dimL(A.Get_dimL());
	X.Set_dimC(B.Get_dimC());
	Sauvegarde(nom, temp, X.Get_dimL(), X.Get_dimC());
	return X;
}

Matrice& Transposee(string nom, Matrice& A)
{
	Matrice X(nom);
	map<pair<int, int>, int> temp = TRANSPOSEE(A.Get_map());
	X.Set_map(temp);
	X.Set_dimL(A.Get_dimL());
	X.Set_dimC(A.Get_dimC());
	Sauvegarde(nom, temp, X.Get_dimL(), X.Get_dimC());
	return X;
}
