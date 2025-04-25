#include <vector>
#include <iostream>
#include "VecteurV.h"
#include "ChampForces.h"
#include "ForceCentrale.h"
#include "systeme.h"
#include "PointMateriel.h"

int main(){
    PointMateriel pomme({0,0,0},{0,0,0},0.1);
    PointMateriel terre({0,0,6371.01e3},{0,0,0},5.972e24);
    ChampNewtonien champ(terre);
    Systeme sys({std::make_unique<PointMateriel>(pomme), std::make_unique<PointMateriel>(terre)});
}