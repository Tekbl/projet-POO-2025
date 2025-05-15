#pragma once
#include "VecteurV.h"
#include "Champforces.h"
#include "ObjetIntegrable.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"
#include "SupportADessin.h"
#include "ForceCentrale.h"


class ChampCompose : public ChampForces{
    public:
        ChampCompose(std::vector<ChampForces*> champs_):champs(champs_){};
        virtual Vecteur force(const ObjetPhysique& obj, double t) const override;
        virtual void affiche(std::ostream& sortie)const override;
        virtual void whoami(std::ostream& sortie)const override{sortie << "Champ Compose" ;};
    private:
        std::vector<ChampForces*> champs;
};



class ChampElectroMagnetique: public ChampForces{
    public:
        ChampElectroMagnetique(Vecteur elec = 0, Vecteur mag = 0):champElec(elec),champMag(mag){};
        virtual Vecteur force(const ObjetPhysique& obj, double t) const override;
        virtual void affiche(std::ostream& sortie)const override;
        virtual void whoami(std::ostream& sortie)const override{sortie << "Champ Electrique" ;};
    private:
        Vecteur champElec;
        Vecteur champMag;

};

class ChampFrottements: public ChampForces{
    public:
        ChampFrottements(double coeff_):coeff_frottement(coeff_){};
        virtual Vecteur force(const ObjetPhysique& obj, double t) const override;
        virtual void affiche(std::ostream& sortie)const override;
        virtual void whoami(std::ostream& sortie)const override{sortie << "Champ Frottements" ;};
    private:
        double coeff_frottement;

}; 



/*
=========REFERENCES========== 
class ChampForces : public Printable{
    public :
        
    virtual Vecteur force(const ObjetPhysique& obj, double t) const = 0;
    virtual void affiche(std::ostream& out)const override;//blank for now since we have no use for it

    private :
};

class ForceCentrale: public ChampForces{
    protected:
    ForceCentrale(ObjetPhysique& obj): centre(obj){} 
    Vecteur quadratique_inverse(const ObjetPhysique& obj, double precis = 1e-10)const;
    ObjetPhysique& centre;
};

class ChampNewtonien: public ForceCentrale{
    public:
    ChampNewtonien(ObjetPhysique& obj): ForceCentrale(obj){}
    virtual Vecteur force(const ObjetPhysique& obj, double t) const override{
        return quadratique_inverse(obj)*((-G)*obj.get_masse()*centre.get_masse());
    }
    virtual void whoami(std::ostream& out) const override{
        out << "Champ Newtonien";
    }
    virtual void affiche(std::ostream& out) const override{
        whoami(out);
    }
};

*/