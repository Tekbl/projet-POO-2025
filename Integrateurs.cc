#include <iostream>
#include <vector>
#include <cmath>
#include "Integrateurs.h"
#include "VecteurV.h"
#include "ObjetIntegrable.h"




void integrateurEulerCromer::evolue(ObjetMobile *obj, double t, double dt) {
    obj->set_E_pr(obj->get_E_pr() + obj->evolution((abs(t))*abs(dt))); //évolue E_pr
    obj->set_E(obj->get_E() + obj->get_E_pr()*abs(dt)); //évolue E
}







