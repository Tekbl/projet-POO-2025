#pragma once
#include <iostream>


class Printable{
    public:
        virtual void affiche(std::ostream& out) const = 0;
        virtual ~Printable() = default;
        virtual void whoami()const = 0;

};


std::ostream& operator<<(std::ostream& out, const Printable& print);