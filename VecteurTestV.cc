#include <iostream>
#include "VecteurV.h"
#include "affichage.h"
using namespace std;


int main(){
    // Test 1: Création de vecteurs
    Vecteur v1(3);          // Vecteur de dimension 3, initialisé avec 0.0
    Vecteur v2(1.0, 2.0, 3.0);  // Vecteur 3D (1, 2, 3)
    vector<double> liste = {4.0, 5.0, 6.0};
    Vecteur v3(liste);  // Vecteur de dimension 3 (4, 5, 6)

    // Test 2: Affichage de vecteurs
    cout << "Vecteur v1: ";
    v1.affiche(cout);
    cout << "Vecteur v2: ";
    v2.affiche(cout);
    cout << "Vecteur v3: ";
    v3.affiche(cout);

    // Test 3: Addition de vecteurs
    Vecteur v4 = v2 + v3;
    cout << "v2 + v3 = ";
    v4.affiche(cout);

    // Test 4: Soustraction de vecteurs
    Vecteur v5 = v3 - v2;
    cout << "v3 - v2 = ";
    v5.affiche(cout);

    // Test 5: Produit scalaire
    double prod = v2.prod_scalaire(v3);
    cout << "Produit scalaire de v2 et v3: " << prod << endl;

    // Test 6: Multiplication par un scalaire
    Vecteur v6 = v2 * 2.0;
    cout << "v2 * 2 = ";
    v6.affiche(cout);

    // Test 7: Vecteur unitaire
    Vecteur v7 = (~v2);  // Vecteur unitaire de v2
    cout << "Vecteur unitaire de v2: ";
    v7.affiche(cout);

    // Test 8: Comparaison de vecteurs
    if (v2 == v3) {
        cout << "v2 est égal à v3" << endl;
    } else {
        cout << "v2 est différent de v3" << endl;
    }

    // Test 9: Opposé d'un vecteur
    Vecteur v8 = v3.oppose();
    cout << "Opposé de v3: ";
    v8.affiche(cout);

    cout << v8;

    v8.whoami(cout);

    return 0;
}
