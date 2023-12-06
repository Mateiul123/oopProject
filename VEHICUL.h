//
// Created by popma on 12/6/2023.
//

#ifndef VEHICUL_H
#define VEHICUL_H

#include "IOINTERFACE.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <typeinfo>

    class Vehicul : public IOInterface {
    protected:
        std::string culoare, brand;
        int anFabricatie;
        const int id;
        static int contorID;

    public:
        Vehicul(std::string culoare = "negru", std::string brand = "Necunoscut", int anFabricatie = 1990);
        Vehicul(const Vehicul& obj);
        virtual ~Vehicul();
        Vehicul &operator=(const Vehicul& obj);

        std::istream& read(std::istream& in);
        std::ostream& print(std::ostream& out) const;

        friend std::istream &operator>>(std::istream& in, Vehicul& obj);
        friend std::ostream &operator<<(std::ostream& out, const Vehicul& obj);

        static int getContorID() {
            return contorID;
        }

        std::string getBrand() const {return this->brand;}
        virtual int getID() const { return this->id;}
    };
#endif // VEHICUL_H
