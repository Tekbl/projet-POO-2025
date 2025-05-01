#include <vector> 
#include "ObjetIntegrable.h"
#include "SupportADessin.h"
#include "contrainte.h"
#include "Integrateurs.h"
#include "affichage.h"
#include "ObjetDessinable.h"
#include "Champforces.h"
#include <memory>

class Systeme : public Printable, public Dessinable{
    
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
        Systeme(std::vector<std::unique_ptr<ObjetPhysique>> object_list={},std::vector<std::unique_ptr<Contrainte>> constraints_={}, std::vector<std::unique_ptr<ChampForces>> force_field_={}, std::unique_ptr<integrateur> integrator_ = std::unique_ptr<integrateur>(new integrateurEulerCromer())/*std::make_unique<integrateurEulerCromer>(), ne fonctionne qu'avec c++14*/):
        sys_objects(std::move(object_list)),sys_constraints(std::move(constraints_)),sys_force_field(std::move(force_field_)),integrator(std::move(integrator_)){time = 0;}

        virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); } //a copier coller dans toutes les sous classes de dessinable

        void add_object(std::unique_ptr<ObjetPhysique> o){
            sys_objects.push_back(std::move(o));
        }
        void add_constraint(std::unique_ptr<Contrainte> c){
            sys_constraints.push_back(std::move(c));
        }
        void add_force_field(std::unique_ptr<ChampForces> f){
            sys_force_field.push_back(std::move(f));
        }
        void change_integrator(std::unique_ptr<integrateur> new_f){
            integrator = move(new_f);
        }

        void append_constraint(unsigned int i, unsigned int j){
            sys_objects[j]->add_contr(sys_constraints[i].get());
        }
        
        void append_force_field(unsigned int i, unsigned int j){
            sys_objects[j]->add_champ(sys_force_field[i].get());
        }
        double get_time(){return time;}

        virtual void whoami(std::ostream& out) const override{
            out << "systeme";
        }


        virtual void affiche(std::ostream& sortie)const override{
            sortie << "Systeme : à t = " << time <<" :" << std::endl;
            for (int i(0);i<sys_objects.size();i++){
                sortie << "Objet no " << i << " : " <<std::endl;
                sys_objects[i]->whoami(sortie);
                sortie << sys_objects[i].get() << std::endl;
                sortie << "" << std::endl;
                //contrainte relative à l'objet est gérée par l'affichage de l'objet
            }
            for (int j(0);j<sys_force_field.size();j++){
                sortie << "Champ no " << j ;
                sys_force_field[j]->whoami(sortie);
                sortie << sys_force_field[j].get() << std::endl;
                // ça s'applique aussi à sys_objects
            }
            for (int k(0);k<sys_force_field.size();k++){
                sortie << "Contrainte no " << k ;
                sys_constraints[k]->whoami(sortie);
                sortie << std::endl;
            }

        }

        void evolue(double dt){
            for(int i(0);i<sys_objects.size();i++){
                integrator->evolue(sys_objects[i].get(),time,dt);
            }
            time += dt;
        }
};