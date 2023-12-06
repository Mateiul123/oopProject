//
// Created by popma on 12/6/2023.
//
#include "MASINACOMBUSTIBIL.h"
MasinaCombustibil::MasinaCombustibil(std::string culoare = "negru", std::string brand = "Necunoscut", int anFabricatie = 1990,
                                     float volumPortbagaj = 0, float vitezaMaxima = 50, int nrUsi = 3,
                                     float capacitateRezervor = 4.0, float consum = 6.5): Masina(culoare, brand, anFabricatie, volumPortbagaj, vitezaMaxima, nrUsi){
    this->capacitateRezervor = capacitateRezervor;
    this->consum = consum;
}

MasinaCombustibil::MasinaCombustibil(const MasinaCombustibil& m): Masina(m){
    this->capacitateRezervor = m.capacitateRezervor;
    this->consum = m.consum;
}

MasinaCombustibil& MasinaCombustibil::operator=(const MasinaCombustibil& m){
    if(this != &m){
        Masina::operator=(m);
        this->capacitateRezervor = m.capacitateRezervor;
        this->consum = m.consum;
    }
    return *this;
}

std::istream& MasinaCombustibil::read(std::istream &in) {
    Masina::read(in);

    std::cout << "Introdu capacitate rezervor: " << std::endl;
    in >> this->capacitateRezervor;

    std::cout << "Introdu consum: " << std::endl;
    in >> this->consum;

    return in;
}

std::ostream& MasinaCombustibil::print(std::ostream &out) const {
    Masina::print(out);

    out << "Capacitate rezervor: " << this->capacitateRezervor << std::endl;
    out << "Consum: " << this->consum << std::endl;

    return out;
}

void MasinaCombustibil::findRange(){
    if(this->consum <= 0)
        throw std::runtime_error("Nu se poate calcula range-ul\n");
    else
        std::cout<<"Range-ul este: "<<this->capacitateRezervor/this->consum * 100<<" km\n";
}

MasinaCombustibil::~MasinaCombustibil(){}
