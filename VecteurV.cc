#include <iostream>
#include <vector>
#include <cmath>
#include "VecteurV.h"
#include "affichage.h"
using namespace std;

void Vecteur::affiche(ostream& out) const{
    for(int i = 0;i < vecteur.size(); i++){
        out << vecteur[i];
        if(i != vecteur.size()-1){
            out << " ";
        }
    }
    out << endl;
}

void Vecteur::whoami(ostream& out) const{
    out << "vecteur";
}

double Vecteur::get_coord(int i)const {
    return vecteur[i];
}

void Vecteur::augmente(double v){
    vecteur.push_back(v);
}

void Vecteur::set_coord(int i,double v){
    //permet de définir la coordonnée i du vecteur à v
    int dim = vecteur.size();
    if(i>dim){
        //éviter d'avoir un vecteur avec un "trou" i.e {1,2,3,NAN (ou un nombre aléatoire créé par le compilateur),4}
        i = dim;
    }
    vecteur[i] = v;
}

bool Vecteur::compare(const Vecteur& B,double precision) const{ 
    //compare 2 à 2 les coordonnées de chaque vecteur avec un certaine précision
    //si chaque coordonnée est égale à la coordonnée du vecteur B avec une précision donnée, on retourne vrai, sinon faux
    int dim = vecteur.size();
    if (dim==B.vecteur.size()){
        for (unsigned int i(0); i<dim ; i++){
            if ( abs(vecteur[i] - B.vecteur[i]) > precision ){
                return false;
            } 
        }
        return true;
    }else{
        return false;
    }
}

Vecteur Vecteur::addition(const Vecteur& X) const{
    // on fait des copies pour échanger A et B si dim(B)>Dim(A) pour faire l'addition afin d'éviter d'échanger les vecteurs instanciés pour le reste du programme
    vector <double> A = vecteur;
    vector <double> B = X.vecteur; 
    int dim_A = A.size();
    int dim_B = B.size();
    //echange les vecteur si dim(B)>Dim(A) pour eviter de faire copier coller le meme code dans un if(dim_A>=dim_B) et if(dim_A<dim_B) pour l'addition des deux vecteurs.
    if (dim_A < dim_B){ 
        vector<double> C = B;
        B = A;
        A = C;
    }
    for (int i(0); i < abs(dim_A-dim_B) ; i++){
        B.push_back(0);
    } // on complète la dimension de B en la dimension de A en lui rajoutant des 0. La copie de A et B permet aussi de ne pas modifier les vecteurs originaux
    for(int i(0); i<max(dim_A,dim_B) ;i++){
        A[i]= A[i]+B[i];
    }
    Vecteur D(A);
    return D; //je suis vrm pas sur de ces 2 dernières lignes, parce qu'il faut retourner un Vecteur sauf que je dois manipuler les vecteurs (V majuscule = classe et v minuscule = vector contenant les éléments du Vecteur)
}

Vecteur Vecteur::soustraction(const Vecteur& X) const{
    //attention si dim A < dim B on se retrouve à faire B-A plutôt que A-B à voir s'il faut changer la méthode
    return addition(X.oppose());
}

Vecteur Vecteur::oppose() const{
    //renvoie le vecteur opposé, i.e. le vecteur dont les coordonnées sont les opposées de celles du vecteur de cette classe
    int dim = vecteur.size();
    vector <double> coord_oppose = vecteur;
    for(unsigned int i(0); i<dim;i++){
        coord_oppose[i] = 0 - coord_oppose[i];
    }
    Vecteur inverse(coord_oppose);
    return inverse;
}

Vecteur Vecteur::mult(double scalaire) const{
    //multiplie chauque coordonnée du vecteur de cette classe par un scalaire donné et renvoie le vecteur résultant
    int dim = vecteur.size();
    Vecteur multiplie(vecteur);
    for(unsigned int i = 0; i < dim;i++){
        multiplie.vecteur[i] = scalaire*vecteur[i];
    }
    return multiplie;
}

