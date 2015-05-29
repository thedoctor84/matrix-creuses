#include "Operation.h"
#include <map>
#include <iostream>
using namespace std;

/**
 * \brief	Fonction qui transpose une matrice
 * \details	Parcourt la matrice pour inverser sa pair d'indices
 * \param	A			Matrice qui va être transposée

 */
map<pair<int, int>, int> TRANSPOSEE(map<pair<int, int>, int> A)
{
	map <pair<int, int>, int> T;
	map <pair<int, int>, int>::iterator it;
	for (it = A.begin(); it != A.end(); it++)
	{
		T.insert(pair<pair<int, int>, int> (make_pair(it->first.second, it->first.first), it->second));
	}
	return T; /** Retourne la matrice une fois transposée */
}

/**
 * \brief	Fonction qui additionne 2 matrices entre-elles
 * \details	Parcourt les 2 matrices à l'aide de 2 itérateurs, met la somme dans une 3ème matrice qui sera retournée
 * \param	A			Premiere Matrice
 * \param	Lig_A   	Nombre de lignes dans la matrice A
 * \param	Col_A		Nombre de colonnes dans la matrice A
 * \param	B			Deuxieme Matrice
 * \param	Lig_B		Nombre de lignes dans la matrice B
 * \param	Col_B		Nombre de colonnes dans la matrice B
 */
map<pair<int, int>, int> ADDITION(map<pair<int, int>, int> A, int Lig_A, int Col_A, map<pair<int, int>, int> B, int Lig_B, int Col_B)
{
	map <pair<int, int>, int> C; 
	if (Col_A != Lig_B) return C;	/** Si les dimensions des 2 matrices ne sont pas propices a l'addition : retour */
	map <pair<int, int>, int>::iterator it1;
	map <pair<int, int>, int>::iterator it2;
	it1 = A.begin();				/** Initialisation des itérateurs */
	it2 = B.begin();				/** Initialisation des itérateurs */

	while (it1 != A.end() || it2 != B.end())	/** Répétition de l'opération tant que les 2 itérateurs n'ont pas atteint la fin de leur matrice */
	{
		
		if(it1->first.first == it2->first.first)					/** Dans le cas où i de A == i de B */
		{
			if(it1->first.second == it2->first.second) 				/** Dans le cas où j de A == j de B */
			{
				if((it1->second + it2->second)!=0) C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), (it1->second + it2->second)));
				it1++;												/** Incrémentation des itérateurs */
				it2++;												/** Incrémentation des itérateurs */
			}
			else													/** j de A != j de B */
			{
				if(it1->first.second < it2->first.second)			/** j de A  < j de B */
				{
					C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), it1->second));
					it1++;											/** Incrémentation des itérateurs */
				}
				else												/** j de A  > j de B */
				{
					C.insert(pair<pair<int, int>, int> (make_pair(it2->first.first, it2->first.second), it2->second));
					it2++;											/** Incrémentation des itérateurs */
				}
			}
		}
		else														/** i de A != i de B */
		{
			if(it1->first.second < it2->first.second)				/** i de A  < i de B */
			{
				C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), it1->second));
				it1++;												/** Incrémentation des itérateurs */
			}
			else													/** i de A  > i de B */
			{
				C.insert(pair<pair<int, int>, int> (make_pair(it2->first.first, it2->first.second), it2->second));
				it2++;												/** Incrémentation des itérateurs */
			}
		}
	}
	return C;	/** Retourne la nouvelle matrice créée */
}

/**
 * \brief	Fonction qui soustrait une matrice à une autre
 * \details	Parcourt les 2 matrices à l'aide de 2 itérateurs, met la différence dans une 3ème matrice qui sera retournée
 * \param	A			Premiere Matrice
 * \param	Lig_A   	Nombre de lignes dans la matrice A
 * \param	Col_A		Nombre de colonnes dans la matrice A
 * \param	B			Deuxieme Matrice
 * \param	Lig_B		Nombre de lignes dans la matrice B
 * \param	Col_B		Nombre de colonnes dans la matrice B
 */
