#include <vector>
#include <cmath>7
#include "ObjetIntegrable.h"
#include "VecteurV.h"
#include "constantes.h"
#include "contrainte.h"
#include "Champforces.h"
#include "affichage.h"

using namespace std;

/*
class ObjetMobile: public Printable{
    public:
        ObjetMobile(Vecteur E, Vecteur E_pr):E_(E),E_pr_(E_pr){};
        virtual Vecteur evolution(double t) = 0;
        Vecteur get_E() const;
        Vecteur get_E_pr() const;
        void set_E(Vecteur nE);
        void set_E_pr(Vecteur nE_pr);
    protected:
        Vecteur E_;
        Vecteur E_pr_;

};
*/

ObjetMobile:: ObjetMobile(Vecteur E, Vecteur E_pr):E_(E),E_pr_(E_pr){};

Vecteur ObjetMobile::get_E() const{
    return E_;
}
Vecteur ObjetMobile::get_E_pr() const{
    return E_pr_;
}

void ObjetMobile::set_E(Vecteur nE){
    E_ = nE;
}

void ObjetMobile::set_E_pr(Vecteur nE_pr){
    E_pr_ = nE_pr;
}


/*
class ObjetPhysique:public ObjetMobile{
    public: 
        ObjetPhysique(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, double masse = 0, unsigned int dim = 3)
            :ObjetMobile(E,E_pr),masse_(abs(masse)),dim_evo(dim){};
        Vecteur force(ChampForces *c, double t) const;
        Vecteur position(Contrainte *c) const;
        Vecteur vitesse(Contrainte *c) const;
        double get_masse() const;
        virtual void affiche(ostream& out) const override;

        vector<Contrainte*> get_contr(){return contr;}
        vector<ChampForces*> get_champ(){return champ;}

        void add_contr(Contrainte* c){contr.push_back(c);}
        void add_champ(ChampForces* c){champ.push_back(c);}
        
    protected: 
        vector<Contrainte*> contr;
        vector<ChampForces*> champ;
    private:
        unsigned int dim_evo;
        double masse_;
        //possibilité de rajouter setter et getter pour dim et masse si besoin
};
*/

ObjetPhysique::ObjetPhysique(Vecteur E, Vecteur E_pr, double masse, unsigned int dim)
    : ObjetMobile(E, E_pr), masse_(std::abs(masse)), dim_evo(dim) {}

double ObjetPhysique::get_masse() const{
    return masse_;
}


Vecteur ObjetPhysique::position(Contrainte *c) const{
    return c->position(*this);
}

Vecteur ObjetPhysique::vitesse(Contrainte *c) const{
    return c->vitesse(*this);
}

Vecteur ObjetPhysique::force(ChampForces *c ,double t) const{
    return c->force(*this,t);
}


vector<Contrainte*> ObjetPhysique::get_contr(){return contr;}
vector<ChampForces*> ObjetPhysique::get_champ(){return champ;}
void ObjetPhysique::add_contr(Contrainte* c){contr.push_back(c);}
void ObjetPhysique::add_champ(ChampForces* c){champ.push_back(c);}

void ObjetPhysique::affiche(ostream& out) const{
    out << "Objet physique de masse " << masse_ << ", de degré de liberté " << dim_evo << endl;
    out << "Position : " << E_ << endl;
    out << "Vitesse : " << E_pr_ << endl;
}
