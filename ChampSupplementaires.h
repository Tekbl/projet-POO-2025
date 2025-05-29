#pragma once
#include "VecteurV.h"
#include "Champforces.h"
#include "ObjetIntegrable.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"
#include "SupportADessin.h"
#include "ForceCentrale.h"

//ce sont tous des sous-classes de ChampForces

class ChampCompose : public ChampForces{
    public:
        ChampCompose(std::vector<ChampForces*> champs_):champs(champs_){};
        virtual Vecteur force(const ObjetPhysique& obj, double t) const override;
        virtual void affiche(std::ostream& sortie)const override;
        virtual void whoami(std::ostream& sortie)const override{sortie << "Champ Compose" ;};
    private:
        std::vector<ChampForces*> champs; //ChampCompose est une collection hétérogène de champforces
};



class ChampElectroMagnetique: public ChampForces{
    public:
        ChampElectroMagnetique(Vecteur elec = 0, Vecteur mag = 0):champElec(elec),champMag(mag){};
        virtual Vecteur force(const ObjetPhysique& obj, double t) const override;
        virtual void affiche(std::ostream& sortie)const override;
        virtual void whoami(std::ostream& sortie)const override{sortie << "Champ Electrique" ;};
    private: 
        Vecteur champElec; 
        Vecteur champMag; 

};

class ChampFrottements: public ChampForces{
    public:
        ChampFrottements(double coeff_):coeff_frottement(coeff_){};
        virtual Vecteur force(const ObjetPhysique& obj, double t) const override;
        virtual void affiche(std::ostream& sortie)const override;
        virtual void whoami(std::ostream& sortie)const override{sortie << "Champ Frottements" ;};
    private:
        double coeff_frottement;

}; 


/* 
⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⣷⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣰⣿⣿⣿⣿⡿⠿⠿⢿⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢰⣿⣿⣿⡿⠋⠀⠀⠀⠀⠉⠻⣿⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢸⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠘⢿⣿⡿⢃⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠘⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣴⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠙⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠟⠁⣴⠀⠀⢀⡎⠀⠀⢀⡾⠀
⠀⠀⠀⠈⠻⢿⣿⣿⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⢀⣾⠇⠀⢠⣾⠃⠀⢀⣾⠇⠀
⠀⠀⠀⠀⠀⠀⠉⠻⠿⢋⣴⣶⣤⠀⠀⠀⢀⣴⡿⠃⠀⣴⣿⠃⠀⢠⣾⡟⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠿⠟⠁⣀⣴⠿⠋⠀⣠⣾⠟⠁⠀⣴⣿⡿⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠋⠉⠀⢀⣠⣾⠟⠁⠀⣠⣾⣿⠟⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡶⠿⠋⠁⠀⣠⣾⣿⡿⠋⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⢀⣴⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⡾⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/