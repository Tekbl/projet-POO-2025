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
        /*double get_pos(int i) const {return vecteur_position.get_coord(i);};
        double get_vit(int i) const {return vecteur_vitesse.get_coord(i);};
        void set_pos(std::vector<double> a);
        void set_vit(std::vector<double> a);*/
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
       
};


/*===========   INUTILISE ========== 

particule_chargee est inutilisee parce que la méthode force() des ChampForces, prend un objetphysique en argument 
et donc pour calculer la force (F=q*E), je dois faire ObjetPhysique.charge*champElec, 
ce qui marche pas si charge est définie en dehors de ObjetPhysique :'(

*/

class particule_chargee : public PointMateriel{
    public:
        particule_chargee(Vecteur E = {0,0,0}, Vecteur E_pr = {0,0,0}, double masse = 0, double charge_ = 0,
            unsigned int dim = 3, const std::vector<ChampForces*>& c = std::vector<ChampForces*>{},
            const std::vector<Contrainte*>& ctr = std::vector<Contrainte*>{});
        virtual Vecteur evolution(double t) override;
        virtual void affiche(std::ostream& sortie)const override;
        virtual void whoami(std::ostream& out)const override{out << "particule chargee" ;};
    private:
        double charge;
};

class PointMateriel_angulaire : public PointMateriel{
    public:
        PointMateriel_angulaire(Vecteur E = Vecteur(2), Vecteur E_pr = Vecteur(2), double masse = 0, double charge=0 ,unsigned int dim = 2, const std::vector<ChampForces*>& c = std::vector<ChampForces*>{},
            const std::vector<Contrainte*>& ctr = std::vector<Contrainte*>{});
        virtual Vecteur evolution(double t) override;
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