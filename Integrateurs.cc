#include <iostream>
#include <vector>
#include <cmath>
#include "Integrateurs.h"
#include "VecteurV.h"
#include "ObjetIntegrable.h"




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



    /*A DELETE DANS LA VERSION FINALE
    
    =============FONCTIONNEPAS=========================
    obj->set_E_pr(obj->get_E_pr() + obj->evolution((abs(t)))*dt); //évolue E_pr
    obj->set_E(obj->get_E() + obj->get_E_pr()*abs(dt)); //évolue E
    

    std::cout << "pos : " << pos << std::endl;
    std::cout << "vit_dt : " << obj->get_E_pr()*dt << std::endl;
    std::cout << "new_pos : " << new_pos << std::endl;
    std::cout << "ligne evolue E : "<< obj->get_E() + obj->get_E_pr()*abs(dt) << std::endl;

    std::cout << "position evolue: " << obj->get_E();
    std::cout << "vitesse evolue : " << obj->get_E_pr() << std::endl;
    */
}







