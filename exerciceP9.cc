#include <vector>
#include <iostream>
#include "VecteurV.h"
#include "ChampForces.h"
#include "ForceCentrale.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"

void simulation(double temps, double interval_temps, unsigned int nb_affiche /*pour ne pas faire trop d'affichage*/){    
    Systeme sys;
    double rayon_terre = 6371e3;
    double altitude = 10;
    double masse_terre = 5.972e24;
    double masse_pomme = 0.1;
    //double g = (G * masse_terre) / (rayon_terre * rayon_terre);
    //double altitude_initiale = altitude;
    Vecteur position_terre(3);
    Vecteur vitesse_terre(3);
    Vecteur position_pomme(rayon_terre+altitude, 0, 0);
    Vecteur vitesse_pomme(3);
    PointMateriel pomme(position_pomme, vitesse_pomme, masse_pomme);
    PointMateriel terre(position_terre, vitesse_terre, masse_terre);
    ChampNewtonien TsurP(terre);
    ChampNewtonien PsurT(pomme);
    Libre libre;
    //Systeme sys({std::make_unique<PointMateriel>(pomme), std::make_unique<PointMateriel>(terre)},{std::make_unique<Libre>(libre)}, {std::make_unique<ChampNewtonien>(champ)});
    /*sys.affiche(std::cout);
    sys.evolve(1e-3);
    sys.affiche(std::cout);*/
    sys.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(pomme)));
    sys.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(terre)));
    sys.add_constraint(std::unique_ptr<Libre>(new Libre(libre)));
    sys.add_force_field(std::unique_ptr<ChampNewtonien>(new ChampNewtonien(TsurP)));
    sys.add_force_field(std::unique_ptr<ChampNewtonien>(new ChampNewtonien(PsurT)));
    sys.append_constraint(0, 0);
    sys.append_constraint(0, 1);
    //TextViewer txt(std::cout);
    //sys.dessine_sur(txt);
    double iteration = temps / interval_temps;
    sys.append_force_field(0,0);
    sys.append_force_field(1,1);
    for(int t = 0; t < iteration; t++){
        if(t%nb_affiche == 0){
            std::cout << "t = " << sys.get_time() << std::endl;
            // à faire la diff entre position de la (pomme + rayon_terre) - rayon terre pour avoir la distance
        }
        sys.evolve(interval_temps); 
    }
}

    
int main(){}