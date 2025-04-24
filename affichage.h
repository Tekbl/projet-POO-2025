#pragma once
#include <iostream>


class Printable{
    public:
        virtual void affiche(std::ostream& out) const = 0;
        virtual ~Printable() = default;
};


std::ostream& operator<<(std::ostream& out, const Printable& print);