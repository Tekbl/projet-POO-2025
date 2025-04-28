#include <vector>
#include <iostream>
#include "VecteurV.h"
#include "ChampForces.h"
#include "ForceCentrale.h"
#include "systeme.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"
//modif unique_ptr en ptr 

int main(){
    PointMateriel pomme({0,0,0},{0,0,0},0.1);
    PointMateriel terre({0,0,6371.01e3},{0,0,0},5.972e24);
    ChampNewtonien champ(terre);
    Libre libre;
    Systeme sys({std::make_unique<PointMateriel>(pomme), std::make_unique<PointMateriel>(terre)},{std::make_unique<Libre>(libre)}, {std::make_unique<ChampNewtonien>(champ)});
    sys.affiche(std::cout);
    sys.evolve(1e-3);
    sys.affiche(std::cout);

    //TextViewer txt(std::cout);
    //sys.dessine_sur(txt);
}