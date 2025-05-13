#include <vector>
#include <iostream>
#include <cmath>
#include "VecteurV.h"
#include "ChampForces.h"
#include "GravitationConstante.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"

void corbeaurenard(double pas, unsigned int nb_iter){
    //Création du système
    Systeme sys;

    //paramètres
    double hauteur = 10;
    double distance = 10;
    double vitesse_initiale = 5;
    double angle = 30.0 * M_PI / 180.0; //en radians
    //les masses n'influent pas sur le mouvement, mais on les met quand même
    double masse_fromage = 1;
    double masse_pierre = 1;
    double t_coll = sqrt(pow(distance, 2) + pow(hauteur, 2)) / vitesse_initiale; //comme trouvé dans l'exercice
    Vecteur fromage({distance, hauteur});
    Vecteur pierre({0, 0});
    Vecteur vitesse_pierre({vitesse_initiale*cos(angle), vitesse_initiale*sin(angle)});
    Vecteur vitesse_fromage({0, 0});
    PointMateriel fromage_objet(fromage, vitesse_fromage, masse_fromage);
    PointMateriel pierre_objet(pierre, vitesse_pierre, masse_pierre);

    //contraintes
    Libre libre;

    //champ de force
    GravitationConstante gravitation;

    //mode d'affichage
    TextViewer txt(std::cout);

    //ajout des objets, contraintes et champs de force au système
    sys.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(fromage_objet)));
    sys.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(pierre_objet)));
    sys.add_constraint(std::unique_ptr<Libre>(new Libre(libre)));
    sys.add_force_field(std::unique_ptr<GravitationConstante>(new GravitationConstante(gravitation)));
    sys.append_constraint(0, 0);
    sys.append_constraint(0, 1);
    sys.append_force_field(0, 0);
    sys.append_force_field(0, 1);

    for(int i = 0; i < t_coll; i++){
        if(i % nb_iter == 0){
            std::cout << "t = " << sys.get_time() << std::endl;
            sys.dessine_sur(txt);
            //sys.affiche(std::cout); 
        }
        sys.evolve(pas);
    }


}

int main(){
    double pas = 0.01; //pas de temps
    unsigned int nb_iter = 100; //limite le nombre d'affichage

    corbeaurenard(pas, nb_iter);

    return 0;
}