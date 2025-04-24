#include "Systeme.h"
#include "VecteurV.h"
#include "PointMateriel.h"
#include "constantes.h"
#include "contrainte.h"
#include <vector>
#include <iostream>

class ForceCentrale: public ChampForces{
    protected:
        Vecteur quadratique_inverse(const ObjetPhysique& obj, double precis = 1e-10)const{
            Vecteur r = obj.get_E() - centre.get_E();
            double norme = r.norme();
            if (norme < precis) return Vecteur(0,0,0);
            return r * (1/ (norme * norme));
        }
        ObjetPhysique& centre;
};

class ChampNewtonien: public ForceCentrale{
    public:
    virtual Vecteur force(const ObjetPhysique& obj, double t) const override{
        return quadratique_inverse(obj)*((-G)*obj.get_masse()*centre.get_masse());
    }
};

int main(){
    PointMateriel pomme({0,0,10},{0,0,0},0.1, 3, vector<ChampForces*>& c {},vector<Contrainte*>& ctr {});
    PointMateriel terre();
}