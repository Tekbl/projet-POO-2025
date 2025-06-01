#include <vector>
#include <cmath>
#include "ObjetIntegrable.h"
#include "VecteurV.h"
#include "constantes.h"
#include "contrainte.h"
#include "ChampForces.h"
#include "affichage.h"

using namespace std;

ObjetMobile::ObjetMobile(Vecteur E, Vecteur E_pr):E_(E),E_pr_(E_pr){};

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


ObjetPhysique::ObjetPhysique(Vecteur E, Vecteur E_pr, double masse,double charge ,unsigned int dim)
    : ObjetMobile(E, E_pr), masse_(std::abs(masse)),charge_(charge) ,dim_evo(dim) {}

double ObjetPhysique::get_masse() const{
    return masse_;
}


Vecteur ObjetPhysique::position(Contrainte *c) const{
    return c->position(*this);//applique la méthode position de la contrainte c à l'objet physique
}

Vecteur ObjetPhysique::vitesse(Contrainte *c) const{
    return c->vitesse(*this);//applique la méthode vitesse de la contrainte c à l'objet physique
}

Vecteur ObjetPhysique::force(ChampForces *c ,double t) const{
    return c->force(*this,t);//applique la méthode force du champ de force c à l'objet physique
}

double ObjetPhysique::get_charge()const{return charge_;}

vector<Contrainte*> ObjetPhysique::get_contr(){return contr;}
vector<ChampForces*> ObjetPhysique::get_champ(){return champ;}
void ObjetPhysique::add_contr(Contrainte* c){contr.push_back(c);}
void ObjetPhysique::add_champ(ChampForces* c){champ.push_back(c);}

void ObjetPhysique::affiche(ostream& out) const{
    out << "Objet physique de masse " << masse_ << ", de degré de liberté " << dim_evo << endl;
    out << "Position : " << position(contr[0]) << endl;
    out << "Vitesse : " << vitesse(contr[0]) << endl;
}
