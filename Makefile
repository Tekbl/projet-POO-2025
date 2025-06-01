CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall


#all = mettre tout les fichiers cibles qu'on veut compiler / executer
all: VecteurTestV exerciceP11-magnetique exerciceP9 Pomme exerciceP9-LeCorbeauEtLeRenard testIntegrateur1 gnuplot_test testIntegrateur2 exerciceP11-spherique testPointMateriel


VecteurTestV : VecteurV.o affichage.o

exerciceP9: exerciceP9.o VecteurV.o ChampForces.o ForceCentrale.o Systeme.o PointMateriel.o ObjetDessinable.o \
        ObjetIntegrable.o contrainte.o Integrateurs.o constantes.o GravitationConstante.o \
        SupportADessin.o affichage.o ##Remplir ça avec les dépendances (#include "fichier.h" --> fichier.o) de exercice P9

Pomme : Pomme.o VecteurV.o ObjetIntegrable.o contrainte.o constantes.o ChampForces.o affichage.o \
        PointMateriel.o Integrateurs.o GravitationConstante.o ForceCentrale.o ##Remplir ça avec les dépendances (#include "fichier.h" --> fichier.o) de Pomme

exerciceP9-LeCorbeauEtLeRenard: exerciceP9-LeCorbeauEtLeRenard.o VecteurV.o ChampForces.o \
        GravitationConstante.o Systeme.o PointMateriel.o ObjetDessinable.o \
        ObjetIntegrable.o contrainte.o Integrateurs.o constantes.o \
        SupportADessin.o affichage.o ##Remplir ça avec les dépendances (#include "fichier.h" --> fichier.o) de exercice P9 le corbeau et le renard


exerciceP11-magnetique : VecteurV.o affichage.o ObjetIntegrable.o ChampForces.o ForceCentrale.o Integrateurs.o Systeme.o PointMateriel.o \
                        SupportADessin.o ObjetDessinable.o ChampSupplementaires.o contrainte.o ##Remplir ça avec les dépendances (#include "fichier.h" --> fichier.o) de exercice P11 magnétique


testIntegrateur1 : testIntegrateur1.o VecteurV.o ObjetIntegrable.o contrainte.o constantes.o ChampForces.o affichage.o \
        PointMateriel.o Integrateurs.o GravitationConstante.o ##Remplir ça avec les dépendances (#include "fichier.h" --> fichier.o) de testIntegrateur1

gnuplot_test : VecteurV.o ObjetIntegrable.o constantes.o contrainte.o ChampForces.o affichage.o PointMateriel.o GravitationConstante.o Integrateurs.o
                        ##Remplir ça avec les dépendances (#include "fichier.h" --> fichier.o) de gnuplot_test

testIntegrateur2 : VecteurV.o ObjetIntegrable.o constantes.o contrainte.o ChampForces.o affichage.o PointMateriel.o GravitationConstante.o Integrateurs.o
                        ##Remplir ça avec les dépendances (#include "fichier.h" --> fichier.o) de testIntegrateur2

exerciceP11-spherique: VecteurV.o ChampForces.o ObjetIntegrable.o GravitationConstante.o ContrainteSpherique.o Systeme.o PointMateriel.o SupportADessin.o \
        Integrateurs.o ObjetDessinable.o constantes.o affichage.o
                        ##Remplir ça avec les dépendances (#include "fichier.h" --> fichier.o) de exercice P11 spherique

testPointMateriel : VecteurV.o ObjetIntegrable.o constantes.o contrainte.o ChampForces.o affichage.o PointMateriel.o GravitationConstante.o

# \/ Ces lignes ont été recopiées de la commande g++ -MM *.cc \/ 
# ce sont les dépendances de compilation de chaque fichier .o mentionnés ci dessus

affichage.o: affichage.cc affichage.h
ChampForces.o: ChampForces.cc ChampForces.h VecteurV.h affichage.h \
 ObjetIntegrable.h constantes.h contrainte.h
ChampSupplementaires.o: ChampSupplementaires.cc VecteurV.h affichage.h \
 ChampForces.h ObjetIntegrable.h constantes.h contrainte.h \
 PointMateriel.h ObjetDessinable.h SupportADessin.h ForceCentrale.h \
 ChampSupplementaires.h
constantes.o: constantes.cc VecteurV.h affichage.h
contenu.o: contenu.cc ObjetDessinable.h SupportADessin.h \
 ObjetIntegrable.h VecteurV.h affichage.h constantes.h contrainte.h \
 contenu.h
contrainte.o: contrainte.cc VecteurV.h affichage.h ObjetIntegrable.h \
 constantes.h contrainte.h
