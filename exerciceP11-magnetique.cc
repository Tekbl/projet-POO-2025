#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "VecteurV.h"
#include "affichage.h"
#include "ChampForces.h"
#include "ObjetIntegrable.h"
#include "ForceCentrale.h"
#include "Integrateurs.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "SupportADessin.h"
#include "ObjetDessinable.h"
#include "ChampSupplementaires.h"
#include "contrainte.h"
using namespace std;

//Dependances de la cible dans le makefile : VecteurV.o affichage.o ObjetIntegrable.o ChampForces.o ForceCentrale.o Systeme.o PointMateriel.o ObjetDessinable.o ChampSupplementaires.o contrainte.o

int main(){
vector<double> x_pos;
vector<double> y_pos; //pour stocker les données de simulations et l'afficher sur gnuplot
vector<double> z_pos; 


Systeme systeme;

Vecteur Mag(0,0,0.5);
Vecteur Electro(0,0,0);
double lambda(1.33e-5);
Libre libre; 
double m = 1.5e-4;   
double q = 2e-6;
Vecteur pos(0,0,0);
Vecteur vit(0.3,0,0);

double t_simu = 0.4;  
double dt = 0.001; 
int iter = t_simu/dt;

TextViewer txt(std::cout); //mode d'affichage texte avec la méthode dessine_sur

integrateurEulerCromer euler; //les différents intégrateurs
RungeKutta4 Rk4;
Newmark New;

ChampElectroMagnetique ElectroMag(Electro,Mag); //Initialisation des ChampsForces
ChampFrottements frottements(lambda);
std::vector<ChampForces*> champs_;
champs_.push_back(&ElectroMag);
champs_.push_back(&frottements);

ChampCompose un_champ_de_ble(champs_); //composition des ChampForces

PointMateriel particule(pos,vit,m,q,3); //création de la particule
particule.add_champ(&un_champ_de_ble); //on lui attribue les champsforces
particule.add_contr(&libre); //on lui ajoute la contrainte libre 

systeme.add_object(std::unique_ptr<ObjetPhysique>(new PointMateriel(particule)));
systeme.add_constraint(std::unique_ptr<Contrainte> (new Libre(libre))); //on ajoute tous les objets au système
systeme.add_force_field(std::unique_ptr<ChampForces> (new ChampCompose(un_champ_de_ble)));

//=========================CHANGER_INTEGRATEUR=============================================
systeme.change_integrator(std::unique_ptr<integrateur>(new RungeKutta4(Rk4))); //mettre celui la en commentaire pour utiliser Euler
//systeme.change_integrator(std::unique_ptr<integrateur>(new Newmark(New))); //mettre RungeKutta en commentaire et enlever les commentaires ici pour utiliser Newmark
//=========================================================================================
//systeme.get_champ(0)->force(*(systeme.get_obj(0)), 2);

//début de l'affichage
std::cout << "Methode d'integration : " ;
systeme.display_integrator(std::cout);
std::cout << std::endl;
 
std::cout << std::left << std::setw(10) << "t"
<< std::left << std::setw(15) << "x"
<< std::left <<std::setw(15) << "y"
<< "z" << "\n";

//on utilise setw et left pour que l'affichage soit pico bello

for(int i(0); i<iter; i++){
    std::cout 
    << std::left << std::setw(5) <<std::setprecision(5) <<systeme.get_time() << "     " 

    << std::left << std::setw(10)<< systeme.get_obj(0)->get_E().get_coord(0) << "     ";

    std::cout  
    << std::left << std::setw(12) << systeme.get_obj(0)->get_E().get_coord(1) << "   ";
    std::cout 
    << std::left << std::setw(5) << systeme.get_obj(0)->get_E().get_coord(2) << std::endl;

    x_pos.push_back(systeme.get_obj(0)->get_E().get_coord(0));
    y_pos.push_back(systeme.get_obj(0)->get_E().get_coord(1)); //on sauvegarde les données 
    z_pos.push_back(systeme.get_obj(0)->get_E().get_coord(2));

    systeme.evolve(dt); //on invoque l'intégrateur 
}

std::cout << std::endl;
systeme.dessine_sur(txt);

ofstream fichier_test;
fichier_test.open("exerciceP11_magnetique.dat",ios::out);

for(int i(0); i<x_pos.size();i++){

    fichier_test<< x_pos[i] << " " << y_pos[i] << " " << z_pos[i] << "\n" ;

}

fichier_test.close();


ofstream graphe("graphe3D_exerciceP11_magnetique.gp");
graphe << " set title \"Trajectoire 3D du point materiel dans un champ electromagnetique avec frottements\" \n";
graphe << "set xlabel \"X\" \n";
graphe << "set ylabel \"Y\" \n";
graphe << "set zlabel \"Z\" \n";
graphe << "set grid\n";
graphe << "set ticslevel 0\n";
graphe << "splot \"exerciceP11_magnetique.dat\" using 1:2:3 with lines title \"particule chargee\"\n";
graphe << "pause -1\n";
graphe.close();
system("gnuplot graphe3D_exerciceP11_magnetique.gp");



return 0;    
}


/*
C'est MAGIQUE

                                 ....
                                .'' .'''
.                             .'   :
\\                          .:    :
 \\                        _:    :       ..----.._
  \\                    .:::.....:::.. .'         ''.
   \\                 .'  #-. .-######'     #        '.
    \\                 '.##'/ ' ################       :
     \\                  #####################         :
      \\               ..##.-.#### .''''###'.._        :
       \\             :--:########:            '.    .' :
        \\..__...--.. :--:#######.'   '.         '.     :
        :     :  : : '':'-:'':'::        .         '.  .'
        '---'''..: :    ':    '..'''.      '.        :'
           \\  :: : :     '      ''''''.     '.      .:
            \\ ::  : :     '            '.      '      :
             \\::   : :           ....' ..:       '     '.
              \\::  : :    .....####\\ .~~.:.             :
               \\':.:.:.:'#########.===. ~ |.'-.   . '''.. :
                \\    .'  ########## \ \ _.' '. '-.       '''.
                :\\  :     ########   \ \      '.  '-.        :
               :  \\'    '   #### :    \ \      :.    '-.      :
              :  .'\\   :'  :     :     \ \       :      '-.    :
             : .'  .\\  '  :      :     :\ \       :        '.   :
             ::   :  \\'  :.      :     : \ \      :          '. :
             ::. :    \\  : :      :    ;  \ \     :           '.:
              : ':    '\\ :  :     :     :  \:\     :        ..'
                 :    ' \\ :        :     ;  \|      :   .'''
                 '.   '  \\:                         :.''
                  .:..... \\:       :            ..''
                 '._____|'.\\......'''''''.:..'''

*/