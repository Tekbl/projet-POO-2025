#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
#include "affichage.h"
#include "contrainte.h"
using namespace std;


Vecteur Libre::applique_force(const ObjetPhysique& obj, Vecteur force, double t){
    //F = m * a <=> a = F/m
    if(obj.get_masse()>0){
        return force * (1/obj.get_masse()); //a = f/m
    }else{
        return force;
    }
}

Vecteur Libre::position(const ObjetPhysique& obj){ //la contrainte libre ne fait rien
    return obj.get_E();
}

Vecteur Libre::vitesse(const ObjetPhysique& obj){ //la contrainte libre ne fait rien
    return obj.get_E_pr();
}
