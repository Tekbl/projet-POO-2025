CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall


#all = la première cible
all: TestPomme

calculCplx: calculCplx.o ##fill stuff with dependencies

# Ces lignes ont été recopiées de la commande g++ -MM *.cc

affichage.o: affichage.cc
ChampForces.o: ChampForces.cc VecteurV.h affichage.h ObjetIntegrable.h constantes.h contrainte.h Champforces.h
constantes.o: constantes.cc VecteurV.h affichage.h
contenu.o: contenu.cc ObjetDessinable.h SupportADessin.h PointMateriel.h VecteurV.h affichage.h constantes.h ObjetIntegrable.h contrainte.h Champforces.h Systeme.h Integrateurs.h
contrainte.o: contrainte.cc VecteurV.h affichage.h ObjetIntegrable.h constantes.h contrainte.h Champforces.h
exerciceP9.o: exerciceP9.cc Systeme.h ObjetIntegrable.h VecteurV.h affichage.h constantes.h contrainte.h Champforces.h Integrateurs.h PointMateriel.h ObjetDessinable.h SupportADessin.h
GravitationConstante.o: GravitationConstante.cc constantes.h VecteurV.h affichage.h PointMateriel.h ObjetIntegrable.h contrainte.h Champforces.h ObjetDessinable.h SupportADessin.h Systeme.h Integrateurs.h
Integrateurs.o: Integrateurs.cc VecteurV.h affichage.h ObjetIntegrable.h constantes.h contrainte.h Champforces.h
ObjetDessinable.o: ObjetDessinable.cc SupportADessin.h PointMateriel.h VecteurV.h affichage.h constantes.h ObjetIntegrable.h contrainte.h Champforces.h ObjetDessinable.h Systeme.h Integrateurs.h
ObjetIntegrable.o: ObjetIntegrable.cc VecteurV.h affichage.h constantes.h contrainte.h ObjetIntegrable.h Champforces.h
PointMateriel.o: PointMateriel.cc VecteurV.h affichage.h constantes.h ObjetIntegrable.h contrainte.h Champforces.h GravitationConstante.h PointMateriel.h ObjetDessinable.h SupportADessin.h Systeme.h Integrateurs.h
Pomme.o: Pomme.cc VecteurV.h affichage.h ObjetIntegrable.h constantes.h contrainte.h Champforces.h PointMateriel.h ObjetDessinable.h SupportADessin.h Systeme.h Integrateurs.h
SupportADessin.o: SupportADessin.cc PointMateriel.h VecteurV.h affichage.h constantes.h ObjetIntegrable.h contrainte.h Champforces.h ObjetDessinable.h SupportADessin.h Systeme.h Integrateurs.h
Systeme.o: Systeme.cc ObjetIntegrable.h VecteurV.h affichage.h constantes.h contrainte.h Champforces.h Integrateurs.h
VecteurTestV.o: VecteurTestV.cc VecteurV.h affichage.h
VecteurV.o: VecteurV.cc affichage.h