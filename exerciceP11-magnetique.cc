#include <vector>
#include <iostream>
#include "VecteurV.h"
#include "ChampForces.h"
#include "ForceCentrale.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"
#include "ChampSupplementaires.h"
#include "contrainte.h"



int main(){
Vecteur Mag(0,0,0.5);
Vecteur Electro(0,0,0);
double lambda(1.33e-5);
Libre libre; 
double m = 1.5e-4;
double q = 2e-6;
Vecteur pos(0,0,0);
Vecteur vit(0.3,0,0);

double t_simu = 2.0;
double dt = 0.001;
integrateurEulerCromer euler;



ChampElectroMagnetique ElectroMag(Electro,Mag);
ChampFrottements frottements(lambda);
std::vector<ChampForces*> champs_;
champs_.push_back(&ElectroMag);
champs_.push_back(&frottements);

ChampCompose un_champ_de_ble(champs_);
std::vector<ChampForces*> champs;

champs.push_back(&un_champ_de_ble);

std::vector<Contrainte*> contraintes;
contraintes.push_back(&libre);

PointMateriel particule(pos,vit,q,m,3,champs,contraintes);


for(double t(0.0);t<t_simu;t+=dt){
    std::cout << "temps : "<< t << std::endl;
    std::cout << particule << std::endl;
    euler.evolue(&particule,t,dt);
}

return 0;    
}
/*

un champ électromagnétique constant de champ électrique nul, de champ magnétique 0.5 T suivant l'axe vertical (c.-à-d. B=(0, 0, 0.5));
un champ de forces de frottement fluide d'intensité 1.33e-5 S.I.;
une contrainte libre;
une particule de masse 1.5e-4 kg, de charge 2e-6, en position (0, 0, 0), de vitesse initiale 0.3 m/s suivant l'axe des ordonnées (c.-à-d. v0=(0.3, 0, 0)).
Avec un intégrateur d'Euler-Cromer et un pas de temps de 0.001 s, vous devriez obtenir les résultats ci-dessous.

Notes :

l'intégrateur d'Euler-Cromer n'est pas assez précis (ordre 1, c.-à-d. erreur croissant linéairement avec le temps); il est donc normal, si vous comparez avec la courbe théorique (que vous avez si vous avez fait l'exercice de Physique ;-)), que vous constatiez un écart croissant; l'amélioration de la précision de l'intégrateur est justement le but du sujet de la semaine prochaine;

la troisième coordonnée (z) est toujours nulle;
il pourrait aussi être intéressant de dessiner la trajectoire (p.ex. avec gnuplot ou autre) sur des temps plus longs;
sur des temps plus longs, il n'est aussi pas forcément nécessaire d'afficher les valeurs à chaque pas d'intégration; vous pourriez choisir aussi un « pas de temps d'affichage » (multiple du pas d'intégration); p.ex. avoir un pas d'intégration de 0.001 s, mais un affichage que toutes les 0.05 s (tous les 50 pas d'intégration).
t     x           y


*/


