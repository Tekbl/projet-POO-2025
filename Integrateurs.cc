#include <iostream>
#include <vector>
#include <cmath>
#include "Integrateurs.h"
#include "VecteurV.h"
#include "ObjetIntegrable.h"

void integrateur::affiche(std::ostream& out) const{
    out << "";
}

void integrateurEulerCromer::whoami(std::ostream& out)const{
    out << "EulerCromer";
}

void RungeKutta4::whoami(std::ostream& out)const{
    out << "Runge-Kutta ordre 4";
}

void Newmark::whoami(std::ostream& out)const{
    out << "Newmark";
}

void integrateurEulerCromer::evolue(ObjetMobile *obj, double t, double dt) {
    Vecteur vit = obj->get_E_pr();
    Vecteur vit_dt = obj->evolution(abs(t))*dt;

    obj->set_E_pr(vit + vit_dt); //évolue E_pr
    Vecteur new_vit = obj->get_E_pr();

    //std::cout << "EULER new vit : " << new_vit << std::endl;

    Vecteur pos = obj->get_E();
    Vecteur pos_dt = new_vit *dt;

    obj->set_E(pos + pos_dt); //évolue E

    //Vecteur new_pos = obj->get_E(); 
    //std::cout << "EULER new pos : " << new_pos << std::endl;
    

    //======avant on avait ça mais ça ne marchait pas==========================
    //obj->set_E_pr(obj->get_E_pr() + obj->evolution((abs(t)))*dt); //évolue E_pr
    //obj->set_E(obj->get_E() + obj->get_E_pr()*abs(dt)); //évolue E

}

void Newmark::evolue(ObjetMobile *obj, double t, double dt){
    Vecteur new_pos = obj->get_E();
    Vecteur new_vit = obj-> get_E_pr();
    Vecteur s = obj->evolution(t);
    Vecteur q(0);
    Vecteur r(0);

    Vecteur d(0);
    double e=1e-6;
    int i(0);
    do{
        q = new_pos;
        r = obj->evolution(t);
        new_vit = new_vit + (r+s)*(dt/2);
        new_pos = new_pos + obj->get_E_pr()*dt + (r*(1/2) + s)*((dt*dt)/3);
        d = new_pos-q;
        i++;
        if (i>100){throw("Newark overload");}// a remischer
    }while(d.norme()<e);

    obj->set_E_pr(new_vit);
    obj->set_E(new_pos);
}


void RungeKutta4::evolue(ObjetMobile *obj, double t, double dt){

Vecteur old_vit(obj->get_E_pr());
Vecteur old_pos(obj->get_E());

Vecteur k1 = old_vit;
Vecteur k1_ = obj->evolution(t);
/*
Vecteur E_1 = old_pos + k1*(dt/2); 
Vecteur E_pr_1 = old_vit + k1_*(dt/2); 

obj->set_E(E_1);
obj->set_E_pr(E_pr_1);
*/
Vecteur k2 = old_vit + k1_*(dt/2);
Vecteur k2_ = obj->evolution(t+dt/2);

/*
Vecteur E_2 =old_pos+k2*(dt/2); 
Vecteur E_pr_2 = old_vit+k2_*(dt/2); 

obj->set_E(E_2);
obj->set_E_pr(E_pr_2);
*/
Vecteur k3 = old_vit + k2_*(dt/2);
Vecteur k3_ = obj->evolution(t+dt/2);
/*
Vecteur E_3 = old_pos+k3*(dt/2); 
Vecteur E_pr_3 = old_vit+k2_*(dt/2); 

obj->set_E(E_3);
obj->set_E_pr(E_pr_3);
*/
Vecteur k4 = old_vit + k3_*dt ;
Vecteur k4_ = obj->evolution(t+dt);

obj->set_E_pr(old_vit);
obj->set_E(old_pos);

Vecteur new_vit = old_vit +(k1_ + k2_*2 + k3_*2 + k4_)*(dt/6);
Vecteur new_pos = old_pos + (k1 + k2*2 + k3*2 + k4)*(dt/6);

//std::cout<<  "new_pos : " << new_pos << std::endl;
//std::cout<<  "new_vit : " << new_vit << std::endl;


obj->set_E_pr(new_vit);
obj->set_E(new_pos);
}

  






