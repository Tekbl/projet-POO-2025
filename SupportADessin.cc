#include <iostream>
#include "ObjetDessinable.h"
#include "PointMateriel.h"
#include "ObjetIntegrable.h"

class SupportADessin{
    public:
        virtual ~SupportADessin() = default; // on suppose ici que les supports ne seront ni copiés ni déplacés
        virtual void dessine(std::ostream& sortie, PointMateriel const&)=0;
        //virtual void dessine(Systeme const&) = 0;
        //virtual void dessine(Solide const&) = 0; // exemple, non abordé dans ce projet
        // ... autres choses que vous voudriez « dessiner »...
    private : 
        std::ostream& flot; 
};

class TextViewer : public SupportADessin{

    public :
        virtual void dessine(PointMateriel const& p)override{std::cout << p << std::endl;}
    private :
         
};