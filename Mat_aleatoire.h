#ifndef _MAT_ALEA_
#define _MAT_ALEA_

#include <map>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rand_entre_min_et_max(int min, int max);

map<pair<int,int>,int> generer_mat_aleatoire(int pourcentage_zero,int& nbLigne,int& nbCol);

#endif