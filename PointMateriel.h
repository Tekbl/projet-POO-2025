#pragma once
#include "VecteurV.h"
#include "constantes.h"

double masse;
Vecteur get_pos() const {return vecteur_position.vecteur;};
Vecteur get_vit() const {return vecteur_vitesse.vecteur;};
void set_pos(vector<double> a);
void set_vit(vector<double> a);
Vecteur ChampForces(g);
