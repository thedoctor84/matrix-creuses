#ifndef _PICKFICH_H_
#define _PICKFICH_H_

#include <string>

using namespace std;
/**
 * \file      pickfich.h
 * \author    Imran
 * \version   4.0
 * \date      29 mai 2015
 * \brief     Fichier pickfich.h
 * \details    Contient les prototypes des fonctions de verification de fichiers.
 */


bool file_exist(string& fichier);
bool recherchefich(string nom_fichier);
void UpdateS(string nom_sauvegarde);

#endif