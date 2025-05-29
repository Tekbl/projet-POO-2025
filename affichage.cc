#include <iostream>
#include "affichage.h"

using namespace std;

ostream& operator<<(ostream& out, const Printable& print){
    print.affiche(out);
    return out;
}