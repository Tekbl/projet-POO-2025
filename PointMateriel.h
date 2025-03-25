#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"

class PointMateriel {
public:
    double masse;
    Vecteur get_pos(int i) const { return vecteur_position.get_coord(i); }
    Vecteur get_vit(int i) const { return vecteur_vitesse.get_coord(i); }
    void set_pos(std::vector<double> a);
    void set_vit(std::vector<double> a);
    Vecteur evolution(double t) const;
    Vecteur ChampForces = g; 
    friend std::ostream& operator<<(std::ostream& sortie, const PointMateriel& p);
    Vecteur position(); 
    Vecteur vitesse();

private:
    Vecteur vecteur_position; 
    Vecteur vecteur_vitesse; 
};
