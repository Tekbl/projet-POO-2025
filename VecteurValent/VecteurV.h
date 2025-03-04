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
   
};