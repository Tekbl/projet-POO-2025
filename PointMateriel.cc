#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
using namespace std;



class PointMateriel{

    public: 
        double masse;
        Vecteur get_pos(int i) const {return vecteur_position.get_coord(i);};
        Vecteur get_vit(int i) const {return vecteur_vitesse.get_coord(i);};
        void set_pos(vector<double> a);
        void set_vit(vector<double> a);
        Vecteur evolution(double t) const{};
        Vecteur ChampForces = g; // emploie le constructeur de la classe Vecteur
        Vecteur position(){} // pas capté la diff avec set/get_pos/vit
        Vecteur vitesse(){} // pas capté la diff avec set/get_pos/vit
        friend ostream& operator<<(ostream& sortie, const PointMateriel& p){};
        

    private:
        Vecteur vecteur_position; //3D pour l'instant (vecteur etat dans l'exercice P5)
        Vecteur vecteur_vitesse; //3D et dérivée du vecteur position (vecteur dérivé du vecteur etat dans l'exercice P5)
       

};

Vecteur Vecteur::position(){return;}

Vecteur Vecteur::vitesse(){return ;}

Vecteur PointMateriel::evolution(double t) const{
    Vecteur A=ChampForces;
    A = A.mult(masse);
    return A;} //représente l'accéleration (pour l'instant on utilise une version simplifiée)


void PointMateriel::set_pos(vector<double> a){
    for (int i(0); i<unsigned int(a.size());i++){
        vecteur_position.set_coord(i,a[i]);
    } 
}; 

void PointMateriel::set_vit(vector<double> a){
    for (int i(0); i<unsigned int(a.size());i++){
        vecteur_vitesse.set_coord(i,a[i]);
    } 
};//comme cela, get_pos/vit fonctionnent pour des vecteurs de n'importe quelle dimension

ostream& operator<<(ostream& sortie, const PointMateriel& p){
    sortie << p.ChampForces << " ";
    return sortie;
}