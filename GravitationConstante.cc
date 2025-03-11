#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class GravitationConstante{

    public :

    private :
        Vecteur gravitation;
        gravitation.vecteur.setcoord(0,0);
        gravitation.vecteur.setcoord(1,9.81); //je suis pas sur si c'est la meilleure façon d'initialiser le champ de gravite terrestre
        Vecteur force(PointMateriel p, double t){return gravitation.vecteur.mult(p.masse);} // F=m*a avec a=champ de grav et m = p.masse et on utilise la méthode mult définie dans la classe vecteur pour les multiplier


};