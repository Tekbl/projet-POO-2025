#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Vecteur{

public:
    void affiche();
    void set_coord(int i,double v);
    double get_coord(int i);
    void augmente(double v);
    bool compare(Vecteur B, int precision=1e-10);


private:
    vector<double> vecteur; //on utilise un vector car on peut modifier leur taille (dimension) contrairement aux array
    void affiche() const{for(auto element:vecteur){cout << element << " ";}; cout << endl;}
    void set_coord(int i,double v){vecteur[i] = v;}
    double get_coord(int i){return vecteur[i];}
    void augmente(double v){vecteur.push_back(v);}
    int dim = vecteur.size(); // on fixe n pour eviter de refaire appel à la fonction size() pour chaque opération

    bool compare(Vecteur B,int precision=1e-10){ //la precision est par défaut 1e-10 mais je laisse l'opportunité de la modifier
        if (dim==B.vecteur.size()){
            for (int i(0); i<=dim ; i++){

                if ( abs(vecteur[i] - B.vecteur[i]) > precision ){return false;} 
                else {return true;}}}

        else {return false;}
    }

    Vecteur addition(Vecteur X) const{
        vector <double> A = vecteur; // on fait des copies parce que je veux echanger A et B si dim(B)>Dim(A) pour faire l'addition sauf que ça va également échanger les vecteurs instanciés pour le reste du programme
        vector <double> B = X.vecteur; 
        int dim_A = A.size();
        int dim_B = B.size();
        if (dim_A < dim_B){ //echange les vecteur si dim(B)>Dim(A) pour eviter de faire copier coller le meme code dans un if(dim_A>=dim_B) et if(dim_A<dim_B) pour l'addition des deux vecteurs.
            vector<double> C = B;
            B = A;
            A = C;
        }
        for (int i(0); i <= dim_A-dim_B ; i++){B.push_back(0);} // on complète la dimension de B en la dimension de A en lui rajoutant des 0. La copie de A et B permet aussi de ne pas modifier les vecteurs originaux
        for(int i(0); i<=dim_A ;i++){A[i]= A[i]+B[i];}
        Vecteur D;
        D.vecteur = A;
        return D; //je suis vrm pas sur de ces 2 dernières lignes, parce qu'il faut retourner un Vecteur sauf que je dois manipuler les vecteurs (V majuscule = classe et v minuscule = vector contenant les éléments du Vecteur)
    }

    Vecteur soustraction(Vecteur X) const{
        //attention si dim A < dim B on se retrouve à faire B-A plutôt que A-B à voir s'il faut changer la méthode
        return addition(X.oppose());
    }

    Vecteur oppose() const{
        vector <double> coord_oppose = vecteur;
        for(int i(0); i<=dim;i++){
            coord_oppose[i] = 0 - coord_oppose[i];
        }
        Vecteur inverse;
        inverse.vecteur = coord_oppose;
        return inverse;
    }

    Vecteur mult(double scalaire) const{
        Vecteur multiplie;
        for(int i = 0; i <= dim;i++){
            multiplie.vecteur[i] = vecteur[i];
        }
        return multiplie;
    }


};