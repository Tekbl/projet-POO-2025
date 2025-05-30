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


Vecteur PointMateriel::evolution(double t){
    //on initialise un vecteur de dim 1 à valeur 0 qui sera modifié par les calculs de force, sa dimension augmentera en fonction des champs de force appliqués
    Vecteur force_(1);
    for(auto chp : champ){
        force_ += force(chp,t) ;
    } 
    Vecteur contraint(1);
    for(auto c : contr){
        contraint += c->applique_force(*this, force_, t);
    }
    return contraint;
}

void PointMateriel::affiche(std::ostream& out) const{
    out << "masse : " << this->get_masse() <<" Kg"<< std::endl;
    out << "position : " << position(contr[0]) ;
    out << "vitesse : " << vitesse(contr[0]);
}

PointMateriel::PointMateriel(Vecteur E, Vecteur E_pr, double masse, double charge ,unsigned int dim, const std::vector<ChampForces*>& c,
    const std::vector<Contrainte*>& ctr):ObjetPhysique(E,E_pr,masse, charge,dim){

        /* A remettre si on veut initialiser une gravitation constante et aucune contrainte par défaut
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

PointMateriel_angulaire::PointMateriel_angulaire(Vecteur E, Vecteur E_pr, double masse, double charge ,unsigned int dim, const std::vector<ChampForces*>& c,
    const std::vector<Contrainte*>& ctr):PointMateriel(E,E_pr,masse,charge,dim,c,ctr){
        for(int i = 0; i < E.get_dimension(); i++){
            E.set_coord(i, angle_max(E.get_coord(i)));
        }
    }


Vecteur PointMateriel_angulaire::evolution(double t){
    Vecteur contrainte = PointMateriel::evolution(t);
    for(int i = 0; i < contrainte.get_dimension(); i++){
        contrainte.set_coord(i, angle_max(contrainte.get_coord(i)));
    }
    return contrainte;
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
