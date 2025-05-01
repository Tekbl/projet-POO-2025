CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall


#all = la première cible
all: exerciceP9


#include <vector>
#include <iostream>
#include "VecteurV.h"
#include "ChampForces.h"
#include "ForceCentrale.h"
#include "Systeme.h"
#include "PointMateriel.h"
#include "ObjetDessinable.h"

exerciceP9: exerciceP9.o VecteurV.o ChampForces.o ForceCentrale.o Systeme.o PointMateriel.o ObjetDessinable.o##fill stuff with dependencies

# Ces lignes ont été recopiées de la commande g++ -MM *.cc
# Ces lignes sont les dépendances de compilation 
affichage.o: affichage.cc
ChampForces.o: ChampForces.cc VecteurV.h affichage.h ObjetIntegrable.h \
 constantes.h contrainte.h
constantes.o: constantes.cc VecteurV.h affichage.h
contenu.o: contenu.cc ObjetDessinable.h SupportADessin.h \
 ObjetIntegrable.h VecteurV.h affichage.h constantes.h contrainte.h
contrainte.o: contrainte.cc VecteurV.h affichage.h ObjetIntegrable.h \
 constantes.h contrainte.h
exerciceP9.o: exerciceP9.cc VecteurV.h affichage.h ChampForces.h \
 ForceCentrale.h constantes.h ObjetIntegrable.h contrainte.h systeme.h \
 Integrateurs.h ObjetDessinable.h SupportADessin.h PointMateriel.h
ForceCentrale.o: ForceCentrale.cc ChampForces.h VecteurV.h affichage.h \
 constantes.h ObjetIntegrable.h contrainte.h
GravitationConstante.o: GravitationConstante.cc constantes.h VecteurV.h \
 affichage.h PointMateriel.h ObjetIntegrable.h contrainte.h \
 ObjetDessinable.h SupportADessin.h Champforces.h
Integrateurs.o: Integrateurs.cc VecteurV.h affichage.h ObjetIntegrable.h \
 constantes.h contrainte.h
ObjetDessinable.o: ObjetDessinable.cc SupportADessin.h ObjetIntegrable.h \
 VecteurV.h affichage.h constantes.h contrainte.h
ObjetIntegrable.o: ObjetIntegrable.cc VecteurV.h affichage.h constantes.h \
 contrainte.h ObjetIntegrable.h Champforces.h
PointMateriel.o: PointMateriel.cc VecteurV.h affichage.h constantes.h \
 ObjetIntegrable.h contrainte.h Champforces.h GravitationConstante.h \
 PointMateriel.h ObjetDessinable.h SupportADessin.h
Pomme.o: Pomme.cc VecteurV.h affichage.h ObjetIntegrable.h constantes.h \
 contrainte.h Champforces.h PointMateriel.h ObjetDessinable.h \
 SupportADessin.h
SupportADessin.o: SupportADessin.cc PointMateriel.h VecteurV.h \
 affichage.h constantes.h ObjetIntegrable.h contrainte.h \
 ObjetDessinable.h SupportADessin.h Systeme.h Integrateurs.h \
 Champforces.h
Systeme.o: Systeme.cc ObjetIntegrable.h VecteurV.h affichage.h \
 constantes.h contrainte.h SupportADessin.h Integrateurs.h \
 ObjetDessinable.h Champforces.h
VecteurTestV.o: VecteurTestV.cc VecteurV.h affichage.h
VecteurV.o: VecteurV.cc affichage.h