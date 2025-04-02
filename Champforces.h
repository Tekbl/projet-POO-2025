#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
class ObjetPhysique;

class ChampForces{
    public :
        
    Vecteur force(const ObjetPhysique& obj, double t);

    private :
};


