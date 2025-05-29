#include <vector>
#include <iostream>
#include <cmath>
#include "VecteurV.h"
#include "ChampForces.h"
#include "GravitationConstante.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"

#define M_PI 3.14159265358979323846

void corbeaurenard(double temps, double pas, unsigned int nb_iter, double precision = 1e-3){
    //Création du système
    Systeme sys;

    //paramètres
    double hauteur = 10;
    double distance = 10;
    double L2D2 = pow(distance, 2) + pow(hauteur, 2);
    //vitesse minimale pour avoir une collision d'après la formule trouvé dans l'exercice, v>sqrt(g*(distance^2 + hauteur^2/(2*hauteur)))
    double vitesse_initiale = sqrt(9.81 * (L2D2 / (2 * hauteur))) + 1e-3; //on rajoute une petite valeur pour être sûr d'avoir une collision
    //double vitesse_initiale = 10; //pour mettre une vitesse initiale arbitraire
    double tanangle = hauteur/distance;
    double angle = atan(tanangle); //déjà en radians
    //les masses n'influent pas sur le mouvement, mais on les met quand même
    double masse_fromage = 1;
    double masse_pierre = 1;
    double t_coll = sqrt(L2D2) / vitesse_initiale; //comme trouvé dans l'exercice
    
    // on mets les vecteurs à 3 dimensions car gravitation constante est faite pour avoir la gravité en z 
    Vecteur fromage(std::vector<double>{0, distance, hauteur});
    Vecteur pierre(3);
    Vecteur vitesse_pierre(std::vector<double>{0, vitesse_initiale*cos(angle), vitesse_initiale*sin(angle)});
    Vecteur vitesse_fromage(3);
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
    sys.append_constraint(0, 0);//on ajoute la contrainte libre au fromage
    sys.append_constraint(0, 1);//on ajoute la contrainte libre à la pierre
    sys.append_force_field(0, 0);//on ajoute le champ de force gravitationnel au fromage
    sys.append_force_field(0, 1);//on ajoute le champ de force gravitationnel à la pierre

    double iteration = temps / pas;

    for(int i = 0; i < iteration; i ++){
        if(i % nb_iter == 0){
            std::cout << "t = " << sys.get_time() << std::endl;
            sys.dessine_sur(txt);
            //sys.affiche(std::cout); 
        }
        
        if(std::abs(t_coll-sys.get_time()) < precision){
            std::cout << "Collision entre le fromage et la pierre à t = " << sys.get_time() << std::endl;
            sys.dessine_sur(txt);
            break; //on arrête la simulation à la collision
        }
        sys.evolve(pas);
    }


}

int main(){
    double temps = 5; //temps de la simulation en secondes
    double pas = 0.001; //pas de temps
    unsigned int nb_iter = 100; //limite le nombre d'affichage

    corbeaurenard(temps, pas, nb_iter);

    return 0;
}