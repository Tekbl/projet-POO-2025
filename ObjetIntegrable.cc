#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
#include "contrainte.h"
#include "Champforces.h"

using namespace std;

class ObjetMobile{
    public:
        ObjetMobile(Vecteur E, Vecteur E_pr):E_(E),E_pr_(E_pr){};
        virtual Vecteur evolution(double t) = 0;
        Vecteur get_E() const;
        Vecteur get_E_pr() const;
        void set_E(Vecteur nE);
        void set_E_pr(Vecteur nE_pr);
    protected:
        Vecteur E_;
        Vecteur E_pr_;

};

Vecteur ObjetMobile::get_E() const{
    return E_;
}
Vecteur ObjetMobile::get_E_pr() const{
    return E_pr_;
}

void ObjetMobile::set_E(Vecteur nE){
    E_ = nE;
}

void ObjetMobile::set_E_pr(Vecteur nE_pr){
    E_pr_ = nE_pr;
}



class ObjetPhysique:public ObjetMobile{
    public: 
        ObjetPhysique(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, unsigned int dim = 3, double masse = 0)
            :ObjetMobile(E,E_pr),dim_evo(dim),masse_(abs(masse)){};
        Vecteur force(ChampForces *c, double t) const;
        Vecteur position(Contrainte *c) const;
        Vecteur vitesse(Contrainte *c) const;
        double get_masse() const;
    protected: 
        unsigned int dim_evo;
        double masse_;
        //possibilité de rajouter setter et getter pour dim et masse si besoin
};

double ObjetPhysique::get_masse() const{
    return masse_;
}


Vecteur ObjetPhysique::position(Contrainte *c) const{
    return c->position(*this);
}

Vecteur ObjetPhysique::vitesse(Contrainte *c) const{
    return c->vitesse(*this);
}

Vecteur ObjetPhysique::force(ChampForces *c ,double t) const{
    return c->force(*this,t);
}
