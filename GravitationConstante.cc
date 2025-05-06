#include <iostream>
#include <vector>
#include <cmath>
#include "GravitationConstante.h"
#include "constantes.h"
#include "ObjetIntegrable.h"
#include "Champforces.h"
#include "VecteurV.h"



Vecteur GravitationConstante::force(const ObjetPhysique& p, double t) const {return gravitation.mult(p.get_masse());} 
//F=m*a avec a=champ de grav et m = p.masse et on utilise la méthode mult définie dans la classe vecteur pour les multiplier


