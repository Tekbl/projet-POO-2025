#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
#include "ObjetIntegrable.h"    
#include "affichage.h"
#include "Champforces.h"
#include "contrainte.h"
#include "GravitationConstante.h"
#include "ObjetDessinable.h"
#include "SupportADessin.h"
#include "PointMateriel.h"

/*class PointMateriel:public ObjetPhysique, public Dessinable{

    public: 
        PointMateriel(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, double masse = 0, unsigned int dim = 3, const std::vector<ChampForces*>& c = std::vector<ChampForces*>{},
            const std::vector<Contrainte*>& ctr = std::vector<Contrainte*>{}):
            ObjetPhysique(E,E_pr,masse,dim){
                if(c.empty()){
                    champ.push_back(new GravitationConstante());
                }else{ 
                    champ = c;
                }

                if(ctr.empty()){
                    contr.push_back(new Libre());
                }else{
                    contr = ctr;
                }
            };
        double get_pos(int i) const {return vecteur_position.get_coord(i);};
        double get_vit(int i) const {return vecteur_vitesse.get_coord(i);};
        void set_pos(std::vector<double> a);
        void set_vit(std::vector<double> a);
        virtual Vecteur evolution(double t) override;
        //Vecteur ChampForces = g; //instruction de la W4, à changer dans le futur 

        virtual void affiche(std::ostream& sortie)const override;
        virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); } //a copier coller dans toutes les sous classes de dessinable
        
        virtual void whoami(std::ostream& out)const override{out << "point materiel" ;};

        //constructeur ?
        //destructeur ?

    private:    
        //Vecteur vecteur_position; //3D pour l'instant (vecteur etat dans l'exercice P5)
        //Vecteur vecteur_vitesse; //3D et dérivée du vecteur position (vecteur dérivé du vecteur etat dans l'exercice P5)
       

};*/




//===============================A_CHANGER==================================
Vecteur PointMateriel::evolution(double t){
    //on initialise un vecteur de dim 3 à valeur 0 qui sera modifié par les calculs de force
    Vecteur x(3);
    for(auto chp : champ){
        x += force(chp,t) ;
    } 
    
    x=x*(1/this->get_masse());
    return x;
}

/*void PointMateriel::set_pos(std::vector<double> a){
    for (size_t i = 0; i< a.size(); i++){
        vecteur_position.set_coord(i,a[i]);
    } 
}; 

void PointMateriel::set_vit(std::vector<double> a){
    for (int i(0); i< a.size() ; i++){
        vecteur_vitesse.set_coord(i,a[i]);
    } 
};//comme cela, get_pos/vit fonctionnent pour des vecteurs de n'importe quelle dimension*/

void PointMateriel::affiche(std::ostream& out) const{
    //out << this->position(contr[0]) << " #position" << "\n" << this->vitesse(contr[0]) << " #vitesse" << std::endl;
    out << "masse : " << this->get_masse() <<" Kg" << std::endl;
    out << "position : " << this->get_E();
    out << "\nvitesse : " << this->get_E_pr() << std::endl;
}

PointMateriel::PointMateriel(Vecteur E, Vecteur E_pr, double masse, double charge ,unsigned int dim, const std::vector<ChampForces*>& c,
    const std::vector<Contrainte*>& ctr):ObjetPhysique(E,E_pr,masse, charge,dim){
        /*
        if(c.empty()){
            champ.push_back(new GravitationConstante());
        }else{ 
            champ = c;
        }

        if(ctr.empty()){
            contr.push_back(new Libre());
        }else{
            contr = ctr;
        }
        */
    }



/*=================== INUTILISE (VOIR .h) =================================0
particule_chargee::particule_chargee(Vecteur E, Vecteur E_pr, double masse, double charge_, unsigned int dim, const std::vector<ChampForces*>& c,
    const std::vector<Contrainte*>& ctr):PointMateriel(E,E_pr,masse,dim,c,ctr),charge(charge_){
       
       /*======== Mettre new Champmagnetique à la place de GravitationConstante une fois implementé 
        if(c.empty()){
            champ.push_back(new GravitationConstante());
        }else{ 
            champ = c;
        }
        

        if(ctr.empty()){
            contr.push_back(new Libre());
        }else{
            contr = ctr;
        }
    }

*/
