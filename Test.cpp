#include <iostream>
#include <string>
#include <map>
#include "libmatcreuse.h"
#include <unistd.h>



using namespace std;

int main()
{
    Matrice A("A",8,12);
    Matrice B("B",8,12);
    Matrice C("C",12,16);

    bool test(false);
    for(int i=0; i<8; ++i)
    {
        for(int j=0; j<12; ++j)
        {
            test = A.Insertion(i, j, i+j);
            test = B.Insertion(i, j, i*j);
        }
    }
    
    for(int i=0; i<12; ++i)
    {
        for(int j=0; j<16; ++j)
        {
            test = C.Insertion(i, j, i+j);
        }
    }
    test = A.Affichage();
    test = B.Affichage();
    test = C.Affichage();
    Matrice D = Addition("D",A,B);
    test = D.Affichage();
    Matrice E = Soustraction("E",B,A);
    test = E.Affichage();
    Matrice F = Multiplication("F",A,C);
    test = F.Affichage();
    Matrice G = Transposee("G",F);
    test = G.Affichage();

    return 0;
}
/*int main()
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
    bool test;

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
        test = Chargement(mat_aleatoire, A, dimLA, dimCA, nbrElemNNA);
        if(test == true)
        {
            generer_mat_aleatoire(95);
            test = Chargement(mat_aleatoire, B, dimLB, dimCB, nbrElemNNB);
            if(test == true)
            {
                Res = ADDITION(A, dimLA, dimCA, B, dimLB, dimCB);
                dimLRes = dimLA;
                dimCRes = dimCA;
                Affiche(A, dimLA, dimCA);
                cout << endl;
                Affiche(B, dimLB, dimCB);
                cout << endl;
                Affiche(Res, dimLRes, dimCRes);
            }
            else
            {
                cerr << "Erreur à l'ouverture" << endl;
            }
        }
        else
        {
            cerr << "Erreur à l'ouverture" << endl;
        }
    }
    else if(choix == 2)
    {
        generer_mat_aleatoire_taille_fixe(15,15,95);
        test = Chargement("Mat_aleatoire_fixe", A, dimLA, dimCA, nbrElemNNA);
        if(test == true)
        {
            generer_mat_aleatoire_taille_fixe(15,15,95);
            test = Chargement("Mat_aleatoire_fixe", B, dimLB, dimCB, nbrElemNNB);
            if(test == true)
            {
                Res = MULTIPLICATION(A, dimLA, dimCA, B, dimLB, dimCB);
                if(dimCA == dimLB)
                {
                    dimLRes = dimLA;
                    dimCRes = dimCB;
                    Affiche(A, dimLA, dimCA);
                    cout << endl;
                    Affiche(B, dimLB, dimCB);
                    cout << endl;
                    Affiche(Res, dimLRes, dimCRes);
                }
                else
                {
                    Affiche(A, dimLA, dimCA);
                    cout << endl;
                    Affiche(B, dimLB, dimCB);

                    cerr << "Multiplication impossible !" <<endl;
                }
            }
            else
            {
                cerr << "Erreur à l'ouverture" << endl;
            }
        }
        else
        {
            cerr << "Erreur à l'ouverture" << endl;
        }
    }
    else if(choix == 3)
    {
        generer_mat_aleatoire(95);
        test = Chargement(mat_aleatoire, A, dimLA, dimCA, nbrElemNNA);
        if(test == true)
        {
            generer_mat_aleatoire(95);
            test = Chargement(mat_aleatoire, B, dimLB, dimCB, nbrElemNNB);
            if(test == true)
            {
                Res = SOUSTRACTION(A, dimLA, dimCA, B, dimLB, dimCB);
                dimLRes = dimLA;
                dimCRes = dimCA;
                Affiche(A, dimLA, dimCA);
                cout << endl;
                Affiche(B, dimLB, dimCB);
                cout << endl;
                Affiche(Res, dimLRes, dimCRes);
            }
            else
            {
                cerr << "Erreur à l'ouverture" << endl;
            }
        }
        else
        {
            cerr << "Erreur à l'ouverture" << endl;
        }
    }
    else if(choix == 4)
    {
        generer_mat_aleatoire(95);
        test = Chargement(mat_aleatoire, A, dimLA, dimCA, nbrElemNNA);
        if(test == true)
        {
            Res = TRANSPOSEE(A);
            Affiche(A, dimLA, dimCA);
            cout << endl;
            Affiche(Res, dimCA, dimLA);
            

        }
        else
        {
            cerr << "Erreur à l'ouverture" << endl;
        }

    }

        return 0;
}*/
	