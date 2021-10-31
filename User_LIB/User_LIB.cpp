// Vecteur3D.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//#include "Vecteur3D.h"
//#include "Matrice.h"
#include <iostream>
#include "Vecteur3D.h"
#include "Matrice.h"
using namespace vecteur;
using namespace traitMatrice;
using namespace std;
int main()
{
    Vecteur3D v1(1, 2, 3), v2(1, 1, 1);
    Vecteur3D* v3 = new Vecteur3D();
    v1.print();
    v3 = v1 * 3;
    v3->print();
    float k = v1 * v2;
    cout << "\nle produit scalaire de v1 et v2 est :" << k << ".\n";
    k = ~v1;
    cout << "\nla norme du v1 est :" << k << ".\n";
    cout << "\nle produit de v1 et v2 est :" << ".\n";
    v3 = v1 ^ v2;
    v3->print();
    cout << "\nla somme  de v1 et v2 est :" << ".\n";
    v3 = v1 + v2;
    v3->print();
    cout << "\nla division du v1 par 3 est :" << k << ".\n";
    v3 = v1 / 3;
    v3->print();
    /*std::cout << "\n****************************Traitement de la matrice\n";
    Matrice l(2,3),m(2,3);
    Matrice *k= new Matrice(2, 3);
    l.remplissage(2);
    m.remplissage(3);
    k = l-m;
    l.print();
    printf("\n****************\n");
    m.print();
    printf("\n****************\n");
    k->print();*/
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
