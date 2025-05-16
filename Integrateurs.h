#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
#include "affichage.h"

class integrateur:public Printable{
    public :
        virtual void evolue(ObjetMobile *obj, double t, double dt)=0;
        virtual void affiche(std::ostream& out) const override;
        
    
};


class integrateurEulerCromer : public integrateur{
    public :
        virtual void evolue(ObjetMobile *obj, double t, double dt) override;
        virtual void whoami(std::ostream& out)const override;
};


class Newmark: public integrateur{
    public :
        virtual void evolue(ObjetMobile *obj, double t, double dt) override;
        virtual void whoami(std::ostream& out)const override;

}; 


class RungeKutta4: public integrateur{
    public :
        virtual void evolue(ObjetMobile *obj, double t, double dt) override;
        virtual void whoami(std::ostream& out)const override;

}; 

