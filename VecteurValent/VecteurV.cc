#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Vecteur{

public:

    Vecteur(int dimension):dim(dimension),vecteur(dimension,0){}
    Vecteur(double x, double y, double z):vecteur{x,y,z},dim(3){}

    void affiche() const;
    void set_coord(int i,double v);
    double get_coord(int i) const;
    void augmente(double v);
    bool compare(Vecteur B, double precision=1e-10) const; //la precision est par défaut 1e-10 mais je laisse l'opportunité de la modifier
    Vecteur addition(Vecteur X) const;
    Vecteur soustraction(Vecteur X) const;
    Vecteur oppose() const;
    Vecteur mult(double scalaire) const;
    double prod_scalaire(Vecteur B) const;
    Vecteur prod_vect(Vecteur B) const;
    double norme() const;
    double norme2() const;
    Vecteur unitaire() const;

private:
    vector<double> vecteur; //on utilise un vector car on peut modifier leur taille (dimension) contrairement aux array
    unsigned int dim = 0; // on fixe n pour eviter de refaire appel à la fonction size() pour chaque opération
};

void Vecteur::affiche() const{for(auto element:vecteur){cout << element << " ";}; cout << endl;}

double Vecteur::get_coord(int i)const {return vecteur[i];}
void Vecteur::augmente(double v){
    vecteur.push_back(v);
    dim +=1;}

void Vecteur::set_coord(int i,double v){
    vecteur[i] = v;
    dim = vecteur.size();
}

bool Vecteur::compare(Vecteur B,double precision) const{ 
    if (dim==B.vecteur.size()){
        for (unsigned int i(0); i<dim ; i++){
            if ( abs(vecteur[i] - B.vecteur[i]) > precision ){return false;} }
        return true;}

    else {return false;}
}

Vecteur Vecteur::addition(Vecteur X) const{
    vector <double> A = vecteur; // on fait des copies parce que je veux echanger A et B si dim(B)>Dim(A) pour faire l'addition sauf que ça va également échanger les vecteurs instanciés pour le reste du programme
    vector <double> B = X.vecteur; 
    int dim_A = A.size();
    int dim_B = B.size();
    if (dim_A < dim_B){ //echange les vecteur si dim(B)>Dim(A) pour eviter de faire copier coller le meme code dans un if(dim_A>=dim_B) et if(dim_A<dim_B) pour l'addition des deux vecteurs.
        vector<double> C = B;
        B = A;
        A = C;
        int dim = dim_A;
        dim_A = dim_B;
        dim_B = dim_A;
    }
    for (int i(0); i < dim_A-dim_B ; i++){B.push_back(0);} // on complète la dimension de B en la dimension de A en lui rajoutant des 0. La copie de A et B permet aussi de ne pas modifier les vecteurs originaux
    for(int i(0); i<dim_A ;i++){A[i]= A[i]+B[i];}
    Vecteur D;
    D.vecteur = A;
    return D; //je suis vrm pas sur de ces 2 dernières lignes, parce qu'il faut retourner un Vecteur sauf que je dois manipuler les vecteurs (V majuscule = classe et v minuscule = vector contenant les éléments du Vecteur)
}

Vecteur Vecteur::soustraction(Vecteur X) const{
    //attention si dim A < dim B on se retrouve à faire B-A plutôt que A-B à voir s'il faut changer la méthode
    return addition(X.oppose());
}

Vecteur Vecteur::oppose() const{
    vector <double> coord_oppose = vecteur;
    for(unsigned int i(0); i<dim;i++){
        coord_oppose[i] = 0 - coord_oppose[i];
    }
    Vecteur inverse;
    inverse.vecteur = coord_oppose;
    return inverse;
}

Vecteur Vecteur::mult(double scalaire) const{
    Vecteur multiplie;
    for(unsigned int i = 0; i < dim;i++){
        multiplie.vecteur[i] = scalaire*vecteur[i];
    }
    return multiplie;
}

double Vecteur::prod_scalaire(Vecteur B) const{
    //création d'un vecteur temporaire pour ne pas modifier les coords du vecteur de cette classe
    vector <double> vect_temp = vecteur;
    do{
        if(dim > B.vecteur.size()){
            B.vecteur.push_back(0);
        }else if(dim < B.vecteur.size()){ 
            vect_temp.push_back(0);
        }
    }while(dim != B.vecteur.size());
    double produit(0);
    for(unsigned int i = 0; i < dim;i++){
        produit += (vect_temp[i]*B.vecteur[i]);
    }
    return produit;
}

Vecteur Vecteur::prod_vect(Vecteur B) const{
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
    Vecteur Produit;
    Produit.vecteur[0] = (vect_temp[2]*B.vecteur[3])-(vect_temp[3]*B.vecteur[2]);
    Produit.vecteur[1] = (vect_temp[3]*B.vecteur[1])-(vect_temp[1]*B.vecteur[3]);
    Produit.vecteur[2] = (vect_temp[1]*B.vecteur[2])-(vect_temp[2]*B.vecteur[1]);

    return Produit;
}

double Vecteur::norme() const{
    Vecteur B;
    B.vecteur = vecteur;
    return sqrt(B.norme2());
}

double Vecteur::norme2() const{
    double norme(0);
    for(unsigned int i = 0; i < dim;i++){
        norme += (vecteur[i]*vecteur[i]);
    }
    return norme;
}

    
Vecteur Vecteur::unitaire() const{
    Vecteur A;
    A.vecteur = vecteur;
    Vecteur B;
    double n = A.norme();
    try{
        if (n==0){
            throw("division par zero");
        }
        for (unsigned int i(0); i<dim; i++){
            B.augmente(vecteur[i]/n);
        }
    }
    
    catch(string txt) {cout << "Erreur :" << txt << endl;}
    return B;
}