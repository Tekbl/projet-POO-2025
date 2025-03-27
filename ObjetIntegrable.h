#pragma once
#include <vector>
#include <cmath>
#include "VecteurV.h"

class ObjetMobile{
    public:
        ObjetMobile(Vecteur E, Vecteur E_pr);
        virtual Vecteur evolution(double t) = 0;
        Vecteur get_E() const;
        Vecteur get_E_pr() const;
        void set_E(Vecteur nE);
        void set_E_pr(Vecteur nE_pr);
    protected:
        Vecteur E_;
        Vecteur E_pr_;

};

class ObjetPhysique:public ObjetMobile{
    public: 
        ObjetPhysique(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, unsigned int dim = 3, double masse = 0);
        Vecteur force(double t) const;
        Vecteur position() const;
        Vecteur vitesse() const;
        double get_masse() const;
    private:
        unsigned int dim_evo;
        double masse_;
};