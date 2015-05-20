/**
 * \file          flots.cpp
 * \author    Grégoire Esteban
 * \version   4.0
 * \date       20 Mai 2015
 * \brief       Effectue les operations d'entrés - sorties sur les fichiers de matrices	    
 *                 
 */


#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std; /** \namespace std */

/**
 * \brief       Charge une matrice à partir d'un fichier texte 
 * \details    Le schéma d'exportation se fait d'abord en inscrivant les paramètres de la matrice
 *				puis chaque valeur est écrite sur une ligne selon le format L C V (Ligne Colonne Valeur) 
 * \param    matrice		Référence de la matrice qui va acceuillir les données du fichier
 * \param    dimL   		Entier représentant le nombre de lignes totale de la matrice 
 * \param    dimC			Entier représentant le nombre de colonnes totale de la matrice
 * \param    nbrElemNN		Entier représentant le nombre de valeurs différentes de 0
 * \return    un \e booléen selon l'erreur d'ouverture de fichier
 */

bool Chargement(string matr, map <pair<int, int>, int>& matrice, int& dimL, int& dimC, int& nbrElemNN)
{
	ifstream ouv(matr.c_str(),ios::in);

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
		return 0;
	}
	else	//cas d'erreur lors de l'ouverture de la matrice
	{
		cerr<<"Ouverture de "<<matr<<"impossible !"<<endl; 
		return 1;
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
	map <pair<int,int>, int>::iterator it;
	it = matrice.begin();
	for(int i = 0; i < dimL; i++)
	{
		for (int j = 0; j < dimC; j++)
		{
			if((it->first.first == i) && (it->first.second == j))
			{
				cout <<it->second << '\t';
				it++;
			}
			else
			{
				cout<<"0\t";
			}
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


int main()
{
	int dimC;
	int dimL;
	int nbrElemNN;
	map <pair<int,int>,int> michel;
	if(!Chargement("4.txt",michel,dimL,dimC,nbrElemNN))
	{
		Affiche(michel,dimL,dimC);
	}
	
	return 0;                 
}


