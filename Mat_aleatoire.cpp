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
	int nbLigne = rand_entre_min_et_max(5,10);
	int nbCol = rand_entre_min_et_max(5,10);
	cout << "Nombre de lignes : " << nbLigne << endl;
	cout << "Nombre de Colonnes : " << nbCol << endl;
	map<pair<int,int>,int> MC;
	map <pair<int, int>, int>::iterator it;

	int nombresNonNuls = (int)((100-pourcentage_zero)*nbLigne*nbCol/100);
	cout << "Nombre de case non nulles : " << nombresNonNuls << endl;



	  for (int i=0; i<=nbLigne; i++)
        {
            for (int j=0; j<=nbCol; j++)
            {
                MC.insert(pair<pair<int, int>, int> (make_pair(i, j), i+j));
            }
        }  
}


int main() 
{
	srand(time(NULL));
	generer_mat_aleatoire(50);
	//for(int i=0; i < 100; i++)	cout << "nb : "<< rand_ligne_col() << endl;

	return 0;
}