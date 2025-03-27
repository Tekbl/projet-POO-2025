#include <vector>
#include "VecteurV.h"

using namespace std;

class ObjetMobile{
    public:
        ObjetMobile(Vecteur E, Vecteur E_pr):E_(E),E_pr_(E_pr){};
        virtual void evolution(double t) = 0;
    protected:
        Vecteur E_;
        Vecteur E_pr_;

};



class ObjetPhysique:public ObjetMobile{
    public: 
        ObjetPhysique(Vecteur E, Vecteur E_pr, unsigned int dim):ObjetMobile(E,E_pr),dim_evo(dim){};
        Vecteur force(double t) const;
        Vecteur position() const;
        Vecteur vitesse() const;
    private:
        unsigned int dim_evo;
};