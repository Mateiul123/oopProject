//
// Created by popma on 12/6/2023.
//

#ifndef UNTITLED2_MASINA_H
#define UNTITLED2_MASINA_H
#include_next <string>
#include <iostream>
#include "VEHICUL.h"


class Masina:public Vehicul {
protected:
    float volumPortbagaj, vitezaMaxima;
    int nrUsi;

public:

    Masina(std::string culoare = "negru", std::string brand = "Necunoscut", int anFabricatie = 1990,
           float volumPortbagaj = 0, float vitezaMaxima = 50, int nrUsi = 3):Vehicul(culoare,brand,anFabricatie) {
        // si dupa ce construim partea legata de vehicul, in constructorul masina construim si datele noi
        this->volumPortbagaj = volumPortbagaj;
        this->vitezaMaxima = vitezaMaxima;
        this->nrUsi = nrUsi;
    }

    Masina(const Masina& obj):Vehicul(obj) {
        this->volumPortbagaj = obj.volumPortbagaj;
        this->vitezaMaxima = obj.vitezaMaxima;
        this->nrUsi = obj.nrUsi;
    }


    Masina &operator=(const Masina& obj) {
        if (this != &obj) {
            Vehicul::operator=(obj);
            this->volumPortbagaj = obj.volumPortbagaj;
            this->vitezaMaxima = obj.vitezaMaxima;
            this->nrUsi = obj.nrUsi;
        }

        return *this;
    }

    std::istream& read(std::istream& in);
    std::ostream& print(std::ostream& out) const;


    virtual void findRange()  = 0;
    virtual ~Masina(){};
};

#endif //UNTITLED2_MASINA_H
