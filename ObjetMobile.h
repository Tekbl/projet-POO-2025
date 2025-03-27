#include <vector>
#include "VecteurV.h"

class ObjetMobile{
    public:
        ObjetMobile(Vecteur E, Vecteur E_pr);
        void evolution(double t);
    private:
        Vecteur E_;
        Vecteur E_pr_;

};