#include <iostream>
#include "SupportADessin.h"
#include "PointMateriel.h"
#include "ObjetIntegrable.h"
#include "Systeme.h"


TextViewer::TextViewer(std::ostream& flot_):flot(flot_){}

void TextViewer::dessine(PointMateriel const& p){flot << p << std::endl;}
void TextViewer::dessine(Systeme const& s){flot << s << std::endl;}


