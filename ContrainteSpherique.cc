#include <iostream>
#include "contrainte.h"
#include "ContrainteSpherique.h"
#include "VecteurV.h"
#include "affichage.h"

Vecteur ContrainteSpherique::position(const ObjetPhysique& obj) {
    //on considère que l'origine du repère est en (0,0,0)
    double theta = obj.get_E().get_coord(0);
    double phi = obj.get_E().get_coord(1);

    //on transforme les coordonnées sphérique en coordonnées cartésiennes
    double x = rayon * sin(theta) * cos(phi);
    double y = rayon * sin(theta) * sin(phi);
    double z = rayon * cos(theta);//z dans le sens de g
    return Vecteur(x, y, z);
}

Vecteur ContrainteSpherique::vitesse(const ObjetPhysique& obj) {
    //on considère que l'origine du repère est en (0,0,0)
    double theta = obj.get_E().get_coord(0);
    double phi = obj.get_E().get_coord(1);
    double theta_pr = obj.get_E_pr().get_coord(0);
    double phi_pr = obj.get_E_pr().get_coord(1);
    
    //formules données dans l'annexe
    double x = rayon * (theta_pr * cos(theta) * cos(phi) - phi_pr * sin(theta) * sin(phi));
    double y = rayon * (theta_pr * cos(theta) * sin(phi) + phi_pr * sin(theta) * cos(phi));
    double z = -rayon * theta_pr * sin(theta); //on fait comme dans l'annexe, ou z est dans le sens de g

    return Vecteur(x, y, z);
}

Vecteur ContrainteSpherique::applique_force(const ObjetPhysique& obj, Vecteur force, double t) {
    //déclarations des angles et de leurs dérivées
    double theta = obj.get_E().get_coord(0);
    double phi = obj.get_E().get_coord(1);
    double theta_pr = obj.get_E_pr().get_coord(0);
    double phi_pr = obj.get_E_pr().get_coord(1);

    double ulm = 1/(rayon*obj.get_masse());
    double coteta = cos(theta)/sin(theta);

    //formules des dérivées secondes de theta et phi
    double theta_pr_pr = sin(theta)*cos(theta)*phi_pr*phi_pr + ulm*(force.get_coord(0) * cos(theta) * cos(phi) + force.get_coord(1) * cos(theta) * sin(phi) + force.get_coord(2) * sin(theta));
    double phi_pr_pr = 0;
    if(abs(theta) > 1e-10){
        phi_pr_pr = -2*coteta*theta_pr*phi_pr + (ulm * (1/sin(theta)))*(-force.get_coord(0)*sin(phi)+force.get_coord(1)*cos(phi));
    }
    std::vector<double> force_appliquee = {theta_pr_pr, phi_pr_pr};
    return Vecteur(force_appliquee);
}