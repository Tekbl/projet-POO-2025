#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
#include "constantes.h"
#include "contrainte.h"
#include "ChampForces.h"
#include "affichage.h"
#include "PointMateriel.h"
#include "GravitationConstante.h"
// VecteurV.o ObjetIntegrable.o constantes.o contrainte.o Champforces.o affichage.o PointMateriel.o GravitationConstante.o

int main(){

GravitationConstante g_terre;
Libre libre;
Vecteur pos1(1,3,2);
Vecteur pos2(2,3,10);
Vecteur vit_nulle(0,0,0);
Vecteur vit2(1,-10,0.2);

//initialisation des points matériels
PointMateriel p1(pos1, vit_nulle, 1, 0, 3);
PointMateriel p2(pos1,vit2,1,0,3);
//ajout des champs de force et des contraintes
p1.add_champ(&g_terre);
p1.add_contr(&libre);
p2.add_champ(&g_terre);
p2.add_contr(&libre);

//test de l'affichage
p1.affiche(std::cout);
std::cout << "force :" << p1.force(&g_terre, 0) << std::endl;
std::cout << "\n" << std::endl;
p2.affiche(std::cout);
std::cout << "force :" << p2.force(&g_terre, 0) << std::endl;

return 0;
}