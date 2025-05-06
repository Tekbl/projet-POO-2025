#include <iostream>
#include "affichage.h"

using namespace std;

/*class Printable{
    public:
        virtual void affiche(ostream& out) const = 0;
        virtual ~Printable() = default;
        virtual void whoami(ostream& out)const = 0;
};*/


ostream& operator<<(ostream& out, const Printable& print){
    print.affiche(out);
    return out;
}