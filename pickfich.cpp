#include <iostream>
#include <fstream>
#include <string>

using namespace std;



/**
 * \file      pickfich.cpp
 * \author    Imran
 * \version   3.0
 * \date       20 mai 2015
 * \brief      Permet de séléctionner des fichiers présent dans un fichier texte.
 *
 * \details    Liste les fichiers de matrices disponible et demande à un utilisateur d'en séléctionner un certain nombre en vue des opérations.
 */

/**
 * \brief       Vérifie l'existence d'un fichier.
 * \details    Teste l'ouverture d'un fichier donné, si elle s'éffectue, alors le fichier existe.
 * \param    fichier         nom du fichier
 * \return    retourne le booléan qui true = le fichier existe, false sinon.
 */
bool file_exist(string& fichier)
{
	ifstream fich(fichier.c_str());
	return !fich.fail();
}

/**
 * \brief       recherche les fichiers présent dans une liste.
 * \details    Parmis la liste des fichiers disponible, teste l'existence du fichier donné par l'utilisateur, et renvoie des noms de ceux-ci.
 * \param    fichprincipal      fichier contenant la liste des fichiers matrices.
 * \param    nbfich         	nombre de fichiers que l'utilisateur désire.
 * \return    retourne un tableau contenant les noms des fichiers séléctionnés.
 */
string* recherchefich(int nbfich)
{
	 
	ifstream fichier("main.txt", ios::in);
	if(fichier) 
	{
		string ligne;
		string *fich_choisie = new string[nbfich];
		string tmp ="";
		while(getline(fichier, ligne))			// affiche la liste des fichiers de matrices disponible
		{
					cout << ligne << endl;
		}
       	 	
		for(int i=0;i<nbfich;i++)
		{
				do
				{
					cout << "de quel fichier avez vous besoin ?" << endl;
					cin >> tmp;
				}
				while(!file_exist(tmp));		//tant que le fichier n'existe pas, demander le nom du fichier voulue 
				fich_choisie[i] = tmp; 
		
		}

		fichier.close();
		return fich_choisie;
		
 		
	}
	else 
	{
		cerr << "Erreur à l'ouverture !" << endl;
 	}
}

/**
 * \brief   	Met à jour le fichier des noms de sauvegardes (main.txt)  
 * \details  	Ajoute au fichier main.txt le nom d'un fichier sauvegardé
 * \param   	nom_sauvegarde		nom du fichier sauvegardé
 */
void UpdateS(string nom_sauvegarde)
{
	ofstream fichier("main.txt", ios::out | ios::app);
	if(fichier)
	{
		fichier << nom_sauvegarde << endl;
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier" << endl;
	}
}
