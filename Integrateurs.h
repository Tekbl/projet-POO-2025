#pragma once
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

class Newmark: public integrateur{}; 


class RungeKutta4: public integrateur{}; 

