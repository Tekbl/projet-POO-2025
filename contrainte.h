#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "affichage.h"
class ObjetPhysique;

class Contrainte : public Printable{
    public:
        //décalaration des méthodes virtuelles pures pour la classe Contrainte
        virtual Vecteur applique_force(const ObjetPhysique& obj, Vecteur force, double temps) = 0;
        virtual Vecteur position(const ObjetPhysique& obj) = 0;
        virtual Vecteur vitesse(const ObjetPhysique& obj) = 0;
        //rappel des méthodes virtuelles pures de Printable
        virtual void affiche(std::ostream& out)const override = 0;
        virtual void whoami(std::ostream& out)const = 0;

};  

class Libre:public Contrainte{
    virtual Vecteur applique_force(const ObjetPhysique& obj, Vecteur force, double t) override;
    virtual Vecteur position(const ObjetPhysique& obj) override;
    virtual Vecteur vitesse(const ObjetPhysique& obj) override;
    virtual void whoami(std::ostream& out)const override{out << "contrainte libre" ;};
    virtual void affiche(std::ostream& out)const override{whoami(out);}//blank for now since we have no use for it
};