#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

bool Chargement(string matr, map <pair<int, int>, int>& matrice)
{
	ifstream ouv(matr.c_str(),ios::in);

	if(ouv)
	{
		/*Initialisation des éléments*/

		//Dimensions
		int dimL;
		int dimC;
		int nbrElemNN;
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
	}
	else	//cas d'erreur lors de l'ouverture de la matrice
	{
		cerr<<"Ouverture de "<<matr<<"impossible !"<<endl; 
		return 1;
	}
}

void Affiche(map <pair<int, int>, int> matrice)
{
	map <pair<int,int>, int>::iterator it;
	for (it = matrice.begin();it != matrice.end(); it++)
    {
        cout << "<<" << it->first.first << "," << it->first.second << ">,";
        cout << it->second << ">" << endl;
    }
}


int main()
{
	map <pair<int, int>, int> michel;
	Chargement("4.txt",michel);
	Affiche(michel);
	return 0;
}


