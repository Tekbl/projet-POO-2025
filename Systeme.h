#pragma once
#include <vector> 
#include <memory>
#include "ObjetIntegrable.h"
#include "contrainte.h"
#include "Integrateurs.h"
#include "affichage.h"
#include "ObjetDessinable.h"
#include "SupportADessin.h"
#include "Champforces.h"


class Systeme: public Printable, public Dessinable{
    
    private :

        //modif unique_ptr en ptr car ne fonctionne pas avec c++11
        std::vector<std::unique_ptr<ObjetPhysique>> sys_objects;
        // j'utilise des unique ptr pour simplifier l'utilisation
        // j'utilise des objets physiques car j'ai besoin d'objets qui ont des contraintes/champforces en attribut

        std::vector<std::unique_ptr<Contrainte>> sys_constraints;
        std::vector<std::unique_ptr<ChampForces>> sys_force_field;
        std::unique_ptr<integrateur> integrator;


        double time; // peut être utiliser un SHARED_PTR pour le temps, ce serait bien
        // Si pas de shared_ptr, faut que tout les bidules qui utilisent time passent par REFERENCE

        
    public :

    Systeme(std::vector<std::unique_ptr<ObjetPhysique>> object_list={},std::vector<std::unique_ptr<Contrainte>> constraints_={}, std::vector<std::unique_ptr<ChampForces>> force_field_={}, std::unique_ptr<integrateur> integrator_ = std::unique_ptr<integrateur>(new integrateurEulerCromer())/*std::make_unique<integrateurEulerCromer>(), ne fonctionne qu'avec c++14*/);
    
        virtual void dessine_sur(SupportADessin& support)override; //a copier coller dans toutes les sous classes de dessinable


        void add_object(std::unique_ptr<ObjetPhysique> o);
        void add_constraint(std::unique_ptr<Contrainte> c);
        void add_force_field(std::unique_ptr<ChampForces> f);
        void change_integrator(std::unique_ptr<integrateur> new_f);
        void append_constraint(unsigned int i, unsigned int j);
        void append_force_field(unsigned int i, unsigned int j);
        double get_time();

        ObjetPhysique* get_obj(int i)const;

        void evolve(double dt);
        virtual void whoami(std::ostream& out) const override;
        virtual void affiche(std::ostream& sortie)const override;

};