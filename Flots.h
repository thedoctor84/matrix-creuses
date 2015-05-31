#ifndef FLOTS
#define FLOTS

#include <fstream>
#include <string>
#include <map>

using namespace std;

bool Chargement(string matr, map <pair<int, int>, int>& matrice, int& dimL, int& dimC, int& nbrElemNN);
void Affiche(map <pair<int, int>, int> matrice, int dimL, int dimC);
bool Sauvegarde(string smatr, map <pair<int, int>, int>& matrice, int& dimL, int& dimC);

#endif