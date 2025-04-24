#pragma once
#include "ObjetDessinable.h"
#include "PointMateriel.h"
#include "ObjetIntegrable.h"


class SupportADessin{
   
   
    public:

        SupportADessin() = default;
        virtual ~SupportADessin() = default; // on suppose ici que les supports ne seront ni copiés ni déplacés
        
        
        virtual void dessine(PointMateriel const& p) = 0;

    private :
        std::ostream& flot;
};

class TextViewer : public SupportADessin{

    public :
        virtual void dessine(PointMateriel const& p){std::cout << p << std::endl;}
    private :
};