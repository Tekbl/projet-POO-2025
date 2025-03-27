#include <vector>
#include "VecteurV.h"

class ObjetMobile{
    public:
        ObjetMobile(Vecteur E, Vecteur E_pr);
        void evolution(double t);
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
        ObjetPhysique(Vecteur E, Vecteur E_pr, unsigned int dim);
        Vecteur force(double t) const;
        Vecteur position() const;
        Vecteur vitesse() const;
    private:
        unsigned int dim_evo;
};