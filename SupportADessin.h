#pragma once
#include <iostream>
#include "ObjetIntegrable.h"
class PointMateriel;
class Systeme;

class SupportADessin{
    public:
        virtual ~SupportADessin() = default;
        //virtual void dessine(SupportADessin const& s)=0;
        virtual void dessine(PointMateriel const& p)=0;
        virtual void dessine(Systeme const& s) = 0;
};

class TextViewer : public SupportADessin{

    private :
        std::ostream& flot; 
    public :
    
        TextViewer(std::ostream& flot_);
        virtual ~TextViewer()=default;

        virtual void dessine(PointMateriel const& p) override;
        virtual void dessine(Systeme const& s)override;



        TextViewer(TextViewer const&) = delete;
        TextViewer& operator=(TextViewer const&) = delete;
        TextViewer(TextViewer&&) = default;
        TextViewer& operator=(TextViewer&&) = default;


};