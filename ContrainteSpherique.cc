#include <iostream>
#include "contrainte.h"
#include "ContrainteSpherique.h"
#include "VecteurV.h"
#include "affichage.h"

Vecteur ContrainteSpherique::position(const ObjetPhysique& obj) {
    //on considère que l'origine du repère est en (0,0,0)
    double teta = obj.get_E().get_coord(0);
    double phi = obj.get_E().get_coord(1);

    //on transforme les coordonnées sphérique en coordonnées cartésiennes avec z le long de g
    double x = rayon * sin(teta) * cos(phi);
    double y = rayon * sin(teta) * sin(phi);
    double z = -rayon * cos(teta);// pour qu'il soit dans le sens de g, on met un signe moins en considérant teta comme dans la figure 3 du complément
    return Vecteur(x, y, z);
}

Vecteur ContrainteSpherique::vitesse(const ObjetPhysique& obj) {
    //on considère que l'origine du repère est en (0,0,0)
    double teta = obj.get_E().get_coord(0);
    double phi = obj.get_E().get_coord(1);
    double teta_pr = obj.get_E_pr().get_coord(0);
    double phi_pr = obj.get_E_pr().get_coord(1);
    
    double x = rayon * (teta_pr * cos(teta) * cos(phi) - phi_pr * sin(teta) * sin(phi));
    double y = rayon * (teta_pr * cos(teta) * sin(phi) + phi_pr * sin(teta) * cos(phi));
    double z = rayon * teta_pr * sin(teta); // pas de signe - car on est dans le sens de g

    return Vecteur(x, y, z);
}

Vecteur ContrainteSpherique::applique_force(const ObjetPhysique& obj, Vecteur force, double t) {
    double teta = obj.get_E().get_coord(0);
    double phi = obj.get_E().get_coord(1);
    double teta_pr = obj.get_E_pr().get_coord(0);
    double phi_pr = obj.get_E_pr().get_coord(1);


    double teta_pr_pr = sin(teta)*cos(phi)*pow(teta_pr,2) + (1/(rayon*obj.get_masse()))*(force.get_coord(0) * cos(teta) * cos(phi) + force.get_coord(1) * sin(teta) * sin(phi) - force.get_coord(2) * sin(teta));
    double phi_pr_pr = 0;
    if(abs(teta) > 1e-10){
        double phi_pr_pr = -2*(cos(teta)/sin(teta))*teta_pr*phi_pr + (1/(rayon*obj.get_masse()*sin(teta)))*(-force.get_coord(0)*sin(phi)+force.get_coord(1)*cos(phi));
    }
    std::vector<double> force_appliquee = {teta_pr_pr, phi_pr_pr};
    return Vecteur(force_appliquee);
}