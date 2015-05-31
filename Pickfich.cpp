#include <iostream>
#include <fstream>
#include <string>
#include "Pickfich.h"

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
 * \brief       recherche un fichier présent dans la liste main.txt.
 * \details     Parmis la liste des fichiers disponible, teste l'existence du fichier donné par l'utilisateur, et true s'il existe, false sinon.
 * \param 		nom_fichier nom du fichier à tester.	
 * \return    	retourne un booléen indiquant si le fichier demandé existe ou pas.
 */
bool recherchefich(string nom_fichier)
{
	 
	ifstream fichier("main.txt", ios::in);
	if(fichier) 
	{
		if(!file_exist(nom_fichier))		//le fichier n'existe pas
		{
			fichier.close();
			return false;
		}
		else
		{
			fichier.close();
			return true;
		}

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
