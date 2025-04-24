#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include "affichage.h"


class Vecteur: public Printable{

public:

    //constructeurs
    Vecteur(unsigned int dimension);
    Vecteur(double x, double y, double z);
    Vecteur(const std::vector<double>& liste_dinit);

    //mise en place et affichage des vecteurs
    virtual void affiche(ostream& out) const override;
    void set_coord(int i,double v);
    double get_coord(int i) const;
    void augmente(double v);
    
    //opérations sur les vecteurs
    bool compare(const Vecteur& B, double precision=1e-10) const;
    Vecteur addition(const Vecteur& X) const;
    Vecteur soustraction(const Vecteur& X) const;
    Vecteur oppose() const;
    Vecteur mult(double scalaire) const;
    double prod_scalaire(const Vecteur& B) const;
    Vecteur prod_vect(Vecteur B) const;
    double norme() const;
    double norme2() const;
    Vecteur unitaire() const;

    //opérateurs
    bool operator==(const Vecteur& B) const;
    bool operator!=(const Vecteur& B) const;
    void operator+=(const Vecteur& B);
    void operator-=(const Vecteur& B);
    void operator*=(double d);
    Vecteur operator*(double d);
    Vecteur operator^(const Vecteur& B);
    friend const Vecteur operator+(Vecteur A, const Vecteur& B);
    friend const Vecteur operator-(Vecteur A, const Vecteur& B);
    Vecteur operator~() const;

private:
   
};