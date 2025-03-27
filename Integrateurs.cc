#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"



class integrateur{
    public :
        virtual void evolue(ObjetMobile *obj, double t, double dt)=0;
    
};

class integrateurEulerCromer : public integrateur{
    public :
        virtual void evolue(ObjetMobile *obj, double t, double dt) override;
            
};
//comment on fait la diff entre premier ordre et deuxième ordre ??
//nom des méthodes a changer
//pointeurs et ou références à implémenter 

void integrateurEulerCromer::evolue(ObjetMobile *obj, double t, double dt) override {
    obj->set_E_pr(obj->get_E_pr() + obj->evolution(t)*dt); //évolue E_pr
    obj->set_E(obj->get_E() + obj->get_E_pr()*dt ); //évolue E
}

class Newmark: public integrateur{}; 


class RungeKutta4: public integrateur{}; 






