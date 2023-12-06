//
// Created by popma on 12/6/2023.
//

#include "ELECTRICA.h"

Electrica::Electrica(std::string culoare, std::string brand, int anFabricatie,
                     float volumPortbagaj, float vitezaMaxima, int nrUsi,
                     float capacitateBaterie, float putereInKw):Masina(
        culoare, brand, anFabricatie, volumPortbagaj,
        vitezaMaxima, nrUsi
) {
    this->capacitateBaterie = capacitateBaterie;
    this->putereInKw = putereInKw;
}

Electrica::Electrica(const Electrica &obj):Masina(obj) {
    this->capacitateBaterie = obj.capacitateBaterie;
    this->putereInKw = obj.putereInKw;
}

Electrica &Electrica::operator=(const Electrica &obj) {
    if (this != &obj) {
        Masina::operator=(obj);
        this->capacitateBaterie = obj.capacitateBaterie;
        this->putereInKw = obj.putereInKw;
    }

    return *this;
}

std::istream& Electrica::read(std::istream &in) {
    Masina::read(in);

    std::cout << "Introdu capacitatea bateriei: " << std::endl;
    in >> this->capacitateBaterie;

    std::cout << "Introdu puterea (kw): " << std::endl;
    in >> this->putereInKw;

    return in;
}

std::ostream& Electrica::print(std::ostream& out) const {
    Masina::print(out);

    out << "Capacitatea bateriei: " << this->capacitateBaterie << std::endl;
    out << "Putere (kw): " << this->putereInKw << std::endl;

    return out;
}

void Electrica::findRange() {
    if (this->putereInKw <= 0) {
        throw std::runtime_error("Nu se poate calcula range-ul\n");
    }

    std::cout << "Range-ul este de: " << this->capacitateBaterie/this->putereInKw << " km\n";
}

Electrica::~Electrica() {
}
