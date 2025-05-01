#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
#include "ObjetIntegrable.h"
#include "Champforces.h"

class GravitationConstante : public ChampForces{

    public :
        GravitationConstante(); 
        virtual Vecteur force(ObjetPhysique const& p, double t) const override;
        virtual void whoami(std::ostream& out)const override{out << "gravitation constante";}

    private :
        Vecteur gravitation;
};

