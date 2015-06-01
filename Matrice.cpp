#include <iostream>
#include <map>
#include "Matrice.h"
#include "Operation.h"
#include "Flots.h"
#include "Pickfich.h"
#include "Mat_aleatoire.h"

using namespace std;
/**
 * \file      Matrice.cpp
 * \author    Rémi Drissi
 * \version   4.0
 * \date      29 mai 2015
 * \brief     Effectue les opérations sur les matrice à partir d'une classe.
 *
 * \details   Les fonctions sur les matrices ont étés crée de façon à utiliser l'objet Matrice pour que l'utilisateur est une gestion facile des matrices.
 */


/**
 * \brief	Constructeur de Matrice.
 * \details	initialise le nom et les dimension de la matrice et test l'existence du fichier.
 * \param	nom			nom de la Matrice.
 */
Matrice::Matrice(string nom)
{
	fichier = nom;
	int dimL(0);
	int dimC(0);
	int nbrElemNN(0);
	Chargement(fichier, M, dimL, dimC, nbrElemNN);
}

/**
 * \brief	Constructeur de Matrice.
 * \details	initialise le nom et les dimension de la matrice selon des coordonnées donnés en argument.
 * \param	nom			nom de la Matrice.
  * \param	x			indice en ligne
   * \param	y			indice en colonne.
 */
Matrice::Matrice(string nom, int x, int y)
{
	fichier = nom;
	int dimL = x;
	int dimC = y;
	nbrElemNN = 0;
	Sauvegarde(fichier, M, dimL, dimC);
}


Matrice::~Matrice() {}


/**
 * \brief	Fonction Insertion
 * \details	insère une valeur dans une matrice selon ses coordonnées.
 * \param	x			indice en ligne.
 * \param	y			indice en colonne.
 * \param	valeur		valeur à ajouter.
 * \return	Retourne un booléen selon si on peut insérer ou pas et insère si oui.
 */
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
	++nbrElemNN;
	M.insert(pair<pair<int, int>, int> (make_pair(x, y), valeur));
	Sauvegarde(fichier, M, dimL, dimC);
	return true;
}

/**
 * \brief	Fonction Affichage.
 * \details	Affiche la matrice.
 * \return	Retourne un booléen selon si on peut afficher ou pas et affiche si oui.
 */
bool Matrice::Affichage()
{
	if(nbrElemNN < 0) return false;
	
	Affiche(M, dimL, dimC);
	return true;
}

void Matrice::Set_dimL(int dim) {dimL = dim;}

void Matrice::Set_dimC(int dim) {dimC = dim;}

void Matrice::Set_map(map<pair<int, int>, int> X) {M = X;}

int  Matrice::Get_dimL() {return dimL;}

int  Matrice::Get_dimC() {return dimC;}

map<pair<int, int>, int> Matrice::Get_map() {return M;}


/**
 * \brief	Fonction Addition
 * \details	Additionne deux matrices après avoir tester les conditions nécéssaire.
 * \param	nom			nom de la matrice. 
 * \param	A			Matrice A.
 * \param	B			Matrice B.
 * \return	Retourne une Matrice, addition de A et de B.
 */
Matrice Addition(string nom, Matrice A, Matrice B)
{
	if(A.Get_dimL() != B.Get_dimL() || A.Get_dimC() != B.Get_dimC())
	{
		Matrice Matfail("fail");
		return Matfail;
	}
	Matrice X(nom);
	map<pair<int, int>, int> temp = ADDITION(A.Get_map(), A.Get_dimL(), A.Get_dimC(), B.Get_map(), B.Get_dimL(), B.Get_dimC());
	X.Set_map(temp);
	X.Set_dimL(A.Get_dimL());
	X.Set_dimC(B.Get_dimC());
	Sauvegarde(nom, temp, X.Get_dimL(), X.Get_dimC());
	return X;
}

/**
 * \brief	Fonction Soustraction
 * \details	Soustrait deux matrices après avoir tester les conditions nécéssaire.
 * \param	nom			nom de la matrice. 
 * \param	A			Matrice A.
 * \param	B			Matrice B.
 * \return	Retourne une Matrice, soustraction de A et de B.
 */
Matrice Soustraction(string nom, Matrice A, Matrice B)
{

	if(A.Get_dimL() != B.Get_dimL() || A.Get_dimC() != B.Get_dimC())
	{
		Matrice Matfail("fail");
		return Matfail;
	}

	Matrice X(nom);
	map<pair<int, int>, int> temp = SOUSTRACTION(A.Get_map(), A.Get_dimL(), A.Get_dimC(), B.Get_map(), B.Get_dimL(), B.Get_dimC());
	X.Set_map(temp);
	X.Set_dimL(A.Get_dimL());
	X.Set_dimC(B.Get_dimC());
	Sauvegarde(nom, temp, X.Get_dimL(), X.Get_dimC());
	return X;
}

/**
 * \brief	Fonction Multiplication
 * \details	Multiplie deux matrices après avoir tester les conditions nécéssaire.
 * \param	nom			nom de la matrice. 
 * \param	A			Matrice A.
 * \param	B			Matrice B.
 * \return	Retourne une Matrice, multiplication de A et de B.
 */
Matrice Multiplication(string nom, Matrice A, Matrice B)
{

	if(A.Get_dimC() != B.Get_dimL()) 
	{
		Matrice Matfail("fail");
		return Matfail;
	}
	Matrice X(nom);
	map<pair<int, int>, int> temp = MULTIPLICATION(A.Get_map(), A.Get_dimL(), A.Get_dimC(), B.Get_map(), B.Get_dimL(), B.Get_dimC());
	X.Set_map(temp);
	X.Set_dimL(A.Get_dimL());
	X.Set_dimC(B.Get_dimC());
	Sauvegarde(nom, temp, X.Get_dimL(), X.Get_dimC());
	return X;
}

/**
 * \brief	Fonction Transposee
 * \details	Effectue la transposee d'une matrice A
 * \param	nom			nom de la matrice.
 * \param	A			Matrice A.
 * \return	Retourne une Matrice, transposee de A.
 */
Matrice Transposee(string nom, Matrice A)
{
	Matrice X(nom);
	map<pair<int, int>, int> temp = TRANSPOSEE(A.Get_map());
	X.Set_map(temp);
	X.Set_dimL(A.Get_dimL());
	X.Set_dimC(A.Get_dimC());
	Sauvegarde(nom, temp, X.Get_dimL(), X.Get_dimC());
	return X;
}
