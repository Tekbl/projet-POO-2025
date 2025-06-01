#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include "VecteurV.h"
#include "affichage.h"
#include "constantes.h"
#include "contrainte.h"
class Contrainte;
class ChampForces;

class ObjetMobile: public Printable{
    public:
        ObjetMobile(Vecteur E, Vecteur E_pr);
        virtual Vecteur evolution(double t) = 0;
        Vecteur get_E() const;
        Vecteur get_E_pr() const;
        void set_E(Vecteur nE);
        void set_E_pr(Vecteur nE_pr);

        virtual ~ObjetMobile() = default; //destructeur virtuel par défaut pour éviter les fuites de mémoire
    protected:
        Vecteur E_;
        Vecteur E_pr_;

};

class ObjetPhysique:public ObjetMobile{
    public: 
        ObjetPhysique(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, double masse = 0,double charge=0, unsigned int dim = 3);
        Vecteur force(ChampForces *c ,double t) const;
        Vecteur position(Contrainte *c) const;
        Vecteur vitesse(Contrainte *c) const;
        double get_masse() const;
        double get_charge() const;
        virtual void affiche(std::ostream& out) const override;

        std::vector<Contrainte*> get_contr();
        std::vector<ChampForces*> get_champ();

        void add_contr(Contrainte* c);
        void add_champ(ChampForces* c);

        virtual ~ObjetPhysique(){
            for(auto& c : contr) {
                delete c; // Suppression des contraintes
            }
            for(auto& f : champ) {
                delete f; // Suppression des champs de force
            }
        }
        
    protected: 
        std::vector<Contrainte*> contr;
        std::vector<ChampForces*> champ;
    private:
        unsigned int dim_evo;
        double masse_;
        double charge_;
};