ContrainteSpherique.o: ContrainteSpherique.cc contrainte.h VecteurV.h \
 affichage.h ContrainteSpherique.h ObjetIntegrable.h constantes.h
exerciceP11-magnetique.o: exerciceP11-magnetique.cc VecteurV.h \
 affichage.h ChampForces.h ObjetIntegrable.h constantes.h contrainte.h \
 ForceCentrale.h Integrateurs.h Systeme.h ObjetDessinable.h \
 SupportADessin.h PointMateriel.h ChampSupplementaires.h
exerciceP11-spherique.o: exerciceP11-spherique.cc VecteurV.h affichage.h \
 ChampForces.h ObjetIntegrable.h constantes.h contrainte.h \
 GravitationConstante.h ContrainteSpherique.h Systeme.h Integrateurs.h \
 ObjetDessinable.h SupportADessin.h PointMateriel.h
exerciceP9-LeCorbeauEtLeRenard.o: exerciceP9-LeCorbeauEtLeRenard.cc \
 VecteurV.h affichage.h ChampForces.h GravitationConstante.h constantes.h \
 ObjetIntegrable.h contrainte.h Systeme.h Integrateurs.h \
 ObjetDessinable.h SupportADessin.h PointMateriel.h
exerciceP9.o: exerciceP9.cc VecteurV.h affichage.h ChampForces.h \
 ForceCentrale.h constantes.h ObjetIntegrable.h contrainte.h Systeme.h \
 Integrateurs.h ObjetDessinable.h SupportADessin.h PointMateriel.h
ForceCentrale.o: ForceCentrale.cc ChampForces.h VecteurV.h affichage.h \
 constantes.h ObjetIntegrable.h contrainte.h ForceCentrale.h
gnuplot_test.o: gnuplot_test.cc VecteurV.h affichage.h ObjetIntegrable.h \
 constantes.h contrainte.h ChampForces.h PointMateriel.h \
 ObjetDessinable.h SupportADessin.h GravitationConstante.h Integrateurs.h
GravitationConstante.o: GravitationConstante.cc GravitationConstante.h \
 VecteurV.h affichage.h constantes.h ObjetIntegrable.h contrainte.h \
 ChampForces.h
Integrateurs.o: Integrateurs.cc Integrateurs.h VecteurV.h affichage.h \
 ObjetIntegrable.h constantes.h contrainte.h
ObjetDessinable.o: ObjetDessinable.cc ObjetDessinable.h SupportADessin.h \
 ObjetIntegrable.h VecteurV.h affichage.h constantes.h contrainte.h
ObjetIntegrable.o: ObjetIntegrable.cc ObjetIntegrable.h VecteurV.h \
 affichage.h constantes.h contrainte.h ChampForces.h
PointMateriel.o: PointMateriel.cc VecteurV.h affichage.h constantes.h \
 ObjetIntegrable.h contrainte.h ChampForces.h GravitationConstante.h \
 ObjetDessinable.h SupportADessin.h PointMateriel.h
Pomme.o: Pomme.cc VecteurV.h affichage.h ObjetIntegrable.h constantes.h \
 contrainte.h ChampForces.h PointMateriel.h ObjetDessinable.h \
 SupportADessin.h GravitationConstante.h Integrateurs.h ForceCentrale.h
SupportADessin.o: SupportADessin.cc SupportADessin.h ObjetIntegrable.h \
 VecteurV.h affichage.h constantes.h contrainte.h PointMateriel.h \
 ObjetDessinable.h Systeme.h Integrateurs.h ChampForces.h
Systeme.o: Systeme.cc Systeme.h ObjetIntegrable.h VecteurV.h affichage.h \
 constantes.h contrainte.h Integrateurs.h ObjetDessinable.h \
 SupportADessin.h ChampForces.h
testIntegrateur1.o: testIntegrateur1.cc VecteurV.h affichage.h \
 ObjetIntegrable.h constantes.h contrainte.h ChampForces.h \
 PointMateriel.h ObjetDessinable.h SupportADessin.h \
 GravitationConstante.h Integrateurs.h
testIntegrateur2.o: testIntegrateur2.cc VecteurV.h affichage.h \
 ObjetIntegrable.h constantes.h contrainte.h ChampForces.h \
 PointMateriel.h ObjetDessinable.h SupportADessin.h \
 GravitationConstante.h Integrateurs.h
testPointMateriel.o: testPointMateriel.cc VecteurV.h affichage.h \
 ObjetIntegrable.h constantes.h contrainte.h ChampForces.h \
 PointMateriel.h ObjetDessinable.h SupportADessin.h \
 GravitationConstante.h
VecteurTestV.o: VecteurTestV.cc VecteurV.h affichage.h
VecteurV.o: VecteurV.cc VecteurV.h affichage.h