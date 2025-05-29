#pragma once
#include <iostream>
#include "contrainte.h"
#include "VecteurV.h"
#include "affichage.h"
#include "ObjetIntegrable.h"

class ContrainteSpherique : public Contrainte{
    private:
        const double rayon;
    public:
        ContrainteSpherique(double r) : rayon(r) {}
        //override des méthodes de Contrainte
        virtual Vecteur applique_force(const ObjetPhysique& obj, Vecteur force, double t) override;
        virtual Vecteur position(const ObjetPhysique& obj) override;
        virtual Vecteur vitesse(const ObjetPhysique& obj) override;
        //override des méthodes de Printable
        virtual void whoami(std::ostream& out)const override{out << "contrainte sphérique" ;};
        virtual void affiche(std::ostream& out)const override{whoami(out);}
};