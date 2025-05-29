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
 
//VecteurV.o ObjetIntegrable.o constantes.o contrainte.o Champforces.o affichage.o PointMateriel.o GravitationConstante.o Integrateurs.o

int main(){
vector<double> x_pos;
vector<double> y_pos; //pour sauvegarder les données de la simulation
vector<double> z_pos;


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
cout << point.position(point.get_contr()[0]) << " position " << endl; //affichage sur le terminal
cout << point.vitesse(point.get_contr()[0]) << " vitesse " << endl;

x_pos.push_back(point.get_E().get_coord(0));
y_pos.push_back(point.get_E().get_coord(1)); //sauvegarde des données
z_pos.push_back(point.get_E().get_coord(2));

//Euler.evolue(&point,t,dt); //pour utiliser Euler
Rk4.evolue(&point,t,dt); //mettre en commentaire pour utiliser Euler
t+=dt;   

cout << endl;
}while(point.position(point.get_contr()[0]).get_coord(2)>0); //on simule tant que le point est au dessus du sol


ofstream fichier_test; //création du fichier de sauvegarde
fichier_test.open("test_integrateur_1.dat",ios::out);

for(int i(0); i<x_pos.size();i++){

    fichier_test<< x_pos[i] << " " << y_pos[i] << " " << z_pos[i] << "\n" ;

}

fichier_test.close(); 


ofstream graphe("graphe3D_testIntegrateur1.gp");
//graphe.open("graphe3D_testIntegrateur1.gp",ios::out);
graphe << " set title \"Trajectoire 3D du point materiel\" \n";
graphe << "set xlabel \"X\" \n";
graphe << "set ylabel \"Y\" \n";
graphe << "set zlabel \"Z\" \n";
graphe << "set grid\n";
graphe << "set ticslevel 0\n";
graphe << "splot \"test_integrateur_1.dat\" using 1:2:3 with lines title \"Trajectoire\"\n";
graphe << "pause -1\n";
graphe.close();
system("gnuplot graphe3D_testIntegrateur1.gp");

return 0;
}