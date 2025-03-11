#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



class PointMateriel{

    public: 
        double masse;
        Vecteur get_pos() const {return vecteur_position.vecteur;};
        Vecteur get_vit() const {return vecteur_vitesse.vecteur;};

        void set_pos(vector<double> a){
            for (int i(0); i<unsigned int(a.size());i++){
                vecteur_position.vecteur[i]=a[i];
            } 
        }; 
        void set_vit(vector<double> a){
            for (int i(0); i<unsigned int(a.size());i++){
                vecteur_vitesse.vecteur[i]=a[i];
            } 
        };//comme cela, get_pos/vit fonctionnent pour des vecteurs de n'importe quelle dimension
        
        

    
    private:
        Vecteur vecteur_position; //3D pour l'instant 
        Vecteur vecteur_vitesse; //3D et dérivée du vecteur position
        Vecteur position(){} // pas capté la diff avec set/get_pos/vit
        Vecteur vitesse(){} // pas capté la diff avec set/get_pos/vit
        double ChampForces;
        double evolution(double t){return ChampForces/masse;} //représente l'accéleration (pour l'instant on utilise une version simplifiée)


};