double Vecteur::prod_scalaire(const Vecteur& B) const{
    //calcul le produit scalaire entre le vecteur de cette classe et le vecteur B
    Vecteur copie_B = B;
    int dim = vecteur.size();
    //création d'un vecteur temporaire pour ne pas modifier les coords du vecteur de cette classe
    vector <double> vect_temp = vecteur;
    do{
        if(dim > copie_B.vecteur.size()){
            copie_B.vecteur.push_back(0);
        }else if(dim < copie_B.vecteur.size()){ 
            vect_temp.push_back(0);
        }
    }while(dim != copie_B.vecteur.size());
    double produit(0);
    for(unsigned int i = 0; i < dim;i++){
        produit += (vect_temp[i]*copie_B.vecteur[i]);
    }
    return produit;
}

Vecteur Vecteur::prod_vect(Vecteur B) const{
    //calcul le produit vectoriel entre le vecteur de cette classe et le vecteur B
    int dim = vecteur.size();
    // si les vecteurs sont de dimension 2 ou moins on les complètes en vecteurs de dimension trois avec des 0 
    //dans les coords manquantes. Si les dimension sont > 3 ont ne prends que les 3 premières coords
    vector <double> vect_temp = vecteur;
    do{
        if(dim < 3){
            vect_temp.push_back(0);
        }else if(B.vecteur.size() < 3){
            B.vecteur.push_back(0);
        }
    }while(dim != 3 && B.vecteur.size() != 3);
    double x = (vect_temp[1]*B.vecteur[2])-(vect_temp[2]*B.vecteur[1]);
    double y = (vect_temp[2]*B.vecteur[0])-(vect_temp[0]*B.vecteur[2]);
    double z = (vect_temp[0]*B.vecteur[1])-(vect_temp[1]*B.vecteur[0]);
    Vecteur Produit(x,y,z);
    return Produit;
}

double Vecteur::norme() const{
    //calcul la norme du vecteur de cette classe
    //on utilise la méthode norme2 pour ne pas avoir à faire le calcul de la racine carrée dans cette méthode
    Vecteur B(vecteur);
    return sqrt(B.norme2());
}

double Vecteur::norme2() const{
    //calcul la norme au carré du vecteur de cette classe i.e la somme des carrés de ses coordonnées
    int dim = vecteur.size();
    double norme(0);
    for(unsigned int i = 0; i < dim;i++){
        norme += (vecteur[i]*vecteur[i]);
    }
    return norme;
}

    
Vecteur Vecteur::unitaire() const{
    //renvoie le vecteur unitaire i.e. le vecteur de cette classe divisé par sa norme
    int dim = vecteur.size();
    Vecteur A(vecteur);
    Vecteur B(dim);
    double n = A.norme();
    try{
        if (n==0){
            throw("division par zero");
        }
        for (unsigned int i(0); i<dim; i++){
            B.vecteur[i] = (vecteur[i]/n);
        }
    }
    
    catch(string txt) {cout << "Erreur :" << txt << endl;}
    return B;
}


bool Vecteur::operator==(const Vecteur& B) const{
    return this->compare(B);
}

bool Vecteur::operator!=(const Vecteur& B) const{
    return !(*this == B);
}

void Vecteur::operator+=(const Vecteur& B){
    //on augmente le vecteur B si dim B < dimA ou on les échanges si dimA<dimB pour garder les mêmes convention que pour la méthode addition
    int dim_A = vecteur.size();
    int dim_B = B.vecteur.size();
    vector<double> B_vect = B.vecteur;
    if(dim_A>dim_B){
        for(int i = 0;i<(dim_A-dim_B);i++){
            B_vect.push_back(0);
        }
    }else if(dim_B>dim_A){
        vector<double> C = vecteur;
        vecteur = B_vect;
        B_vect = C;
        for(int i = 0;i<(dim_B-dim_A);i++){
            B_vect.push_back(0);
        }
    }
    for(int i = 0;i<max(dim_A,dim_B);i++){
        vecteur[i] += B_vect[i];
    }
}

void Vecteur::operator-=(const Vecteur& B){
    Vecteur C(B.oppose());
    *this += C;
}

Vecteur Vecteur::operator^(const Vecteur& B){
    return this->prod_vect(B);
}

const Vecteur operator+(Vecteur A, const Vecteur& B){
    A += B;
    return A;
}

const Vecteur operator-(Vecteur A, const Vecteur& B){
    A-=B;
    return A;
}

void Vecteur::operator*=(double d){
    *this = this->mult(d);
}

Vecteur Vecteur::operator*(double d)const{
    return mult(d);
}

Vecteur Vecteur::operator~() const{
    return unitaire();
}