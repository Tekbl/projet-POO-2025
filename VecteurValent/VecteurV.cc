#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Vecteur{

public:

    Vecteur(unsigned int dimension):vecteur(dimension,0.0){}
    Vecteur(double x, double y, double z):vecteur{x,y,z}{}
    //initialise vecteur avec un vector de double de dimension quelconque,on le passe par référence constant pour ne pas créér de copies et ne pas faire de modifications sur le vector entré
    Vecteur(const vector<double>& liste_dinit):vecteur(liste_dinit){}
    

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
    friend ostream& operator<<(ostream& sortie,const Vecteur& v); //on met friend pour accéder aux éléments de vecteur
    bool operator==(Vecteur B) const;

private:
    vector<double> vecteur; //on utilise un vector car on peut modifier leur taille (dimension) contrairement aux array
};

void Vecteur::affiche() const{
    for(auto element:vecteur){
        cout << element << " ";
    }; cout << endl;
}

double Vecteur::get_coord(int i)const {return vecteur[i];}
void Vecteur::augmente(double v){
    vecteur.push_back(v);
    }

void Vecteur::set_coord(int i,double v){
    int dim = vecteur.size();
    if(i>dim){
        //éviter d'avoir un vecteur avec un "trou" i.e {1,2,3,NAN (ou un nombre aléatoire créé par le compilateur),4}
        i = dim;
    }
    vecteur[i] = v;
}

bool Vecteur::compare(Vecteur B,double precision) const{ 
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

Vecteur Vecteur::addition(Vecteur X) const{
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
    for (int i(0); i < abs(dim_A-dim_B) ; i++){B.push_back(0);} // on complète la dimension de B en la dimension de A en lui rajoutant des 0. La copie de A et B permet aussi de ne pas modifier les vecteurs originaux
    for(int i(0); i<max(dim_A,dim_B) ;i++){A[i]= A[i]+B[i];}
    Vecteur D(A);
    return D; //je suis vrm pas sur de ces 2 dernières lignes, parce qu'il faut retourner un Vecteur sauf que je dois manipuler les vecteurs (V majuscule = classe et v minuscule = vector contenant les éléments du Vecteur)
}

Vecteur Vecteur::soustraction(Vecteur X) const{
    //attention si dim A < dim B on se retrouve à faire B-A plutôt que A-B à voir s'il faut changer la méthode
    return addition(X.oppose());
}

Vecteur Vecteur::oppose() const{
    int dim = vecteur.size();
    vector <double> coord_oppose = vecteur;
    for(unsigned int i(0); i<dim;i++){
        coord_oppose[i] = 0 - coord_oppose[i];
    }
    Vecteur inverse(coord_oppose);
    return inverse;
}

Vecteur Vecteur::mult(double scalaire) const{
    int dim = vecteur.size();
    Vecteur multiplie(vecteur);
    for(unsigned int i = 0; i < dim;i++){
        multiplie.vecteur[i] = scalaire*vecteur[i];
    }
    return multiplie;
}

double Vecteur::prod_scalaire(Vecteur B) const{
    int dim = vecteur.size();
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
    Vecteur Produit((vect_temp[2]*B.vecteur[3])-(vect_temp[3]*B.vecteur[2]),(vect_temp[3]*B.vecteur[1])-(vect_temp[1]*B.vecteur[3]),(vect_temp[1]*B.vecteur[2])-(vect_temp[2]*B.vecteur[1]));
    return Produit;
}

double Vecteur::norme() const{
    Vecteur B(vecteur);
    return sqrt(B.norme2());
}

double Vecteur::norme2() const{
    int dim = vecteur.size();
    double norme(0);
    for(unsigned int i = 0; i < dim;i++){
        norme += (vecteur[i]*vecteur[i]);
    }
    return norme;
}

    
Vecteur Vecteur::unitaire() const{
    int dim = vecteur.size();
    Vecteur A(vecteur);
    Vecteur B(dim);
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

//on retourne un ostream& afin de pouvoir écrire cout << v1 << endl; ou cout << v1 << v2;
ostream& operator<<(ostream& sortie, const Vecteur& v){
    for(int i = 0;i < v.vecteur.size(); i++){
        sortie << v.vecteur[i] << " ";
    }
    return sortie;
}

bool Vecteur::operator==(Vecteur B) const{
    int dim = vecteur.size();
    if (dim==B.vecteur.size()){
        for (unsigned int i(0); i<dim ; i++){
            if (vecteur[i] != B.vecteur[i]){
                return false;
            } 
        }
        return true;
    }else{
        return false;
    }
}