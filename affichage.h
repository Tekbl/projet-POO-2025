#pragma once
#include <iostream>


class Printable{
    public:
        virtual void affiche(std::ostream& out) const = 0;
        virtual ~Printable() = default;
        virtual void whoami(std::ostream& out)const = 0;

};

//surcharge de l'opérateur << pour afficher les objets de type Printable
std::ostream& operator<<(std::ostream& out, const Printable& print);