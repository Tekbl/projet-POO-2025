#include "ChampForces.h"
#include "VecteurV.h"
#include "constantes.h"
#include <vector>
#include <iostream>
#include "ObjetIntegrable.h"
#include "ForceCentrale.h"

Vecteur ForceCentrale::quadratique_inverse(const ObjetPhysique& obj, double precis) const{
    Vecteur r = obj.get_E() - centre.get_E(); //distance entre l'objet et le centre de la force centrale
    double norme = r.norme();
    if (norme < precis){
         return Vecteur(0,0,0);
    }
    return (~r) * (1/ (norme * norme)); //    =  1/(r^2) * le vecteur unitaire de r pour avoir la direction de la force
}

