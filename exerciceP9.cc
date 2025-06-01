#include <vector>
#include <iostream>
#include <fstream>
#include "VecteurV.h"
#include "ChampForces.h"
#include "ForceCentrale.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"

void simulation(double temps, double interval_temps, unsigned int nb_iter){   
    
    std::vector<double> x_pos;
    std::vector<double> y_pos; 
    std::vector<double> z_pos;

    Systeme sys;
    double rayon_terre = -6371e3;
    double altitude = 10;
    double masse_terre = 5.972e24;
    double masse_pomme = 0.1;

    //si on veut comparer aux valeurs théoriques
    //double g = (G * masse_terre) / (rayon_terre * rayon_terre);
    //double altitude_initiale = altitude;


    //initialisation des objets
    Vecteur position_terre(0, 0, rayon_terre);
    Vecteur vitesse_terre(3);
    Vecteur position_pomme(0, 0, altitude);
    Vecteur vitesse_pomme(3);
    PointMateriel pomme(position_pomme, vitesse_pomme, masse_pomme);
    PointMateriel terre(position_terre, vitesse_terre, masse_terre);
    ChampNewtonien TsurP(terre);
    ChampNewtonien PsurT(pomme);
    Libre libre;
   
    //ajouts des objets au système
    sys.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(pomme)));
    sys.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(terre)));
    sys.add_constraint(std::unique_ptr<Libre>(new Libre(libre)));
    sys.add_force_field(std::unique_ptr<ChampNewtonien>(new ChampNewtonien(TsurP)));
    sys.add_force_field(std::unique_ptr<ChampNewtonien>(new ChampNewtonien(PsurT)));
    sys.append_constraint(0, 0);//on ajoute la contrainte libre à la pomme
    sys.append_constraint(0, 1);//on ajoute la contrainte libre à la terre
    TextViewer txt(std::cout);
    double iteration = temps / interval_temps;
    sys.append_force_field(0,0);//on ajoute la force de la terre sur la pomme à la pomme
    sys.append_force_field(1,1);//on ajoute la force de la pomme sur la terre à la terre
    for(int t = 0; t <= iteration; t++){
            if(t % nb_iter == 0){
                std::cout << "t = " << sys.get_time() << std::endl;
                sys.dessine_sur(txt);
            } 
        x_pos.push_back(sys.get_obj(0)->get_E().get_coord(0));
        y_pos.push_back(sys.get_obj(0)->get_E().get_coord(1));
        z_pos.push_back(sys.get_obj(0)->get_E().get_coord(2));
        sys.evolve(interval_temps);
    }


std::ofstream fichier_test;
fichier_test.open("exerciceP9_pomme.dat",std::ios::out);

for(int i(0); i<x_pos.size();i++){

    fichier_test<< x_pos[i] << " " << y_pos[i] << " " << z_pos[i] << "\n" ;

}

fichier_test.close();


std::ofstream graphe("graphe3D_exerciceP9_pomme.gp");
graphe << " set title \"Chute d'une pomme vers la terre\" \n";
graphe << "set xlabel \"X\" \n";
graphe << "set ylabel \"Y\" \n";
graphe << "set zlabel \"Z\" \n";
graphe << "set grid\n";
graphe << "set ticslevel 0\n";
graphe << "splot \"exerciceP9_pomme.dat\" using 1:2:3 with linespoints lt rgb \"red\" pt 9 ps 0.8 lw 1.2 title \"pomme\"\n";
graphe << "pause -1\n";
graphe.close();
system("gnuplot graphe3D_exerciceP9_pomme.gp");



}

    
int main(){

    double temps = 0.1; //temps de la simulation en secondes
    double interval_temps = 0.001; //intervalle de temps entre chaque itération de la simulation
    unsigned int nb_iter = 15; //nombre d'itérations de la simulation
    simulation(temps, interval_temps, nb_iter);
    return 0;
}