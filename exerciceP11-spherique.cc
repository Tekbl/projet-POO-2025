#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ChampForces.h"
#include "ObjetIntegrable.h"
#include "GravitationConstante.h"
#include "ContrainteSpherique.h"
#include "systeme.h"
#include "PointMateriel.h"
#include "SupportADessin.h"
#include "Integrateurs.h"
#include "ObjetDessinable.h"

#define M_PI 3.14159265358979323846

void simul_spherique(double temps, double pas, unsigned int nb_iter){
    Systeme systeme;

    //RungeKutta4 Rk4;

    //systeme.change_integrator(std::unique_ptr<integrateur>(new RungeKutta4(Rk4)));
    double longueur = 2.2; 

    //initialisation du pendule 
    std::vector<double> pos_init = {M_PI/6,0};//teta=M_PI/6, phi=0
    std::vector<double> vit_init = {0,1};//teta'=0, phi'=1
    //on itnitialise le pendule avec une position initiale une vitesse initiale, une masse de 0.1, pas de charge éléctrique et un degré de liberté de 2 
    PointMateriel_angulaire pendule(Vecteur(pos_init), Vecteur(vit_init),0.1,0,2);

    //contrainte
    ContrainteSpherique contrainte(longueur);

    //champ de force
    GravitationConstante gravitation;

    // mode d'affichage
    TextViewer txt(std::cout);

    ContrainteSpherique* ptc = &contrainte;

    systeme.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(pendule)));
    systeme.add_constraint(std::unique_ptr<Contrainte>(new ContrainteSpherique(contrainte)));
    systeme.add_force_field(std::unique_ptr<ChampForces>(new GravitationConstante(gravitation)));

    systeme.append_constraint(0, 0);//on ajoute la contrainte sphérique au pendule
    systeme.append_force_field(0, 0);//on ajoute le champ de force gravitationnel au pendule

    double iteration = temps / pas;

    //std::cout << systeme.get_obj(0)->get_E() << std::endl; //affichage de l'état initial du pendule

    //std::cout << systeme.get_obj(0)->position(new ContrainteSpherique(contrainte)) << std::endl; //affichage de la position initiale du pendule
    //std::cout << systeme.get_obj(0)->vitesse(new ContrainteSpherique(contrainte)) << std::endl; //affichage de la vitesse initiale du pendule
    //std::cout << *systeme.get_obj(0) << std::endl;
    //std::cout << systeme.get_obj(0)->evolution(temps) << std::endl; //affichage de l'évolution du pendule à t=0
    //std::cout << systeme << std::endl; //affichage de l'état du système
    //systeme.dessine_sur(txt); //affichage du pendule
    std::cout << "Methode d'integration : " ;
    systeme.display_integrator(std::cout);
    std::cout << std::endl;

    std::cout << std::left << std::setw(10) << "t" << std::left << std::setw(22) << "x" << std::left <<std::setw(22) << "y" << "z" << "\n";
    for(int i = 0; i <= iteration; i++){
        if(i % nb_iter == 0){
                /*std::cout << systeme.get_obj(0)->get_E() << std::endl; //affichage de l'état du pendule
                std::cout << systeme.get_obj(0)->get_E_pr() << std::endl; //affichage de la vitesse du pendule
                std::cout << "t = " << systeme.get_time() << std::endl;
                systeme.dessine_sur(txt);*/
                std::cout 
                << std::left << std::setw(5) << std::setprecision(5) <<systeme.get_time() << "     " 

                << std::left << std::setw(17)<< std::setprecision(16) << systeme.get_obj(0)->position(ptc).get_coord(0) << "     ";

                std::cout  
                << std::left << std::setw(19) << std::setprecision(16) << systeme.get_obj(0)->position(ptc).get_coord(1) << "   ";
                std::cout 
                << std::left << std::setw(5) << std::setprecision(16) << systeme.get_obj(0)->position(ptc).get_coord(2) << std::endl;
            } 
        systeme.evolve(pas);
    }
    std::cout << std::setprecision(4) << std::endl;
    systeme.dessine_sur(txt); //affichage du pendule à la fin de la simulation

    delete ptc; //on supprime le pointeur pour éviter les fuites de mémoire
}

int main(){
    double temps = 0.1; //temps de la simulation en secondes
    double pas = 0.001; //pas de temps
    unsigned int nb_iter = 10; //limite le nombre d'affichage

    simul_spherique(temps, pas, nb_iter);

    return 0;
}