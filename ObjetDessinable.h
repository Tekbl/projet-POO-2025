#pragma once
#include "SupportADessin.h"
#include "ObjetIntegrable.h"

class Dessinable : public ObjetPhysique {

    public :
        virtual void dessine_sur(SupportADessin& support) { support.dessine(*this); } //a copier coller dans toutes les sous classes de dessinable
    private : 

};