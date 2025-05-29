#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
#include "constantes.h"
#include "contrainte.h"
#include "Champforces.h"
#include "affichage.h"
#include "PointMateriel.h"
#include "GravitationConstante.h"
#include "Integrateurs.h"
using namespace std;
 
//VecteurV.o ObjetIntegrable.o constantes.o contrainte.o Champforces.o affichage.o PointMateriel.o GravitationConstante.o Integrateurs.o


int main(){

vector<double> x1,y1,z1;
vector<double> x2,y2,z2;
vector<double> x3,y3,z3;


Vecteur position_initiale(0,0,1);
Vecteur vitesse_initiale(0,1,2);
double masse(5.0); //tout les objets chutent à la même vitesse donc j'ai mis une masse arbitraire

integrateurEulerCromer Euler;
RungeKutta4 Rk4;
Newmark New;

GravitationConstante gravite;

Libre libre; 

PointMateriel point1(position_initiale,vitesse_initiale,masse);
PointMateriel point2(position_initiale,vitesse_initiale,masse);
PointMateriel point3(position_initiale,vitesse_initiale,masse);

point1.add_champ(&gravite);
point1.add_contr(&libre);

point2.add_champ(&gravite);
point2.add_contr(&libre);

point3.add_champ(&gravite);
point3.add_contr(&libre);

double t(0.0);
double dt(0.01);


do{
cout << "Temps : " << t << endl;
cout <<"\tEuler : " <<point1.position(point1.get_contr()[0]) << " position " << endl;
cout << "\tRungeKutta4 : " << point2.position(point2.get_contr()[0]) << " position " << endl;
cout << "\tNewmark : " << point3.position(point3.get_contr()[0]) << " position " << endl;

Euler.evolue(&point1,t,dt);
Rk4.evolue(&point2,t,dt);
New.evolue(&point3,t,dt);


x1.push_back(point1.get_E().get_coord(0));
y1.push_back(point1.get_E().get_coord(1));
z1.push_back(point1.get_E().get_coord(2));

x2.push_back(point2.get_E().get_coord(0));
y2.push_back(point2.get_E().get_coord(1));
z2.push_back(point2.get_E().get_coord(2));

x3.push_back(point3.get_E().get_coord(0));
y3.push_back(point3.get_E().get_coord(1));
z3.push_back(point3.get_E().get_coord(2));

t+=dt;   

cout << endl;
}while( (point1.position(point1.get_contr()[0]).get_coord(2)>0) and (point2.position(point2.get_contr()[0]).get_coord(2)>0) and point3.position(point3.get_contr()[0]).get_coord(2)>0);



ofstream fichier_test;
fichier_test.open("test_integrateur_2.dat",ios::out);

for(int i(0); i<x1.size();i++){

    fichier_test<< 
    x1[i] << " " << y1[i] << " " << z1[i] << " " <<
    x2[i] << " " << y2[i] << " " << z2[i] << " " <<
    x3[i] << " " << y3[i] << " " << z3[i] << "\n" ;

}

fichier_test.close();


ofstream graphe("graphe3D_testIntegrateur2.gp");
graphe << " set title \"Comparaison Euler, RungeKutta et Newmark pour un point materiel dans une trajectoire parabolique\" \n";
graphe << "set xlabel \"X\" \n";
graphe << "set ylabel \"Y\" \n";
graphe << "set zlabel \"Z\" \n";
graphe << "set grid\n";
graphe << "set ticslevel 0\n";
graphe << "splot \\\n";
graphe << "  \"test_integrateur_2.dat\" using 1:2:3 with linespoints lt rgb \"red\" pt 9 ps 0.8 lw 1.2 title \"Euler\", \\\n";
graphe << "  \"test_integrateur_2.dat\" using 4:5:6 with linespoints lt rgb \"blue\" pt 9 ps 0.8 lw 1.2 title \"RungeKutta4\", \\\n";
graphe << "  \"test_integrateur_2.dat\" using 7:8:9 with linespoints lt rgb \"green\" pt 9 ps 0.8 lw 1.2 title \"Newmark\"\n";
graphe << "pause -1\n";
graphe.close();
system("gnuplot graphe3D_testIntegrateur2.gp");

return 0;
}