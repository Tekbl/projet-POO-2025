#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "PointMateriel.h"
#include "constantes.h"
#include "ObjetIntegrable.h"
#include "Champforces.h"

class GravitationConstante : public ChampForces{

    public :
        GravitationConstante(); 
        virtual Vecteur force(ObjetPhysique const& p, double t) const override;
    

    private :
        Vecteur gravitation;
};

