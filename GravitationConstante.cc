#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class GravitationConstante{

    public :
        GravitationConstante(double x=0, double y=0, double z=-9.81):{
            gravitation.vecteur.setcoord(0,x);
            gravitation.vecteur.setcoord(1,y);
            gravitation.vecteur.setcoord(2,z);} 

        Vecteur force(PointMateriel p, double t);

    private :
        Vecteur gravitation;
};


Vecteur GravitationConstante::force(PointMateriel p, double t){return gravitation.vecteur.mult(p.masse);} // F=m*a avec a=champ de grav et m = p.masse et on utilise la méthode mult définie dans la classe vecteur pour les multiplier