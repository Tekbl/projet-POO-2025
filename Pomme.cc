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
using namespace std;

//VecteurV.o ObjetIntegrable.o constantes.o Champforces.o affichage.o PointMateriel.o Integrateurs.o GravitationConstante.o
int main(){
    

double rayon(6371e3);
double h(10);

double masse_pomme(0.1);
double masse_terre(5.972e24);

Vecteur pos_terre(0,0,0);
Vecteur pos_pomme(0,0,rayon+h);
Vecteur vit_terre(0,0,0);
Vecteur vit_pomme(0,0,0);

//Contrainte libre();

integrateurEulerCromer euler;
PointMateriel pomme(pos_pomme,vit_pomme,masse_pomme);
PointMateriel terre(pos_terre,vit_terre,masse_terre);

double t_chute = 10.0;
double dt = 0.2;



for(double t(0); t<t_chute; t+=dt){
euler.evolue(&pomme,t,dt);
cout << "temps : "<< t << endl;
cout << "hauteur : "<<pomme.get_E()-Vecteur(0,0,rayon);
cout << "vitesse :" << pomme.get_E_pr().norme() << endl;
cout << endl; 

}


/*

===============Constructeur Point Materiel================

PointMateriel::PointMateriel(
Vecteur E, 

Vecteur E_pr, 
double masse, 
unsigned int dim, 
const std::vector<ChampForces*>& c,
const std::vector<Contrainte*>& ctr)
:ObjetPhysique(E,E_pr,masse,dim)
{
        if(c.empty()){
            champ.push_back(new GravitationConstante());
        }else{ 
            champ = c;
        }

        if(ctr.empty()){
            contr.push_back(new Libre());
        }else{
            contr = ctr;
        }
    }

===============Constructeurs Vecteur======================
Vecteur(unsigned int dimension):vecteur(dimension,0.0){}
Vecteur(double x, double y, double z):vecteur{x,y,z}{}
    //initialise vecteur avec un vector de double de dimension quelconque,on le passe par référence constant pour ne pas créér de copies et ne pas faire de modifications sur le vector entré
    Vecteur(const std::vector<double>& liste_dinit):vecteur(liste_dinit){}

*/


}