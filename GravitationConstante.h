#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "PointMateriel.h"
#include "constantes.h"


class GravitationConstante{

    public :
        GravitationConstante(); 
        Vecteur force(PointMateriel p, double t) const;
    

    private :
        Vecteur gravitation;
};

