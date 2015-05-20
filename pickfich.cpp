#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool file_exist(string& fichier)
{
	ifstream fich(fichier.c_str());
	return !fich.fail();
}

string* recherchefich(string fichprincipal, int nbfich)
{
	 
	ifstream fichier(fichprincipal.c_str(), ios::in);
	if(fichier) 
	{
		string ligne;
		string *fich_choisie = new string[nbfich];
		string tmp ="";
		while(getline(fichier, ligne))			// affiche la liste des fichiers de matrices disponible
		{
					cout << ligne << endl;
		}
       	 	
		for(int i=0;i<nbfich;i++)
		{
			//do
			//{
				///cout << fichier.tellg() << endl;
				do
				{
					cout << "de quel fichier avez vous besoin ?" << endl;
					cin >> tmp;
				}
				while(!file_exist(tmp));
				fich_choisie[i] = tmp; 
				/*while(getline(fichier,ligne))
	      			{
					if(ligne != tmp)
					{
						cout << "la" << endl;
						cout << fichier.tellg() << endl;
						continue;
					}
					else
					{
						fich_choisie[i] = ligne;
						cout << ligne << endl;
					}
				}
			}while(fich_choisie[i] != ligne);*/
		
		}

		fichier.close();
		return fich_choisie;
		
 		
	}
	else 
	{
		cerr << "Erreur à l'ouverture !" << endl;
 	}
}

int main()
{
	string fichprincipal = "main.txt";
	string* tot = recherchefich( fichprincipal,2);
	cout << tot[0] <<endl;
	cout << tot[1] <<endl;
	
	return 0;
}
