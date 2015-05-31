/**
 * \file		Operation.h
 * \author		Rémi Drissi
 * \version		4.0
 * \date		29 mai 2015
 * \brief		Fichier qui regroupe les différentes opérations applicables aux matrices
 * \details		Contient les fonctions décrites dans Operation.cpp
 */

#ifndef _OPERATION_H_
	#define _OPERATION_H_

	#include <map>
	using namespace std;
	map<pair<int, int>, int> TRANSPOSEE(map<pair<int, int>, int>);
	map<pair<int, int>, int> ADDITION(map<pair<int, int>, int>, int, int, map<pair<int, int>, int>, int, int);
	map<pair<int, int>, int> SOUSTRACTION(map<pair<int, int>, int>, int, int, map<pair<int, int>, int>, int, int);
	map<pair<int, int>, int> MULTIPLICATION(map<pair<int, int>, int>, int, int, map<pair<int, int>, int>, int, int);

#endif