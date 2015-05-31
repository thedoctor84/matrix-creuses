/**
 * \file      Mat_aleatoire.h
 * \author    Antoine Letourneur
 * \version   4.0
 * \date      29 mai 2015
 * \brief     Enregistre une matrice aleatoire dans un fichier
 *
 * \details   Sauvegarde une matrice de dim aleatoire avec une pourcentage de zeros donné 
 *            Contient une fonction renvoyant une nombre aleatoire entre deux valeurs min et max donnees
 			  Et contient la fonction generant une matrice aleatoire avec un pourcentage donne de zeros
 */

#ifndef _MAT_ALEA_
#define _MAT_ALEA_

#include <map>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rand_entre_min_et_max(int min, int max);

void generer_mat_aleatoire(int pourcentage_zero);

void generer_mat_aleatoire_taille_fixe(int nbLigne,int nbCol, int pourcentage_zero);

#endif