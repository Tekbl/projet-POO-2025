#include <iostream>
#include <vector>
#include <cmath>
#include "constantes.h"
#include "PointMateriel.h"
#include "ObjetIntegrable.h"
#include "Champforces.h"
#include "VecteurV.h"
using namespace std;


class GravitationConstante : public ChampForces {

    public :
        GravitationConstante():gravitation(g) {}; //constructeur par defaut qui utilise g
       
        virtual Vecteur force(const ObjetPhysique& p, double t) const override{
            return gravitation.mult(p.get_masse());} //F=m*a avec a=champ de grav et m = p.masse et on utilise la méthode mult définie dans la classe vecteur pour les multiplier
            virtual void whoami(ostream& out)const override{out << "gravitation constante";}

    private :
        Vecteur gravitation;
};
