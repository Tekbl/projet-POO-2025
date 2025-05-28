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
#include <fstream>
using namespace std;
 


int main(){

Vecteur position_initiale(0,0,1);
Vecteur vitesse_initiale(0,1,2);
double masse(5.0); //tout les objets chutent à la même vitesse donc j'ai mis une masse arbitraire

integrateurEulerCromer Euler;
RungeKutta4 Rk4;
Newmark New;

GravitationConstante gravite;

Libre libre; 

PointMateriel point(position_initiale,vitesse_initiale,masse);

point.add_champ(&gravite);
point.add_contr(&libre);

double t(0.0);
double dt(0.01);


do{
cout << "Temps : " << t << endl;
cout << point.position(point.get_contr()[0]) << " position " << endl;
cout << point.vitesse(point.get_contr()[0]) << " vitesse " << endl;
//Euler.evolue(&point,t,dt);
Rk4.evolue(&point,t,dt);
t+=dt;   

cout << endl;
}while(point.position(point.get_contr()[0]).get_coord(2)>0);


ofstream fichier_test;
fichier_test.open("test_integrateur_1",ios::in);
fichier_test<<;
return 0;
}