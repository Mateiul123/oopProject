//
// Created by popma on 12/6/2023.
//

#include "MASINAHIBRID.h"
MasinaHibrid::MasinaHibrid(std::string culoare = "rosu", std::string brand = "ford", int anFabricatie = 2019,
                           float volumPortbagaj = 100, float vitezaMaxima = 200, int nrUsi = 4,
                           float capacitateRezervor = 4.0, float consum = 6.5,
                           float capacitateBaterie = 500, float putereInKw = 10):Masina(culoare, brand, anFabricatie, volumPortbagaj, vitezaMaxima, nrUsi), MasinaCombustibil(culoare, brand, anFabricatie, volumPortbagaj, vitezaMaxima, nrUsi, capacitateRezervor, consum),
                                                                                 Electrica(culoare, brand, anFabricatie, volumPortbagaj, vitezaMaxima, nrUsi, capacitateBaterie, putereInKw)
{}

MasinaHibrid::MasinaHibrid(const MasinaHibrid& mh):MasinaCombustibil(mh), Electrica(mh){

}

MasinaHibrid& MasinaHibrid::operator=(const MasinaHibrid& mh){
    if (this != &mh){
        MasinaCombustibil::operator=(mh);
        Electrica::operator=(mh);
    }
    return *this;
}

MasinaHibrid::~MasinaHibrid(){

}

std::istream& MasinaHibrid::read(std::istream &in) {
    MasinaCombustibil::read(in);

    std::cout << "Introdu capacitatea bateriei: " << std::endl;
    in >> this->capacitateBaterie;

    std::cout << "Introdu puterea (kw): " << std::endl;
    in >> this->putereInKw;

    return in;
}

std::ostream& MasinaHibrid::print(std::ostream& out) const {
    MasinaCombustibil::print(out);

    out << "Capacitatea bateriei: " << this->capacitateBaterie<<std::endl;
    out << "Putere: " << this->putereInKw<<std::endl;

    return out;
}

void MasinaHibrid::findRange(){
    std::cout<<"Range-ul masinii hibrid este:\n";
    if(this->consum < 0 && this->putereInKw < 0)
        throw std::runtime_error("Nu se poate calcula range-ul masinii cu indexul " + std::to_string(this->getID()) + "\n");

    if(this->consum){
        std::cout<<"Daca propulsia masinii este pe combustibil: ";
        MasinaCombustibil::findRange();
    }
    else if(this->putereInKw){
        std::cout<<"Daca propulsia masinii este pe baterie: ";
        Electrica::findRange();
        throw std::runtime_error("Nu se poate calcula range-ul masinii (combustibil)\n");

    }
    if(this->putereInKw){
        std::cout<<"Daca propulsia masinii este pe baterie: ";
        Electrica::findRange();
    }else if(this->consum){
        std::cout<<"Daca propulsia masinii este pe combustibil: ";
        MasinaCombustibil::findRange();
        throw std::runtime_error("Nu se poate calcula range-ul masinii (electrica)\n");
    }
}