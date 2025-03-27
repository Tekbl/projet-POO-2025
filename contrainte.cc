#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
using namespace std;


class Contrainte{
    public:
        virtual Vecteur applique_force(const ObjetPhysique& obj, Vecteur force, double temps) = 0;
        virtual Vecteur position(const ObjetPhysique& obj) = 0;
        virtual Vecteur vitesse(const ObjetPhysique& obj) = 0;
};

class Libre:public Contrainte{
    Vecteur applique_force(const ObjetPhysique& obj, Vecteur force, double temps) override;
};

Vecteur Libre::applique_force(const ObjetPhysique& obj, Vecteur force, double temps){
    
}