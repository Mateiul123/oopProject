//
// Created by popma on 12/6/2023.
//

#ifndef UNTITLED2_ELECTRICA_H
#define UNTITLED2_ELECTRICA_H
#include "MASINA.h"
#include <iostream>
#include <string>

class Electrica: virtual public Masina {
protected:
    float capacitateBaterie,putereInKw;
public:
    Electrica(std::string culoare = "negru", std::string brand = "Volkswagen", int anFabricatie = 2000,float volumPortbagaj = 0, float vitezaMaxima = 100, int nrUsi = 3, float capacitateBaterie = 0, float putereInKw = 0);
    Electrica(const Electrica& obj);
    Electrica &operator=(const Electrica &obj);
    virtual ~Electrica();

    std::istream& read(std::istream& in);
    std::ostream& print(std::ostream& out) const;

    void findRange();
};


#endif //UNTITLED2_ELECTRICA_H
