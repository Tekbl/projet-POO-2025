#include <iostream>

using namespace std;

class Printable{
    public:
        virtual void affiche(ostream& out) const = 0;
        virtual ~Printable() = default;
};


ostream& operator<<(ostream& out, const Printable& print){
    print.affiche(out);
    return out;
}