map<pair<int, int>, int> SOUSTRACTION(map<pair<int, int>, int> A, int Lig_A, int Col_A, map<pair<int, int>, int> B, int Lig_B, int Col_B)
{
	map <pair<int, int>, int> C;				
	if (Col_A != Lig_B) return C;				/** Retour si les dimensions ne sont pas propices à la soustraction */
	map <pair<int, int>, int>::iterator it1;
	map <pair<int, int>, int>::iterator it2;
	it1 = A.begin();							/** Initialisation des itérateurs */
	it2 = B.begin();							/** Initialisation des itérateurs */

	while (it1 != A.end() || it2 != B.end())
	{
		if(it1->first.first == it2->first.first)					/** i de A == i de B */
		{
			if(it1->first.second == it2->first.second) 				/** j de A == j de B */
			{
				if((it1->second - it2->second)!=0) C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), (it1->second - it2->second)));
				it1++;												/** Incrémentation des itérateurs */
				it2++;												/** Incrémentation des itérateurs */
			}
			else													/** j de A != j de B */
			{
				if(it1->first.second < it2->first.second)			/** j de A  < j de B */
				{
					C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), it1->second));
					it1++;											/** Incrémentation des itérateurs */
				}
				else												/** j de A  > j de B */
				{
					C.insert(pair<pair<int, int>, int> (make_pair(it2->first.first, it2->first.second), 0-it2->second));
					it2++;											/** Incrémentation des itérateurs */
				}
			}
		}
		else														/** i de A != i de B */
		{
			if(it1->first.second < it2->first.second)				/** i de A  < i de B */
			{
				C.insert(pair<pair<int, int>, int> (make_pair(it1->first.first, it1->first.second), it1->second));
				it1++;												/** Incrémentation des itérateurs */
			}
			else													/** i de A  > i de B */
			{
				C.insert(pair<pair<int, int>, int> (make_pair(it2->first.first, it2->first.second), 0-it2->second));
				it2++;												/** Incrémentation des itérateurs */
			}
		}
	}
	return C;	/** Retour de la nouvelle matrice crée */
}

/**
 * \brief	Fonction qui multiplie 2 matrices entre-elles
 * \details	Parcourt les 2 matrices à l'aide de 2 itérateurs, et met le résultat de la multiplication
 *			dans une 3ème matrice qui sera retournée
 * \param	A			Premiere Matrice
 * \param	Lig_A   	Nombre de lignes dans la matrice A
 * \param	Col_A		Nombre de colonnes dans la matrice A
 * \param	B			Deuxieme Matrice
 * \param	Lig_B		Nombre de lignes dans la matrice B
 * \param	Col_B		Nombre de colonnes dans la matrice B
 */
map<pair<int, int>, int> MULTIPLICATION(map<pair<int, int>, int> A, int Lig_A, int Col_A, map<pair<int, int>, int> B, int Lig_B, int Col_B)
{
	map <pair<int, int>, int> C;				/** Matrice crée et retournée */
	if (Col_A != Lig_B) return C;				/** Retour si les dimensions ne sont pas propices à la multiplication */
	map <pair<int, int>, int>::iterator it1;	/** Création de l'iterateur qui parcourera la matrice A */
	map <pair<int, int>, int>::iterator it2;	/** Création de l'iterateur qui parcourera la matrice B */
	for(int i=0; i<Lig_A; i++)					/** Double-boucle pour parcourir toute la matrice cible */
	{									
		for(int j=0; j<Col_B; j++)				/** Double-boucle pour parcourir toute la matrice cible */
		{
			int temp = 0;
			it1 = A.begin();					/** Initialisation des itérateurs */
			it2 = B.begin();					/** Initialisation des itérateurs */
			for (int k=0; k<Col_A; k++) 		/** 3ème boucle qui effectue l'opération */
			{
				while (it1 != A.end() && ((it1->first.first < i) || (it1->first.second < k))) it1++; /** incrementation des itérateurs */
				while (it2 != B.end() && ((it2->first.second < j) || (it2->first.first < k))) it2++; /** incrementation des itérateurs */

				if (it1->first.second == k && it2->first.first == k && it1->first.first == i && it2->first.second == j)
				{
					temp += (it1->second * it2->second); /** On ajoute notre multiplication à une valeur temporaire */
				}
			}
			if(temp != 0) C.insert(pair<pair<int, int>, int> (make_pair(i, j), temp)); /** Insertion de la valeur temporaire */
		}
	}
	return C;									
}