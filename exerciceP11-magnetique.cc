#include <vector>
#include <iostream>
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


ChampElectroMagnetique ElectroMag(Electro,Mag);
ChampFrottements frottements(lambda);
std::vector<ChampForces*> champs_;
champs_.push_back(&ElectroMag);
champs_.push_back(&frottements);

ChampCompose un_champ_de_ble(champs_);
std::vector<ChampForces*> champs;

champs.push_back(&un_champ_de_ble);

std::vector<Contrainte*> contraintes;
contraintes.push_back(&libre);

PointMateriel particule(pos,vit,q,m,3,champs,contraintes);

systeme.add_object(std::unique_ptr<ObjetPhysique>(new PointMateriel(particule)));
systeme.add_constraint(std::unique_ptr<Contrainte> (new Libre(libre)));
systeme.add_force_field(std::unique_ptr<ChampForces> (new ChampCompose(un_champ_de_ble)));

std::cout << "t \t x \t y \t z" <<std::endl;

for(int i(0); i<iter; i++){
    std::cout << systeme.get_time() <<"\t" << systeme.get_obj(0)->get_E().get_coord(0);
    std::cout << "\t" << systeme.get_obj(0)->get_E().get_coord(1) << "\t";
    std::cout << systeme.get_obj(0)->get_E().get_coord(2) << std::endl;
    systeme.evolve(dt);
}

systeme.dessine_sur(txt);

return 0;    
}


