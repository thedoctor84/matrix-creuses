#include <iostream>
#include <string>
#include <map>
#include "libmatcreuse.h"



using namespace std;


int main()
{
    map <pair<int, int>, int> A;
    map <pair<int, int>, int> B;
    map <pair<int, int>, int> Res;
    
    int dimLA;
    int dimCA;
    int dimLRes;

    int dimLB;
    int dimCB;
    int dimCRes;

    int nbrElemNNA;
    int nbrElemNNB;
    int choix;

    string mat_aleatoire = "Mat_aleatoire";

    cout << "Tester : 1)Addition    2)Multiplication    3)Soustraction  4)Transposee" << endl;
    cin >> choix;
    cin.clear(); // Pour eviter les erreurs sur le cin, effacer les bits d'erreurs 
    cin.ignore(10000, '\n'); // supprimer la ligne erronée dans le buffer

    while(choix < 1 || choix > 4)
    {
        cout << "saisissez le bon numero svp :" << endl;
        cin >> choix;
        cin.clear(); // Pour eviter les erreurs sur le cin, effacer les bits d'erreurs 
    	cin.ignore(10000, '\n'); // supprimer la ligne erronée dans le buffer

    }

    if(choix == 1)
    {
        generer_mat_aleatoire(95);
        Chargement(mat_aleatoire, A, dimLA, dimCA, nbrElemNNA);
        generer_mat_aleatoire(95);
        Chargement(mat_aleatoire, B, dimLB, dimCB, nbrElemNNB);
        Res = ADDITION(A, dimLA, dimCA, B, dimLB, dimCB);
        Affiche(Res, dimLRes, dimCRes);
    }
    else if(choix == 2)
    {
        generer_mat_aleatoire(95);
        Chargement(mat_aleatoire, A, dimLA, dimCA, nbrElemNNA);
        generer_mat_aleatoire(95);
        Chargement(mat_aleatoire, B, dimLB, dimCB, nbrElemNNB);
        Res = MULTIPLICATION(A, dimLA, dimCA, B, dimLB, dimCB);
        Affiche(Res, dimLRes, dimCRes);
    }
    else if(choix == 3)
    {
        generer_mat_aleatoire(95);
        Chargement(mat_aleatoire, A, dimLA, dimCA, nbrElemNNA);
        generer_mat_aleatoire(95);
        Chargement(mat_aleatoire, B, dimLB, dimCB, nbrElemNNB);
        Res = SOUSTRACTION(A, dimLA, dimCA, B, dimLB, dimCB);
        Affiche(Res, dimLRes, dimCRes);
    }
    else if(choix == 4)
    {
        generer_mat_aleatoire(95);
        Chargement(mat_aleatoire, A, dimLA, dimCA, nbrElemNNA);
        Res = TRANSPOSEE(A);
        Affiche(Res, dimLRes, dimCRes);
    }

        return 0;
}
	