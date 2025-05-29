#include <iostream>
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

    double rayon = 2.2; 

    //initialisation du pendule 
    std::vector<double> pos_init(M_PI/6,0);//teta=M_PI/6, phi=0
    std::vector<double> vit_init(0,1);//teta*=0, phi*=1
    //on itnitialise le pendule avec une position initiale une vitesse initiale, une masse de 0.1, pas de charge éléctrique et un degré de liberté de 2 
    PointMateriel pendule(Vecteur(pos_init), Vecteur(vit_init),0.1,0,2);

    //contrainte
    ContrainteSpherique contrainte(rayon);

    //champ de force
    GravitationConstante gravitation;

    // mode d'affichage
    TextViewer txt(std::cout);

    systeme.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(pendule)));
    systeme.add_constraint(std::unique_ptr<Contrainte>(new ContrainteSpherique(contrainte)));
    systeme.add_force_field(std::unique_ptr<ChampForces>(new GravitationConstante(gravitation)));

    systeme.append_constraint(0, 0);//on ajoute la contrainte sphérique au pendule
    systeme.append_force_field(0, 0);//on ajoute le champ de force gravitationnel au pendule

    double iteration = temps / pas;

    for(int i = 0; i < iteration; i++){
        if(i % nb_iter == 0){
                std::cout << "t = " << systeme.get_time() << std::endl;
                systeme.dessine_sur(txt);
                //sys.affiche(std::cout); 
            } 
        systeme.evolve(pas);
    }

}

int main(){
    double temps = 5; //temps de la simulation en secondes
    double pas = 0.001; //pas de temps
    unsigned int nb_iter = 100; //limite le nombre d'affichage

    simul_spherique(temps, pas, nb_iter);

    return 0;
}