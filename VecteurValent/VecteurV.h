#pragma once
#include <vector>
#include <cmath>


class Vecteur{

public:
    void affiche() const;
    void set_coord(int i,double v);
    double get_coord(int i) const;
    void augmente(double v);
    bool compare(Vecteur B, int precision=1e-10) const;


private:
    vector<double> vecteur; //on utilise un vector car on peut modifier leur taille (dimension) contrairement aux array
    void affiche() const{for(auto element:vecteur){cout << element << " ";}; cout << endl;}
    void set_coord(int i,double v){vecteur[i] = v;}
    double get_coord(int i)const {return vecteur[i];}
    void augmente(double v){vecteur.push_back(v);}
    int dim = vecteur.size(); // on fixe n pour eviter de refaire appel à la fonction size() pour chaque opération 

};