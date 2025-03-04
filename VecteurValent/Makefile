CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall         # pour les pur(e)s et dur(e)s
# CXXFLAGS += -g                    # pour debugger
# CXXFLAGS += -O2                   # pour optimiser la vitesse

all: testVecteur

Vecteur.o: Vecteur.cc Vecteur.h

testVecteur.o: testVecteur.cc Vecteur.h

testVecteur: testVecteur.o Vecteur.o