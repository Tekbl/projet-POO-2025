#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
#include "ObjetIntegrable.h"
#include "ChampForces.h"

class GravitationConstante : public ChampForces{

    public :
        GravitationConstante():gravitation(g){}//constructeur par defaut qui utilise g
    
        virtual Vecteur force(ObjetPhysique const& p, double t) const override;
        virtual void whoami(std::ostream& out)const override{out << "gravitation constante";}
        virtual void affiche(std::ostream& out)const override{whoami(out);}
        virtual ~GravitationConstante();

    private :
        Vecteur gravitation;
};

