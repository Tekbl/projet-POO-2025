#include <iostream>
#include <vector>
#include <cmath>
#include "constantes.h"
#include "PointMateriel.h"
#include "Champforces.h"
#include "VecteurV.h"
using namespace std;


class GravitationConstante : ChampForces {

    public :
        GravitationConstante():gravitation(g) {}; //constructeur par defaut qui utilise g
       
        Vecteur force(PointMateriel p, double t) const{
            return gravitation.mult(p.masse);} //F=m*a avec a=champ de grav et m = p.masse et on utilise la méthode mult définie dans la classe vecteur pour les multiplier
    private :
        Vecteur gravitation;
};


