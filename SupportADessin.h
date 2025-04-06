#pragma once
#include "ObjetDessinable.h"
#include "PointMateriel.h"
#include "ObjetIntegrable.h"


class SupportADessin{
    public:
        virtual ~SupportADessin() = default; // on suppose ici que les supports ne seront ni copiés ni déplacés
        virtual void dessine(PointMateriel const&) = 0;
        //virtual void dessine(Systeme const&) = 0;
        //virtual void dessine(Solide const&) = 0; // exemple, non abordé dans ce projet
        // ... autres choses que vous voudriez « dessiner »...
};

class TextViewer : public SupportADessin{

    public :
        virtual void dessine(PointMateriel const& p){std::cout << p.affiche() << std::endl;}
    private :
};