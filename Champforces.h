#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
class ObjetPhysique;

class ChampForces{
    public :
        
    virtual Vecteur force(const ObjetPhysique& obj, double t) const;

    private :
};


