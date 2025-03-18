#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
using namespace std;



class PointMateriel{

    public: 
        double masse;
        Vecteur get_pos() const {return vecteur_position.vecteur;};
        Vecteur get_vit() const {return vecteur_vitesse.vecteur;};
        void set_pos(vector<double> a);
        void set_vit(vector<double> a);
        ostream& operator<<(ostream& sortie, vec){}
        Vecteur ChampForces(g);

    
    private:
        Vecteur vecteur_position; //3D pour l'instant (vecteur etat dans l'exercice P5)
        Vecteur vecteur_vitesse; //3D et dérivée du vecteur position (vecteur dérivé du vecteur etat dans l'exercice P5)
        Vecteur position(){} // pas capté la diff avec set/get_pos/vit
        Vecteur vitesse(){} // pas capté la diff avec set/get_pos/vit
        double evolution(double t) const{return ChampForces/masse;} //représente l'accéleration (pour l'instant on utilise une version simplifiée)


};


void PointMateriel::set_pos(vector<double> a){
    for (int i(0); i<unsigned int(a.size());i++){
        vecteur_position.vecteur[i]=a[i];
    } 
}; 

void PointMateriel::set_vit(vector<double> a){
    for (int i(0); i<unsigned int(a.size());i++){
        vecteur_vitesse.vecteur[i]=a[i];
    } 
};//comme cela, get_pos/vit fonctionnent pour des vecteurs de n'importe quelle dimension
