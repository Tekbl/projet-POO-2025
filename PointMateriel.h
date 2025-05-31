#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "constantes.h"
#include "ObjetIntegrable.h"
#include "affichage.h"
#include "ObjetDessinable.h"
#include "SupportADessin.h"

#define M_PI 3.14159265358979323846
 
class PointMateriel: public ObjetPhysique, public Dessinable{
    public: 
        PointMateriel(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, double masse = 0, double charge=0 ,unsigned int dim = 3, const std::vector<ChampForces*>& c = std::vector<ChampForces*>{},
            const std::vector<Contrainte*>& ctr = std::vector<Contrainte*>{});

        virtual Vecteur evolution(double t) override;

        virtual void affiche(std::ostream& sortie)const override;
        virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); } //a copier coller dans toutes les sous classes de dessinable
        
        virtual void whoami(std::ostream& out)const override{out << "point materiel" ;};

    
};


class PointMateriel_angulaire : public PointMateriel{
    public:
        PointMateriel_angulaire(Vecteur E = Vecteur(2), Vecteur E_pr = Vecteur(2), double masse = 0, double charge=0 ,unsigned int dim = 2, const std::vector<ChampForces*>& c = std::vector<ChampForces*>{},
            const std::vector<Contrainte*>& ctr = std::vector<Contrainte*>{});
        virtual Vecteur evolution(double t) override;
        using PointMateriel::affiche; //pour utiliser la méthode affiche de PointMateriel
        virtual void whoami(std::ostream& out)const override{out << "point materiel angulaire" ;};
    private:
        const double Lim = 2 * M_PI; //limite de l'angle, pour éviter les problèmes de dépassement de la valeur de l'angle

        double angle_max(double angle){
                while(angle > Lim){
                    angle -= Lim;
                } 
                while(angle < -Lim){
                    angle += Lim;
                }
                return angle;
        }
};

/*================ INUTILISE =======================

particule_chargee est inutilisee car vu qu'on utilise du polymorphisme dans un systeme de particule avec une liste de ObjetPhysique*,
on ne peut pas accèder à la charge d'une particule_chargee. On est donc contraint à la charge aux attributs d'un ObjetPhysique, 
ce qui rend la classe particule_chargee inutile. 

*/

/*class particule_chargee : public PointMateriel{
    public:
        particule_chargee(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, double masse = 0, double charge_ = 0,
            unsigned int dim = 3, const std::vector<ChampForces*>& c = std::vector<ChampForces*>{},
            const std::vector<Contrainte*>& ctr = std::vector<Contrainte*>{});
        virtual Vecteur evolution(double t) override;
        virtual void affiche(std::ostream& sortie)const override;
        virtual void whoami(std::ostream& out)const override{out << "particule chargee" ;};
    private:
        double charge;
};*/

