#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
#include "VecteurV.h"
#include "ChampForces.h"
#include "ObjetIntegrable.h"
#include "GravitationConstante.h"
#include "ContrainteSpherique.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "SupportADessin.h"
#include "Integrateurs.h"
#include "ObjetDessinable.h"

#define M_PI 3.14159265358979323846
std::vector<double> x_1,y_1,z_1;

void simul_spherique(double temps, double pas, unsigned int nb_iter){
    Systeme systeme;

    //définition de l'intégrateur à utiliser, par défaut on utilise celui d'Euler-Cromer
    //décommenter les lignes de l'intégrateur et de sont ajout au système pour l'utiliser
    //RungeKutta4 Rk4;
    //Newmark New;
    //systeme.change_integrator(std::unique_ptr<integrateur>(new RungeKutta4(Rk4)));
    //systeme.change_integrator(std::unique_ptr<integrateur>(new Newmark(New)));

    //initialisation du pendule 
    double longueur = 2.2; 
    std::vector<double> pos_init = {M_PI/6,0};//teta=M_PI/6, phi=0
    std::vector<double> vit_init = {0,1};//teta'=0, phi'=1
    //on itnitialise le pendule avec une position initiale une vitesse initiale, une masse de 0.1, pas de charge éléctrique et un degré de liberté de 2 
    PointMateriel_angulaire pendule(Vecteur(pos_init), Vecteur(vit_init),0.1,0,2);

    //contrainte
    ContrainteSpherique contrainte(longueur);

    //champ de force
    GravitationConstante gravitation;

    // mode d'affichage
    TextViewer txt(std::cout);

    ContrainteSpherique* ptc = &contrainte;

    systeme.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(pendule)));
    systeme.add_constraint(std::unique_ptr<Contrainte>(new ContrainteSpherique(contrainte)));
    systeme.add_force_field(std::unique_ptr<ChampForces>(new GravitationConstante(gravitation)));

    systeme.append_constraint(0, 0);//on ajoute la contrainte sphérique au pendule
    systeme.append_force_field(0, 0);//on ajoute le champ de force gravitationnel au pendule

    double iteration = temps / pas;

    //on affiche la méthode d'intégration utilisée
    std::cout << "Methode d'integration : " ;
    systeme.display_integrator(std::cout);
    std::cout << std::endl;


    //on utilise setw et left comme dans exercieP11-magnetique pour faire un affichage propre
    //setprecision permet de définir le nombre de chiffres après la virgule
    std::cout << std::left << std::setw(10) << "t" << std::left << std::setw(22) << "x" << std::left <<std::setw(22) << "y" << "z" << "\n";
    for(int i = 0; i <= iteration; i++){
        if(i % nb_iter == 0){
                std::cout 
                << std::left << std::setw(5) << std::setprecision(5) <<systeme.get_time() << "     " 

                << std::left << std::setw(17)<< std::setprecision(16) << systeme.get_obj(0)->position(ptc).get_coord(0) << "     ";

                std::cout  
                << std::left << std::setw(19) << std::setprecision(16) << systeme.get_obj(0)->position(ptc).get_coord(1) << "   ";
                std::cout 
                << std::left << std::setw(5) << std::setprecision(16) << systeme.get_obj(0)->position(ptc).get_coord(2) << std::endl;
            } 
        x_1.push_back(-systeme.get_obj(0)->position(ptc).get_coord(0));
        y_1.push_back(-systeme.get_obj(0)->position(ptc).get_coord(1));
        z_1.push_back(-systeme.get_obj(0)->position(ptc).get_coord(2));

        systeme.evolve(pas);
    }

    std::cout << std::setprecision(4) << std::endl;
    systeme.dessine_sur(txt); //affichage du pendule à la fin de la simulation


    //sauvegarde des données
    std::ofstream fichier_test;
    fichier_test.open("pendule.dat",std::ios::out);

    for(int i(0); i<x_1.size();i++){

        fichier_test<< 
        x_1[i] << " " << y_1[i] << " " << z_1[i] << "\n";
    }

    fichier_test.close();
    std::ofstream graphe("graphe3D_pendule.gp");
    graphe << "set title \"ExerciceP11-spherique\"\n";
    graphe << "set xlabel \"X\"\n";
    graphe << "set ylabel \"Y\"\n";
    graphe << "set zlabel \"Z\"\n";
    graphe << "set grid\n";
    graphe << "set ticslevel 0\n";
    graphe << "splot \\\n";
    graphe << "  \"pendule.dat\" using 1:2:3 with linespoints lt rgb \"red\" pt 9 ps 0.8 lw 1.2 title \"Pendule\", \n";
    graphe << "pause mouse close\n";
    graphe.close();
    system("gnuplot graphe3D_pendule.gp");

    delete ptc; //on supprime le pointeur pour éviter les fuites de mémoire
}

int main(){
    double temps = 0.1; //temps de la simulation en secondes
    double pas = 0.001; //pas de temps
    unsigned int nb_iter = 10; //limite le nombre d'affichage

    simul_spherique(temps, pas, nb_iter);

    return 0;
}