#include <vector> 
#include "ObjetIntegrable.h"
#include "contrainte.h"
#include "Integrateurs.h"
#include "Printable.h"
#include <memory>

class Systeme:: Printable{
    
    private :
        std::vector<std::unique_ptr<ObjetPhysique>> sys_objects;
        // j'utilise des unique ptr pour simplifier l'utilisation
        // j'utilise des objets physiques car j'ai besoin d'objets qui ont des contraintes/champforces en attribut

        std::vector<std::unique_ptr<Contrainte>> sys_constraints;
        std::vector<std::unique_ptr<ChampForces>> sys_force_field;
        std::unique_ptr<integrateur> integrator;


        double time; // peut être utiliser un SHARED_PTR pour le temps, ce serait bien
        // Si pas de shared_ptr, faut que tout les bidules qui utilisent time passent par REFERENCE

        
    public :

        Systeme(std::vector<std::unique_ptr<ObjetPhysique>> object_list={},std::vector<std::unique_ptr<Contrainte>> constraints_={}, std::vector<std::unique_ptr<ChampForces>> force_field_={}, std::unique_ptr<integrateur> integrator_):
        sys_objects(object_list),sys_constraints(constraints_),sys_force_field(force_field_),integrator(std::move(integrator_)){time = 0;}
    
        void add_object(std::unique_ptr<ObjetPhysique> o){
            sys_objects.push_back(o);
        }
        void add_constraint(std::unique_ptr<Contrainte> c){
            sys_constraints.push_back(c);
        }
        void add_force_field(std::unique_ptr<ChampForces> f){
            sys_force_field.push_back(f);
        }
        void change_integrator(std::unique_ptr<integrateur> new_f){
            integrator = move(new_f);
        }

        void append_constraint(unsigned int i, unsigned int j){
            sys_objects[j];
        }

        double get_time(){return time;}


//A DEFINIR : whoami, liste de champforce et liste de contrainre dans ObjetPhysique, surcharge externe générale de << 
        virtual void affiche(std::ostream& sortie)const override{
            sortie << "Systeme : à t = " << time <<" :" << std::endl;
            for (int i(0);i<sys_objects.size();i++){
                sortie << "Objet no " << i << " : " << sys_objects[i]->whoami() <<" : " <<std::endl;
                sortie << sys_objects[i] << std::endl;
                sortie << "" << std::endl;
                //contrainte relative à l'objet est gérée par l'affichage de l'objet
            }
            for (int j(0);j<sys_force_field.size();j++){
                sortie << "Champ no " << j << sys_force_field[j]->whoami() << sys_force_field[j];
                // je dois faire <<sys_force_field[j] ou utiliser la fonction affiche de sys_force_field[j]?
                // ça s'applique aussi à sys_objects
            }
            for (int k(0);k<sys_force_field.size();k++){
                sortie << "Contrainte no " << k << sys_constraints[k]->whoami() << std::endl;
            }

        }
};