/**
 * \file    : main.cpp
 * \version : 1.0.0
 * \author  : Fabien Léger
 * \date    : 04.10.2024
 * \brief   : Afficheur de nombres premiers dans une plage de valeurs
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    const int limiteMin = 2,
              limiteMax = 1000;

    int limite, // limite donnée par l'utilisateur
        countColonnes,
        nbColonnes = 5;

    char restart;

    cout << "Ce programme sert a trouver tous les nombres premiers "
         << "jusqu'a une limite (comprise) fixee par l'utilisateur." << endl;

    do {
        countColonnes = 0;
        // saisie utilisateur
        do {
            cout << endl;
            cout << "Veuillez entrer la limite (2 <= n <= 1'000) : ";
            cin >> limite;
        } while (limite < limiteMin || limite > limiteMax);

        // calcul algorithmique
        cout << endl;
        for (int i=2; i<=limite; ++i) {
            for(int j=2; (i%j!=0 || j==i) && j<=i; ++j) {
                if (j==i) {
                    ++countColonnes;

                    cout << '\t' << i << " ";
                    if (countColonnes%nbColonnes==0) { cout << endl; }
                }
            }
        }

        // restart
        do {
            cout << endl;
            cout << "Voulez-vous recommencer [O/N] :";
            cin >> restart;
        } while (!(restart == 'O' || restart == 'N'));
    } while (restart == 'O');

    cout << endl
         << "Fin du programme..." << endl;

    return EXIT_SUCCESS;
}
