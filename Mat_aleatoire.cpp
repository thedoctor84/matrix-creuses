#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;

//matrice aléatoire avec un % de 0 (ex: mat_alea(70) donne 70% de 0 et le reste aléatoire)


// Nb de Lignes et de col entre 5 et 10
int rand_entre_min_et_max(int min, int max){
    return rand()%(max-min) + min;
}



/*map<pair<int,int>,int>*/ void generer_mat_aleatoire(int pourcentage_zero)
{
	int nbLigne = rand_entre_min_et_max(100,200);
	int nbCol = rand_entre_min_et_max(100,200);
	cout << "Nombre de lignes : " << nbLigne << endl;
	cout << "Nombre de Colonnes : " << nbCol << endl;
	map<pair<int,int>,int> MC;
	map <pair<int, int>, int>::iterator it;

	int nombresNonNuls = (int)((100-pourcentage_zero)*nbLigne*nbCol/100);
	cout << "Nombre de case non nulles : " << nombresNonNuls << endl;

	int nbAlea = rand_entre_min_et_max(0,100);
	int indLigAlea = rand_entre_min_et_max(0,nbLigne);
	int indColAlea = rand_entre_min_et_max(0,nbCol);
	bool existeDeja;

	MC.insert(pair<pair<int, int>, int> (make_pair(indLigAlea, indColAlea), nbAlea));

	int nbDeNbNonNulsInseres = 1;

	while(nbDeNbNonNulsInseres < nombresNonNuls)
	{
		nbAlea = rand_entre_min_et_max(0,100);
		indLigAlea = rand_entre_min_et_max(0,nbLigne);
		indColAlea = rand_entre_min_et_max(0,nbCol);
		existeDeja = false;

		for(it = MC.begin(); it != MC.end(); it++)
		{
			if (indLigAlea == it->first.first && indColAlea == it->first.second) existeDeja = true;
		}

		if (!existeDeja)
		{
			 MC.insert(pair<pair<int, int>, int> (make_pair(indLigAlea, indColAlea), nbAlea));
			 nbDeNbNonNulsInseres++;
		}
	}
}


int main() 
{
	srand(time(NULL));
	generer_mat_aleatoire(95);
	//for(int i=0; i < 100; i++)	cout << "nb : "<< rand_ligne_col() << endl;

	return 0;
}