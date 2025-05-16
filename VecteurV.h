#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include "affichage.h"


class Vecteur: public Printable{

public:

    //constructeurs
    Vecteur(unsigned int dimension):vecteur(dimension,0.0){}
    Vecteur(double x, double y, double z):vecteur{x,y,z}{}
    //initialise vecteur avec un vector de double de dimension quelconque,on le passe par référence constant pour ne pas créér de copies et ne pas faire de modifications sur le vector entré
    Vecteur(const std::vector<double>& liste_dinit):vecteur(liste_dinit){}
    Vecteur()=default; //constructeur par défaut
    //mise en place et affichage des vecteurs
    virtual void affiche(std::ostream& out) const override;
    void set_coord(int i,double v);
    double get_coord(int i) const;
    void augmente(double v);
    virtual void whoami(std::ostream& out)const override;
    
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
    Vecteur operator*(double d)const;
    Vecteur operator^(const Vecteur& B);
    friend const Vecteur operator+(Vecteur A, const Vecteur& B);
    friend const Vecteur operator-(Vecteur A, const Vecteur& B);
    Vecteur operator~() const;

private:
    std::vector<double> vecteur; //on utilise un vector car on peut modifier leur taille (dimension) contrairement aux array
};