#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "PointMateriel.h"
using namespace std;


class Contrainte{
    public:
        Vecteur applique_force(const PointMateriel& obj, Vecteur force, double temps);//à remplacer par un objet physique, pas sûr pour temps
        Vecteur position();
    private:
};



Vecteur Contrainte::applique_force(const PointMateriel& obj, Vecteur force, double temps){

}