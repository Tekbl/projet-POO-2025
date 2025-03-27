#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h" //a changer/update plus tard



class integrateur{
    public :
        virtual void evolue(objet_integrable obj, double t, double dt)=0;
    
};

class integrateurEulerCromer : public integrateur{
    public :
        virtual void evolue(objet_integrable obj, double t, double dt) override
            
    private :

};

virtual void integrateurEulerCromer::evolue(objet_integrable obj, double t, double dt) override{

}

class RungeKutta4: public integrateur{}; 






