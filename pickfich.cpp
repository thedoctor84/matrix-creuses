#include <iostream>
#include <string>

using namespace std;

string recherchefich(string fichprincipal)
{
	fichprincipal = "main.txt"; 
	ifstream fichier(fichprincipal.c_str(), ios::in);
	if(fichier) 
	{
		int nbfich;
		string ligne;
		string fich_choisie[];
       	 	while(getline(fichier, ligne))
      		{
                	cout << ligne << endl;
		}
		cout << "combien de fichiers voulez vous ?" << endl;
		cin >> nbfich;
		for(int i=0;i<nbfich;i++)
		{
			cout << "de quelle fichier avez vous besoin ?" << endl;
			cin >> fich_choisie[i];
			while(getline(fichier, ligne))
      			{
                		
			}
		}
		




 		fichier.close();
	}
	else 
	{
		cerr << "Erreur à l'ouverture !" << endl;
 	}
}
