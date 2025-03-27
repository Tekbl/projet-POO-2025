#include <vector>
#include "VecteurV.h"

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
        ObjetPhysique(Vecteur E, Vecteur E_pr, unsigned int dim):ObjetMobile(E,E_pr),dim_evo(dim){};
        Vecteur force(double t) const;
        Vecteur position() const;
        Vecteur vitesse() const;
    private:
        unsigned int dim_evo;
        double masse;
};