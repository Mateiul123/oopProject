//
// Created by popma on 12/6/2023.
//

#include "MASINA.h"

std::istream& Masina::read(std::istream &in) {
    Vehicul::read(in);

    std::cout << "Introdu volum portbagaj: " << std::endl;
    in >> this->volumPortbagaj;

    std::cout << "Introdu viteza maxima: " << std::endl;
    in >> this->vitezaMaxima;

    std::cout << "Introdu numarul de usi: " << std::endl;
    in >> this->nrUsi;

    return in;
}

std::ostream& Masina::print(std::ostream &out) const {
    Vehicul::print(out);

    out << "Volum Portbagaj: " << this->volumPortbagaj << std::endl;
    out << "Viteza Maxima " << this->vitezaMaxima << std::endl;
    out << "Numarul de usi: " << this->nrUsi << std::endl;

    return out;
}
