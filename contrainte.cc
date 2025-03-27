#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
using namespace std;


class Contrainte{
    public:
        Vecteur applique_force(const ObjetPhysique& obj, Vecteur force, double temps);//pas sûr pour temps
        Vecteur position(const ObjetPhysique&);
    private:
};



Vecteur Contrainte::applique_force(const ObjetPhysique& obj, Vecteur force, double temps){

}

Vecteur Contrainte::position(const ObjetPhysique&){

}