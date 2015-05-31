/**
 * \file      Mat_aleatoire.cpp
 * \author    Antoine Letourneur
 * \version   4.0
 * \date      29 mai 2015
 * \brief     Enregistre une matrice aleatoire dans un fichier
 *
 * \details   Sauvegarde une matrice de dim aleatoire avec une pourcentage de zeros donné 
 *                  
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mat_aleatoire.h"
#include "Flots.h"
using namespace std;

/**
 * \brief	Fonction qui renvoie un nombre aleatoire entre deux valeurs min et max passees en argument
 * \details	Donne une matrice de dim aleatoire (entre 10 et 20), avec des valeurs aleatoires non nulles entre 1 et 100
 * \param	min Valeur minimale du nombre aleatoire voulu
 * \param   max Valeur aleatoire du nombre aleatoire voulu
 */

int rand_entre_min_et_max(int min, int max)
{
    return rand()%(max-min+1) + min;
}

//matrice aléatoire avec un % de 0 (ex: mat_alea(70) donne 70% de 0 et le reste aléatoire)

/**
 * \brief	Fonction qui genere une matrice remplit aleatoirement avec une dimension aleatoire
 * \details	Donne une matrice de dim aleatoire (entre 10 et 20), avec des valeurs aleatoires non nulles entre 1 et 100
 * \param	pourcentage_zero Le pourcentage de 0 dans la matrice creuse (entier de 0 a 100)
 */

void generer_mat_aleatoire(int pourcentage_zero)

{
	srand (time(NULL));
   	int nbLigne = rand_entre_min_et_max(10,20);
	int nbCol = rand_entre_min_et_max(10,20);
	map<pair<int,int>,int> MC;
	map <pair<int, int>, int>::iterator it;

	int nombresNonNuls = (int)((100-pourcentage_zero)*nbLigne*nbCol/100);

	int nbAlea = rand_entre_min_et_max(1,100);
	int indLigAlea = rand_entre_min_et_max(0,nbLigne-1);
	int indColAlea = rand_entre_min_et_max(0,nbCol-1);

	bool existeDeja;

	MC.insert(pair<pair<int, int>, int> (make_pair(indLigAlea, indColAlea), nbAlea));

	int nbDeNbNonNulsInseres = 1;

	while(nbDeNbNonNulsInseres < nombresNonNuls)
	{
		nbAlea = rand_entre_min_et_max(1,100);
		indLigAlea = rand_entre_min_et_max(0,nbLigne-1);
		indColAlea = rand_entre_min_et_max(0,nbCol-1);
		existeDeja = false;

		for(it = MC.begin(); it != MC.end(); it++)
		{
			if (indLigAlea == it->first.first && indColAlea == it->first.second) existeDeja = true;
		}

		if (!existeDeja)
		{
			 MC.insert(pair<pair<int, int>, int> (make_pair(indLigAlea, indColAlea), nbAlea));
			 nbDeNbNonNulsInseres++;
		}
	}
	Sauvegarde("Mat_aleatoire",MC,nbLigne,nbCol);
}

void generer_mat_aleatoire