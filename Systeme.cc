#include <vector> 
#include "Systeme.h"
#include "ObjetIntegrable.h"
#include "SupportADessin.h"
#include "contrainte.h"
#include "Integrateurs.h"
#include "affichage.h"
#include "ObjetDessinable.h"
#include "ChampForces.h"
#include <memory>



        
Systeme::Systeme(std::vector<std::unique_ptr<ObjetPhysique>> object_list,std::vector<std::unique_ptr<Contrainte>> constraints_, std::vector<std::unique_ptr<ChampForces>> force_field_, std::unique_ptr<integrateur> integrator_ ):
sys_objects(std::move(object_list)),sys_constraints(std::move(constraints_)),sys_force_field(std::move(force_field_)),integrator(std::move(integrator_)){time = 0;}

void Systeme::dessine_sur(SupportADessin& support) { support.dessine(*this); } //a copier coller dans toutes les sous classes de dessinable

//ajout d'un objet physique, d'une contrainte ou d'un champ de force au système
void Systeme::add_object(std::unique_ptr<ObjetPhysique> o){sys_objects.push_back(std::move(o));}
void Systeme::add_constraint(std::unique_ptr<Contrainte> c){sys_constraints.push_back(std::move(c));}
void Systeme::add_force_field(std::unique_ptr<ChampForces> f){sys_force_field.push_back(std::move(f));}

void Systeme::change_integrator(std::unique_ptr<integrateur> new_f){integrator = move(new_f);}

//ajout de contrainte ou de champ de force à un objet physique
void Systeme::append_constraint(unsigned int i, unsigned int j){sys_objects[j]->add_contr(sys_constraints[i].get());}
void Systeme::append_force_field(unsigned int i, unsigned int j){sys_objects[j]->add_champ(sys_force_field[i].get());}

double Systeme::get_time(){return time;}
void Systeme::whoami(std::ostream& out) const{out << "systeme";}
void Systeme::display_integrator(std::ostream& out) const{integrator->whoami(out);}

ObjetPhysique* Systeme::get_obj(int i) const {
    return sys_objects[i].get();
};

ChampForces* Systeme::get_champ(int i) const {
    return sys_force_field[i].get();
};

Contrainte* Systeme::get_contr(int i) const {
    return sys_constraints[i].get();
};


void Systeme::evolve(double dt){
    //fait évoluer chaque objet du système en utilisant l'intégrateur choisi
    for(int i(0);i<sys_objects.size();i++){
        integrator->evolue(sys_objects[i].get(),time,dt);
    }
    time += dt;
}

void Systeme::affiche(std::ostream& sortie)const {
    sortie << "Systeme : à t = " << time <<" :" << std::endl;
    for (int i(0);i<sys_objects.size();i++){
        sortie << "Objet no " << i << " : " <<std::endl;
        sys_objects[i]->whoami(sortie);
        sortie << std::endl;
        sortie <<*sys_objects[i].get() << std::endl;
        sortie << "" << std::endl;
        //contrainte relative à l'objet est gérée par l'affichage de l'objet
    }
    for (int j(0);j<sys_force_field.size();j++){
        sortie << "Champ no " << j << ": ";
        sys_force_field[j]->whoami(sortie);
        sortie << std::endl;
        //sortie << *sys_force_field[j].get() << std::endl;
        // ça s'applique aussi à sys_objects
    }
    for (int k(0);k<sys_constraints.size();k++){
        sortie << "Contrainte no " << k << ": ";
        sys_constraints[k]->whoami(sortie);
        sortie << std::endl;
    }

}


