#include <iostream>
#include <map>
#include "Matrice.h"
#include "Operation.h"
#include "flots.h"
#include "pickfich.h"
#include "Mat_aleatoire.h"

using namespace std;

Matrice::Matrice(string nom)
{
	fichier = nom;
	if(!Chargement(fichier, M, Lig, Col, nbrElemNN))
	{
		Lig = 0;
		Col = 0;
	}
	
}

Matrice::~Matrice()
{

}