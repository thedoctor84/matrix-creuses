/**
 * \file          flots.cpp
 * \author    Grégoire Esteban
 * \version   5.0
 * \date       20 Mai 2015
 * \brief       Effectue les operations d'entrés - sorties sur les fichiers de matrices	    
 *                 
 */


#include <iostream>
#include "Flots.h"

#define RED "\033[01;31m"
#define GREEN "\033[01;32m"
#define BLUE "\033[01;34m"
#define BASIC "\033[00;00m"

using namespace std; /** \namespace std */

/**
 * \brief       Charge une matrice à partir d'un fichier texte 
 * \details    Le schéma d'importation se fait d'abord en chargeant les paramètres de la matrice
 *				puis chaque valeur est récupéré via ses indices de lignes puis de colonne, et enfin
 *				la valeur est insérée dans la matrice.
 * \param    matrice		Référence de la matrice qui va acceuillir les données du fichier
 * \param    dimL   		Entier représentant le nombre de lignes totale de la matrice 
 * \param    dimC			Entier représentant le nombre de colonnes totale de la matrice
 * \param    nbrElemNN		Entier représentant le nombre de valeurs différentes de 0
 * \return    un \e booléen selon l'erreur d'ouverture de fichier
 */


bool Chargement(string matr, map <pair<int, int>, int>& matrice, int& dimL, int& dimC, int& nbrElemNN)
{
	ifstream ouv((matr+".txt").c_str(),ios::in);

	if(ouv)
	{
		/*Initialisation des éléments*/

		//Dimensions
		/*int dimL;
		int dimC;
		int nbrElemNN;*/

		//Indicateurs de positions + Valeur
		int posL;
		int posC;
		int val;

		/*Récupération des éléments*/
		//Init
		ouv >> dimL;
		ouv >> dimC;
		ouv >> nbrElemNN;

		//creation de la map
		for(int i=0;i<nbrElemNN;i++)
		{
			ouv >> posL;
			ouv >> posC;
			ouv >> val;

			matrice.insert(pair<pair<int,int>,int> (make_pair(posL,posC),val));
		}
		ouv.close();
		return true;
	}
	else	//cas d'erreur lors de l'ouverture de la matrice
	{
		return false;
	}
}

/**
 * \brief       Sauvegarde une matrice dans un fichier texte 
 * \details    Le schéma d'exportation se fait d'abord en inscrivant les paramètres de la matrice
 *				puis chaque valeur est écrite sur une ligne selon le format L C V (Ligne Colonne Valeur) 
 * \param    matrice		Référence de la matrice qui contient les données
 * \param    dimL   		Entier représentant le nombre de lignes totale de la matrice 
 * \param    dimC			Entier représentant le nombre de colonnes totale de la matrice
 * \return    un \e booléen selon l'erreur d'ouverture de fichier
 */

bool Sauvegarde(string smatr, map <pair<int, int>, int> matrice, int dimL, int dimC)
{
	ofstream save((smatr+".txt").c_str(), ios::out | ios::trunc);

	if(save)
	{
		save << dimL << endl;
		save << dimC << endl;
		save << matrice.size() << endl;
		map <pair<int,int>, int>::iterator it; 

		for(it = matrice.begin(); it!=matrice.end(); it++)
		{
			save<<it->first.first <<" "<< it->first.second <<" "<<it->second<<endl; 
		}
		save.close();
		return false;
	}
	else
	{
		cerr <<"Erreur lors de la creation du fichier !" <<endl;
		return true;
	}
}

/**
 * \brief      Affiche une matrice selon la notation standard
 * \details    La fonction utilise un itérateur. Par défaut, une case qui ne contient pas de valeur
 *				vaut 0
 * \param    matrice		Référence de la matrice a afficher
 * \param    dimL   		Entier représentant le nombre de lignes totale de la matrice 
 * \param    dimC			Entier représentant le nombre de colonnes totale de la matrice
 */

void Affiche(map <pair<int, int>, int> matrice, int dimL, int dimC)
{
	if(matrice.empty())
	{
		cerr<<"Erreur, la matrice est vide !"<<endl;
		return;
	}
	map <pair<int,int>, int>::iterator it;
	it = matrice.begin();
	for(int i = 0; i < dimL; ++i)
	{
		for (int j = 0; j < dimC; ++j)
		{
			if(it!=matrice.end() && (it->first.first == i) && (it->first.second == j))
			{
				if(it->second > 0)	cout<< GREEN << it->second << "\t" << BASIC;
				else cout<< RED << it->second << "\t" << BASIC;
				it++;
			}
			else cout<< BLUE << "0\t" << BASIC;
		}
		cout<<endl;
	}

	//Affichage en ligne
	/*for (it = matrice.begin();it != matrice.end(); it++)
    {
        cout << "<<" << it->first.first << "," << it->first.second << ">,";
        cout << it->second << ">" << endl;
    }*/
}


/*int main()
{
	int dimC;
	int dimL;
	int nbrElemNN;
	map <pair<int,int>,int> michel;
	if(!Chargement("4",michel,dimL,dimC,nbrElemNN))
	{
		Affiche(michel,dimL,dimC);
	}

	string name;

	cout <<"Entrez le nom de la Sauvegarde"<<endl;
	cin >> name;
	Sauvegarde((name+".txt").c_str(), michel, dimL, dimC);
	
	return 0;                 
}*/


