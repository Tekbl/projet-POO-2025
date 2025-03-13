#pragma once
#include <vector>
#include <cmath>


class Vecteur{

public:
    void affiche() const;
    void set_coord(int i,double v);
    double get_coord(int i) const;
    void augmente(double v);
    bool compare(Vecteur B, double precision=1e-10) const;
    Vecteur addition(Vecteur X) const;
    Vecteur soustraction(Vecteur X) const;
    Vecteur oppose() const;
    Vecteur mult(double scalaire) const;
    double prod_scalaire(Vecteur B) const;
    Vecteur prod_vect(Vecteur B) const;
    double norme() const;
    double norme2() const;
    Vecteur unitaire() const;
    friend ostream& operator<<(ostream& sortie,const Vecteur& v);

private:
   
};