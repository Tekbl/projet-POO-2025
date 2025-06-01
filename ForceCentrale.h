#pragma once
#include "ChampForces.h"
#include "VecteurV.h"
#include "constantes.h"
#include <vector>
#include <iostream>
#include "ObjetIntegrable.h"

class ForceCentrale: public ChampForces{
    protected:
    ForceCentrale(ObjetPhysique& obj): centre(obj){} 
    Vecteur quadratique_inverse(const ObjetPhysique& obj, double precis = 1e-10)const;
    ObjetPhysique& centre; //mis en protected pour que les classes dérivées puissent y accéder 
};

class ChampNewtonien: public ForceCentrale{
    public:
    ChampNewtonien(ObjetPhysique& obj): ForceCentrale(obj){}
    virtual Vecteur force(const ObjetPhysique& obj, double t) const override{
        return quadratique_inverse(obj)*((-G)*obj.get_masse()*centre.get_masse()); //selon la loi de Newton, F = -G * m1 * m2 / r^2 * r_unitaire
    }
    virtual void whoami(std::ostream& out) const override{
        out << "Champ Newtonien";
    }
    virtual void affiche(std::ostream& out) const override{
        whoami(out);
    }
};