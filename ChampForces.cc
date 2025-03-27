#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"


class ChampForces{
    public :
        
    Vecteur force(const ObjetPhysique& obj, double t);

    private :
};


Vecteur ChampForces::force(const ObjetPhysique& obj, double t){
    return obj.force(t);

}