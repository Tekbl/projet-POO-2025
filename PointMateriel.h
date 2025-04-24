#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
#include "ObjetIntegrable.h"
#include "affichage.h"

class PointMateriel: public ObjetPhysique{
public:
    PointMateriel(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, double masse = 0, unsigned int dim = 3, const std::vector<ChampForces*>& c = std::vector<ChampForces*>{},
    const std::vector<Contrainte*>& ctr = std::vector<Contrainte*>{});
    /*Vecteur get_pos(int i) const { return vecteur_position.get_coord(i); }
    Vecteur get_vit(int i) const { return vecteur_vitesse.get_coord(i); }
    void set_pos(std::vector<double> a);
    void set_vit(std::vector<double> a);*/
    virtual Vecteur evolution(double t) override;
    virtual void affiche(std::ostream& sortie)const override;

private:
    /*Vecteur vecteur_position; 
    Vecteur vecteur_vitesse;*/
};

