/**
 * \file      Flots.h
 * \author    Antoine Letourneur
 * \version   4.0
 * \date      29 mai 2015
 * \brief     Opération d'entrées/sorties
 *
 * \details   Affichage, Chargement et sauvegarde d'une matrice sont disponibles
 *            
 			  
 */

#ifndef FLOTS
#define FLOTS

#include <fstream>
#include <string>
#include <map>

using namespace std;

bool Chargement(string matr, map <pair<int, int>, int>& matrice, int& dimL, int& dimC, int& nbrElemNN);
void Affiche(map <pair<int, int>, int> matrice, int dimL, int dimC);
bool Sauvegarde(string smatr, map <pair<int, int>, int> matrice, int dimL, int dimC);

#endif