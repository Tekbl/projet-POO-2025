#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "ObjetIntegrable.h"
#include "affichage.h"

class ChampForces : public Printable{
    
    public :
        
    virtual Vecteur force(const ObjetPhysique& obj, double t) const = 0;
    virtual void affiche(std::ostream& out)const override{out <<" ";}//blank for now since we have no use for it
    
    private :
    
};

