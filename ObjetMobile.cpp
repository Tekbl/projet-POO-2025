#include <vector>
#include "VecteurV.h"

using namespace std;

class ObjetMobile{
    public:
        ObjetMobile(Vecteur E, Vecteur E_pr):E_(E),E_pr_(E_pr){};
        void evolution(double t);
    private:
        Vecteur E_;
        Vecteur E_pr_;

};

void ObjetMobile::evolution(double t){

}