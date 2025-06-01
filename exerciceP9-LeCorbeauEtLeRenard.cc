#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include "VecteurV.h"
#include "ChampForces.h"
#include "GravitationConstante.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"

#define M_PI 3.14159265358979323846

void corbeaurenard(double temps, double pas, unsigned int nb_iter, double precision = 1e-3){
    //affichage gnuplot
        std::vector<double> x_fromage;
        std::vector<double> y_fromage;
        std::vector<double> z_fromage;

        std::vector<double> x_caillou;
        std::vector<double> y_caillou;
        std::vector<double> z_caillou;
    
    //Création du système
    Systeme sys;

    //paramètres
    double hauteur = 10;
    double distance = 10;
    double L2D2 = pow(distance, 2) + pow(hauteur, 2);
    //vitesse minimale pour avoir une collision d'après la formule trouvé dans l'exercice, v>sqrt(g*(distance^2 + hauteur^2/(2*hauteur)))
    double vitesse_initiale = sqrt(9.81 * (L2D2 / (2 * hauteur))) + 1e-3; //on rajoute une petite valeur pour être sûr d'avoir une collision
    //double vitesse_initiale = 10; //pour mettre une vitesse initiale arbitraire
    double tanangle = hauteur/distance;
    double angle = atan(tanangle); //déjà en radians
    //les masses n'influent pas sur le mouvement, mais on les met quand même
    double masse_fromage = 1;
    double masse_pierre = 1;
    double t_coll = sqrt(L2D2) / vitesse_initiale; //comme trouvé dans l'exercice
    
    // on mets les vecteurs à 3 dimensions car gravitation constante est faite pour avoir la gravité en z 
    Vecteur fromage(std::vector<double>{0, distance, hauteur});
    Vecteur pierre(3);
    Vecteur vitesse_pierre(std::vector<double>{0, vitesse_initiale*cos(angle), vitesse_initiale*sin(angle)});
    Vecteur vitesse_fromage(3);
    PointMateriel fromage_objet(fromage, vitesse_fromage, masse_fromage);
    PointMateriel pierre_objet(pierre, vitesse_pierre, masse_pierre);

    //contraintes
    Libre libre;

    //champ de force
    GravitationConstante gravitation;

    //mode d'affichage
    TextViewer txt(std::cout);

    //ajout des objets, contraintes et champs de force au système
    sys.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(fromage_objet)));
    sys.add_object(std::unique_ptr<PointMateriel>(new PointMateriel(pierre_objet)));
    sys.add_constraint(std::unique_ptr<Libre>(new Libre(libre)));
    sys.add_force_field(std::unique_ptr<GravitationConstante>(new GravitationConstante(gravitation)));
    sys.append_constraint(0, 0);//on ajoute la contrainte libre au fromage
    sys.append_constraint(0, 1);//on ajoute la contrainte libre à la pierre
    sys.append_force_field(0, 0);//on ajoute le champ de force gravitationnel au fromage
    sys.append_force_field(0, 1);//on ajoute le champ de force gravitationnel à la pierre

    double iteration = temps / pas;

    for(int i = 0; i < iteration; i ++){

            x_fromage.push_back(sys.get_obj(0)->get_E().get_coord(0));
            y_fromage.push_back(sys.get_obj(0)->get_E().get_coord(1));
            z_fromage.push_back(sys.get_obj(0)->get_E().get_coord(2));

            x_caillou.push_back(sys.get_obj(1)->get_E().get_coord(0));
            y_caillou.push_back(sys.get_obj(1)->get_E().get_coord(1));
            z_caillou.push_back(sys.get_obj(1)->get_E().get_coord(2));

        if(i % nb_iter == 0){
            std::cout << "t = " << sys.get_time() << std::endl;
            sys.dessine_sur(txt);
        }
        
        if(std::abs(t_coll-sys.get_time()) < precision){
            std::cout << "Collision entre le fromage et la pierre à t = " << sys.get_time() << std::endl;
            sys.dessine_sur(txt);
                break; //on arrête la simulation à la collision
        }
        sys.evolve(pas);
    }

std::ofstream fichier_test;
fichier_test.open("exerciceP9_corbeau_renard.dat",std::ios::out);

for(int i(0); i<x_fromage.size();i++){

    fichier_test<< 
    x_fromage[i] << " " << y_fromage[i] << " " << z_fromage[i] << " " <<
    x_caillou[i] << " " << y_caillou[i] << " " << z_caillou[i]<< "\n";

}

fichier_test.close();

std::ofstream graphe("graphe3D_exerciceP9_corbeau_renard.gp");
graphe << "set encoding utf8\n";   
graphe << "set title \"Le Corbeau et le Renard\"\n";
graphe << R"(
set label 1 "Maître corbeau, sur un arbre perché,\nTenait en son bec un fromage.\nMaître renard, par l'odeur alléché,\nLui tint à peu près ce langage :\n« Hé ! bonjour, Monsieur du Corbeau.\nQue vous êtes joli ! que vous me semblez beau !\nSans mentir, si votre ramage\nSe rapporte à votre plumage,\nVous êtes le phénix des hôtes de ces bois. »\nÀ ces mots, le corbeau ne se sent pas de joie ;\nEt pour montrer sa belle voix,\nIl ouvre un large bec, laisse tomber sa proie.\nLe renard s’en saisit, et dit : « Mon bon monsieur,\nApprenez que tout flatteur\nVit aux dépens de celui qui l’écoute.\nCette leçon vaut bien un fromage sans doute. »\nLe corbeau honteux et confus,\nJura, mais un peu tard, qu’on ne l’y prendrait plus." at screen 0.5,0.9 center
)";
graphe << "set xlabel \"X\" \n";  
graphe << "set ylabel \"Y\" \n";
graphe << "set zlabel \"Z\" \n";
graphe << "set grid\n";
graphe << "set ticslevel 0\n";
graphe << "splot \\\n";
graphe << "  \"exerciceP9_corbeau_renard.dat\" using 1:2:3 with linespoints lt rgb \"yellow\" pt 9 ps 0.8 lw 1.2 title \"fromage\", \\\n";
graphe << "  \"exerciceP9_corbeau_renard.dat\" using 4:5:6 with linespoints lt rgb \"gray\" pt 9 ps 0.8 lw 1.2 title \"pierre\", \n";
graphe << "pause -1\n";
graphe.close();
system("gnuplot graphe3D_exerciceP9_corbeau_renard.gp");
    


}

int main(){
    double temps = 5; //temps de la simulation en secondes
    double pas = 0.001; //pas de temps
    unsigned int nb_iter = 100; //limite le nombre d'affichage

    corbeaurenard(temps, pas, nb_iter);

    return 0;
}