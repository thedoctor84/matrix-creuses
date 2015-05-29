#include <iostream>
#include <map>
#include <string>
#include "Operation.h"
#include "pickfich.h"
#include "flots.h"
#include "Mat_aleatoire.h"
#define BASIC   "\033[01;30m"
#define RED     "\033[01;31m"
#define GREEN   "\033[01;32m"
#define YELLOW  "\033[01;33m"
#define BLUE    "\033[01;34m"

using namespace std;

/**
 * \file       main.cpp
 * \author     Gregoire
 * \version    4.0
 * \date       29 mai 2015
 * \brief      Fonction principale que l'utilisateur va utiliser pour faire les opérations.
 *
 * \details    L'utilisateur choisit son opération puis décide s'il veut charger ou génerer une matrice aléatoirement pour faire l'opération, on lui propose ensuite s'il désire la sauvegarder.
 */



/**
 * \brief      Fonction principale Main.
 * \details    Effectue les opérations sur les matrices par l'utilisateur.
 * \return     Valeur de retour du main.
 */
int main()
{
    int ope;
    int choix;
    map <pair<int, int>, int> A;
    map <pair<int, int>, int> B;

    map <pair<int, int>, int> Res;
    string* rech;

    int dimLA;
    int dimCA;
    int dimLRes;

    int dimLB;
    int dimCB;
    int dimCRes;

    int nbrElemNN1;
    int nbrElemNN2;
    int nbrElemNN3;

    cout<<"Bienvenue dans le programme d'interaction des MatrLib"<<endl;
    cout<<endl;

        cout<<"Veuillez selectionner une operation parmi :"<<endl;
        cout<< RED <<"1) ADDITION" << GREEN << " 2) MULTIPLICATION" << BLUE << " 3) SOUSTRACTION" << YELLOW << " 4) TRANSPOSEE"<< BASIC << endl;
        cin>>ope;

        if(ope == 1 || ope == 2 || ope == 3)
        {


            for(int i = 0; i<2; i++)
            {
                do
                {
                    cout<<"Souhaitez vous 1) Charger   2) Generer la matrice "<<i<<" ?"<<endl;
                    cin >> choix;

                }while(choix != 1 || choix != 2);

                if(choix == 1 && i == 0)
                {
                    rech = recherchefich(1);
                    Chargement(rech[0], A, dimLA, dimCA,nbrElemNN1);
                }

                if(choix == 1 && i == 1)
                {
                    rech = recherchefich(1);
                    Chargement(rech[0], B, dimLB, dimCB ,nbrElemNN2);
                }

                if(choix == 2 && i == 0)
                {
                    rech = recherchefich(1);
                    Chargement(rech[0], A, dimLB, dimCB ,nbrElemNN2);
                }

                if(choix == 2 && i == 1)
                {
                    rech = recherchefich(1);
                    Chargement(rech[0], B, dimLB, dimCB ,nbrElemNN2);
                }
            }

            delete rech;

            switch (ope)
            {
                case 1:
                
                Res = ADDITION(A, dimLA, dimCA, B, dimLB, dimCB),
                Affiche(Res, dimLRes,dimCRes,nbrElemNN3);
                break;

               case 2:

                Res = MULTIPLICATION(A, dimLA, dimCA, B, dimLB, dimCB),
                Affiche(Res, dimLRes,dimCRes,nbrElemNN3);
                break;

                case 3 :
                Res = SOUSTRACTION(A, dimLA, dimCA, B, dimLB, dimCB),
                Affiche(Res, dimLRes,dimCRes,nbrElemNN3);
                break;

            }    
        }

        if(ope == 4)
        {
            do
            {
                cout<<"Souhaitez-vous 1) Charger   2) Generer la matrice "<<i<<" ?"<<endl;
                cin >> choix;

            }while(choix != 1 || choix != 2)

            if(choix == 1)
            {
                rech=recherchefich(1);
                Chargement(rech[0], A, dimLA, dimCA,nbrElemNN1);
            }
            else
            {
                A = generer_mat_aleatoire(95);
            }

            Res = TRANSPOSEE(A, dimLA, dimCA),
            Affiche(Res, dimLRes,dimCRes,nbrElemNN3);
        }
        
        char choice;

        cout<<"Voulez-vous sauvegarder la matrice resultante ?(o/n)"<<endl;
        cin>>choice;
        while(choice != 'o' || choice != 'n')
        {
            cout << "Veuillez entrer correctement votre choix :" << endl;
            cin>>choice;
        }
        if(choice == 'n')
        {

        }
        else if(choice == 'o')
        {
            string nom_sauvegarde;
            cout << "Quel nom voulez vous pour la sauvegarde ?" << endl;
            cin >> nom_sauvegarde;
            Sauvegarde(nom_sauvegarde.c_str(),Alea,nbL,nbC);
        }

        return 0;
}
	
	

	/*map <pair<int, int>, int>::iterator it;
	pair<int, int> M;

	for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j>4) A.insert(pair<pair<int, int>, int> (make_pair(i,j), 1));
            else    A.insert(pair<pair<int, int>, int> (make_pair(i,j), 2));
            B.insert(pair<pair<int, int>, int> (make_pair(i,j), 2));
        }
    }

    cout << YELLOW << "\n> MATRICE A : \n\n";
    Affiche(A,10,10);

    cout << YELLOW << "\n> MATRICE B : \n\n";
    Affiche(B,10,10);

    cout << YELLOW << "\n> TRANSPOSEE : \n\n";
    Affiche(TRANSPOSEE(A,10,10),10,10);

   	cout << YELLOW << "\n> ADDITION : \n\n";
    Affiche(ADDITION(A,10,10,B,10,10),10,10);

    cout << YELLOW << "\n> MULTIPLICATION : \n\n";
    Affiche(MULTIPLICATION(A,10,10,B,10,10),10,10);

    cout << YELLOW << "\n> SOUSTRACTION : \n\n";
    Affiche(SOUSTRACTION(A,10,10,TRANSPOSEE(A,10,10),10,10),10,10);


    cout << YELLOW << "\n> AFFICHAGE MAP ALEATOIRE : \n\n";
    int nbC = 1;
    int nbL = 1;

    map <pair<int, int>, int> Alea = generer_mat_aleatoire(95,nbL,nbC);
    Affiche(Alea,nbL,nbC);

    Sauvegarde("frite",Alea,nbL,nbC);

	return 0; */

