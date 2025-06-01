#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
#include "constantes.h"
#include "contrainte.h"
#include "Champforces.h"
#include "affichage.h"
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "Integrateurs.h"
#include "ForceCentrale.h"
using namespace std;

//VecteurV.o ObjetIntegrable.o constantes.o Champforces.o affichage.o PointMateriel.o Integrateurs.o GravitationConstante.o ForceCentrale.o
int main(){
    
//initialisation des constantes et des objets
double rayon(6371e3);
double h(10);

double masse_pomme(0.1);
double masse_terre(5.972e24);

Vecteur pos_terre(0,0,-rayon);
Vecteur pos_pomme(0,0,h);
Vecteur vit_terre(0,0,0);
Vecteur vit_pomme(0,0,0);

Libre libre;

integrateurEulerCromer euler;
PointMateriel pomme(pos_pomme,vit_pomme,masse_pomme);
PointMateriel terre(pos_terre,vit_terre,masse_terre);

ChampNewtonien champ_pomme(pomme);
ChampNewtonien champ_terre(terre);

pomme.add_contr(&libre);
pomme.add_champ(&champ_terre);
terre.add_champ(&champ_pomme);

double t_chute = 30.0;
double dt = 0.2;



for(double t(0); t<t_chute; t+=dt){
//cout << pomme.get_E() << endl;
//cout << "vitesse :" << pomme.get_E_pr().norme() << endl;

cout << "temps : "<< t << endl;
cout << pomme << endl;
euler.evolue(&pomme,t,dt);

}





}