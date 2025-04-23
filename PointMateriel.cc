#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
#include "ObjetIntegrable.h"     



class PointMateriel:public ObjetPhysique{

    public: 
        double get_pos(int i) const {return vecteur_position.get_coord(i);};
        double get_vit(int i) const {return vecteur_vitesse.get_coord(i);};
        void set_pos(std::vector<double> a);
        void set_vit(std::vector<double> a);
        Vecteur evolution(double t) const;
        //Vecteur ChampForces = g; //instruction de la W4, à changer dans le futur 
        friend std::ostream& operator<<(std::ostream& sortie, const PointMateriel& p);
        Vecteur position();
        Vecteur vitesse();

        void ecrit_sur(std::ostream& sortie)const {}
        void affiche(){}
        void affiche(double t){}

        //constructeur ?
        //destructeur ?

    private:    
        Vecteur vecteur_position; //3D pour l'instant (vecteur etat dans l'exercice P5)
        Vecteur vecteur_vitesse; //3D et dérivée du vecteur position (vecteur dérivé du vecteur etat dans l'exercice P5)
       

};

Vecteur PointMateriel::position(){return vecteur_position;}
Vecteur PointMateriel::vitesse(){return vecteur_vitesse;}


/*
===============================A_CHANGER==================================
Vecteur PointMateriel::evolution(double t) const{
    return ChampForces.mult(get_masse()) ;} //représente l'accéleration 
*/

void PointMateriel::set_pos(std::vector<double> a){
    for (size_t i = 0; i< a.size(); i++){
        vecteur_position.set_coord(i,a[i]);
    } 
}; 

void PointMateriel::set_vit(std::vector<double> a){
    for (int i(0); i< a.size() ; i++){
        vecteur_vitesse.set_coord(i,a[i]);
    } 
};//comme cela, get_pos/vit fonctionnent pour des vecteurs de n'importe quelle dimension

void PointMateriel::affiche(){
    ecrit_sur(std::cout);
}


void PointMateriel::affiche(double t){
    affiche();
    //cout << ChampForces << endl;

}

void PointMateriel::ecrit_sur(std::ostream& out) const{
    out << "champ de force :" << "\n" << vecteur_position << " #position" << "\n" << vecteur_vitesse << " #vitesse" << std::endl;
}

std::ostream& operator<<(std::ostream& sortie, const PointMateriel& p){
    p.ecrit_sur(sortie);
    return sortie;
}



