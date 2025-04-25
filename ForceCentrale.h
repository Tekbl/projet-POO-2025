#include "ChampForces.h"
#include "VecteurV.h"
#include "constantes.h"
#include <vector>
#include <iostream>

class ForceCentrale: public ChampForces{
    protected:
        Vecteur quadratique_inverse(const ObjetPhysique& obj, double precis = 1e-10)const;
        ObjetPhysique& centre;
};

class ChampNewtonien: public ForceCentrale{
    public:
    virtual Vecteur force(const ObjetPhysique& obj, double t) const override;
};