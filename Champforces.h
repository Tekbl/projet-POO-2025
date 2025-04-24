#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
#include "affichage.h"
class ObjetPhysique;

class ChampForces : public Printable{
    public :
        
    virtual Vecteur force(const ObjetPhysique& obj, double t) const;

    private :
};


