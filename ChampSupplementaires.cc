#include "VecteurV.h"
#include "ChampForces.h"
#include "ObjetIntegrable.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"
#include "SupportADessin.h"
#include "ForceCentrale.h"
#include <iostream>
#include "ChampSupplementaires.h"

Vecteur ChampCompose::force(const ObjetPhysique& obj, double t)const{ 
    Vecteur somme_des_forces(0,0,0);
    for(auto field : champs){
        somme_des_forces += obj.force(field,t); //méthode force des champs composés = somme des force des champs qui compose le champcompose
    }
    return somme_des_forces;
}

    
void ChampCompose::affiche(std::ostream& sortie)const{
    for(auto field : champs){ 
        field->affiche(sortie);
    }
}


Vecteur ChampFrottements::force(const ObjetPhysique& obj, double t)const{
    Vecteur v = obj.get_E_pr();
    Vecteur Ff = v*(-coeff_frottement);     //F=-coeff_frottement*vitesse
    //std::cout<<"Ff: "<< Ff << std::endl;
    return Ff;
}

void ChampFrottements::affiche(std::ostream& sortie)const{
    sortie << "Coeff frottement : " << coeff_frottement;
}

Vecteur ChampElectroMagnetique::force(const ObjetPhysique& obj, double t)const{
    double q = obj.get_charge();
    Vecteur v = obj.get_E_pr();
    Vecteur V_cross_B = v.prod_vect(champMag);
    Vecteur F_tot =  champElec*q + V_cross_B*q; //F=q*E + q*(V x B) 
    //std::cout<<"F_electromag: "<< F_tot << std::endl;
    return F_tot;
}

void ChampElectroMagnetique::affiche(std::ostream& sortie)const{
    sortie << "Champ Electrique : " << champElec;
    sortie << "Champ Magnetique : " << champMag; 
}