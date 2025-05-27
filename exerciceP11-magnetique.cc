#include <vector>
#include <iostream>
#include <iomanip>
#include "VecteurV.h"
#include "affichage.h"
#include "ChampForces.h"
#include "ObjetIntegrable.h"
#include "ForceCentrale.h"
#include "Integrateurs.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "SupportADessin.h"
#include "ObjetDessinable.h"
#include "ChampSupplementaires.h"
#include "contrainte.h"

//VecteurV.o affichage.o ObjetIntegrable.o ChampForces.o ForceCentrale.o Systeme.o PointMateriel.o ObjetDessinable.o ChampSupplementaires.o contrainte.o

int main(){

Systeme systeme;

Vecteur Mag(0,0,0.5);
Vecteur Electro(0,0,0);
double lambda(1.33e-5);
Libre libre; 
double m = 1.5e-4;   
double q = 2e-6;
Vecteur pos(0,0,0);
Vecteur vit(0.3,0,0);

double t_simu = 0.4;
double dt = 0.001;
int iter = t_simu/dt;

TextViewer txt(std::cout);
integrateurEulerCromer euler;
RungeKutta4 Rk4;
Newmark New;


ChampElectroMagnetique ElectroMag(Electro,Mag);
ChampFrottements frottements(lambda);
std::vector<ChampForces*> champs_;
champs_.push_back(&ElectroMag);
champs_.push_back(&frottements);

ChampCompose un_champ_de_ble(champs_);
//std::vector<ChampForces*> champs;

//champs.push_back(&un_champ_de_ble);

//std::vector<Contrainte*> contraintes;
//contraintes.push_back(&libre);

/*PointMateriel particule(pos,vit,q,m,3,champs,contraintes);//le probleme est que le constructeur de point materiel
ne rajouter pas champs et contraintes. parce que le constructeur utilise le constructeur de ObjetPhysique dans lequel on ne construit pas
les champs et les contraintes à l'initialisation....
particule.add_champ(champs);
particule.add_contr(contraintes);
*/

PointMateriel particule(pos,vit,m,q,3);
particule.add_champ(&un_champ_de_ble);
particule.add_contr(&libre);

systeme.add_object(std::unique_ptr<ObjetPhysique>(new PointMateriel(particule)));
systeme.add_constraint(std::unique_ptr<Contrainte> (new Libre(libre)));
//systeme.add_force_field(std::unique_ptr<ChampForces> (new ChampCompose(un_champ_de_ble)));
systeme.change_integrator(std::unique_ptr<integrateur>(new RungeKutta4(Rk4)));
//systeme.change_integrator(std::unique_ptr<integrateur>(new Newmark(New)));

//systeme.get_champ(0)->force(*(systeme.get_obj(0)), 2);
std::cout << "Methode d'integration : " ;
systeme.display_integrator(std::cout);
std::cout << std::endl;

/*
std::cout << std::setw(0) << "t" << 
std::setw(8) << "x"<<
std::setw(17) << "y" <<
std::setw(19) << "z" <<std::endl;
*/

 
std::cout << std::left << std::setw(10) << "t"
<< std::left << std::setw(15) << "x"
<< std::left <<std::setw(15) << "y"
<< "z" << "\n";

for(int i(0); i<iter; i++){
    std::cout 
    << std::left << std::setw(5) <<std::setprecision(5) <<systeme.get_time() << "     " 

    << std::left << std::setw(10)<< systeme.get_obj(0)->get_E().get_coord(0) << "     ";

    std::cout  
    << std::left << std::setw(12) << systeme.get_obj(0)->get_E().get_coord(1) << "   ";
    std::cout 
    << std::left << std::setw(5) << systeme.get_obj(0)->get_E().get_coord(2) << std::endl;

    systeme.evolve(dt);
}

std::cout << std::endl;
systeme.dessine_sur(txt);

return 0;    
}


