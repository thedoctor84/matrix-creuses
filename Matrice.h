#ifndef _MATRICE_H_
#define _MATRICE_H_

#include <iostream>

using namespace std;

/**
 * \file      Matrice.h
 * \author    Rémi Drissi
 * \version   4.0
 * \date      29 mai 2015
 * \brief     fichier Matrice.h
 *
 * \details   Contient les attributs et les prototypes des fonctions.
 */

class Matrice
{
	string fichier;
	map<pair<int, int>, int> M;
	int dimL;
	int dimC;
	int nbrElemNN;

	public:
    	Matrice(string);
    	Matrice(string, int, int);
		~Matrice();
		void Set_dimL(int);
		void Set_dimC(int);
		void Set_map(map<pair<int, int>, int>);
		int  Get_dimL();
		int  Get_dimC();
		map<pair<int, int>, int> Get_map();
		bool Insertion(int, int, int);
		bool Affichage();
		void Save();
};

Matrice Addition		(string nom, Matrice A, Matrice B);
Matrice Soustraction	(string nom, Matrice A, Matrice B);
Matrice Multiplication	(string nom, Matrice A, Matrice B);
Matrice Transposee		(string nom, Matrice A);


#endif
