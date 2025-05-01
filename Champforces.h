#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "affichage.h"
class ObjetPhysique;

class ChampForces : public Printable{
    public :
        
    virtual Vecteur force(const ObjetPhysique& obj, double t) const = 0;
    virtual void affiche(std::ostream& out)const override;//blank for now since we have no use for it

    private :
};


