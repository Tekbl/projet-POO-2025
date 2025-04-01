#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"


class ChampForces{
    public :
        
    virtual Vecteur force(const ObjetPhysique& obj, double t) = 0;

    private :

};

