#include "VecteurV.h"
#include "Champforces.h"
#include "ObjetIntegrable.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"
#include "SupportADessin.h"
#include "ForceCentrale.h"
#include <iostream>
#include "ChampSupplementaires.h"

Vecteur ChampCompose::force(const ObjetPhysique& obj, double t)const{
    Vecteur somme_des_forces(0,0,0);
    for(auto field : champs){
        somme_des_forces += obj.force(field,t);
    }
    return somme_des_forces;
}

    
void ChampCompose::affiche(std::ostream& sortie)const{
    for(auto field : champs){
        field->affiche(sortie);
    }
}


Vecteur ChampFrottements::force(const ObjetPhysique& obj, double t)const{
    Vecteur v = obj.get_E_pr();
    Vecteur Ff = v*(-coeff_frottement);
    return Ff;
}

void ChampFrottements::affiche(std::ostream& sortie)const{
    sortie << "Coeff frottement : " << coeff_frottement;
}

Vecteur ChampElectroMagnetique::force(const ObjetPhysique& obj, double t)const{
    double q = obj.get_charge();
    Vecteur V_cross_B = obj.get_E_pr().prod_vect(champMag);
    return champElec*q + V_cross_B*q; //F=q*E + q*(V x B)
}

void ChampElectroMagnetique::affiche(std::ostream& sortie)const{
    sortie << "Champ Electrique : " << champElec;
    sortie << "Champ Magnetique : " << champMag; 
}



/*


class ForceCentrale: public ChampForces{
    protected:
        ForceCentrale(ObjetPhysique& obj): centre(obj){} 
        Vecteur quadratique_inverse(const ObjetPhysique& obj, double precis = 1e-10)const{
            Vecteur r = obj.get_E() - centre.get_E();
            double norme = r.norme();
            if (norme < precis){
                 return Vecteur(0,0,0);
            }
            return (~r) * (1/ (norme * norme));
        }
        ObjetPhysique& centre;
};

Vecteur ForceCentrale::quadratique_inverse(const ObjetPhysique& obj, double precis) const{
    Vecteur r = obj.get_E() - centre.get_E();
    double norme = r.norme();
    if (norme < precis){
         return Vecteur(0,0,0);
    }
    return (~r) * (1/ (norme * norme));
}

class ChampNewtonien: public ForceCentrale{
    public:
    ChampNewtonien(ObjetPhysique& obj): ForceCentrale(obj){}
    virtual Vecteur force(const ObjetPhysique& obj, double t) const override{
        return quadratique_inverse(obj)*((-G)*obj.get_masse()*centre.get_masse());
    }
    virtual void whoami(std::ostream& out) const override{
        out << "Champ Newtonien : " ;
    }
    virtual void affiche(std::ostream& out) const override{
        whoami(out);
    }
};


*/