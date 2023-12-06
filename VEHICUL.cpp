//
// Created by popma on 12/6/2023.
//

#include "VEHICUL.h"
#include "IOINTERFACE.h"

Vehicul::Vehicul(std::string culoare, std::string brand, int anFabricatie):id(contorID++) {
    this->culoare = culoare;
    this->brand = brand;
    this->anFabricatie = anFabricatie;
}

Vehicul::~Vehicul() {
    if (!this->culoare.empty()) this->culoare.clear();
    if (!this->brand.empty()) this->brand.clear();
}

Vehicul::Vehicul(const Vehicul &obj):id(contorID++) {
    this->culoare = obj.culoare;
    this->brand = obj.brand;
    this->anFabricatie = obj.anFabricatie;
}

Vehicul &Vehicul::operator=(const Vehicul &obj) {
    if (this != &obj) {
        this->culoare = obj.culoare;
        this->brand = obj.brand;
        this->anFabricatie = obj.anFabricatie;
    }

    return *this;
}

std::istream& Vehicul::read(std::istream &in) {
    std::cout << "Introdu culoare: " << std::endl;
    in >> this->culoare;

    std::cout << "Introdu nume brand: " << std::endl;
    in >> this->brand;

    while (true) {
        std::cout << "Introdu an fabricatie: " << std::endl;
        in >> this->anFabricatie;

        if (in.fail()) {
            std::cout<<"INVALID! Introduceti un numar!\n";
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    while (true) {
        try {
            std::cout << "Introdu an fabricatie: " << std::endl;
            in >> this->anFabricatie;

            if (in.fail()) {
                throw std::runtime_error("INVALID! Introduceti un numar!\n");
            } else {
                break;  // daca s a citit input valid break the loop
            }
        } catch (const std::runtime_error& e) {
            std::cout << e.what();
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return in;
}

std::istream &operator>>(std::istream& in, Vehicul& obj) {
    return obj.read(in);
}

std::ostream& Vehicul::print(std::ostream &out) const {
    out << "\t Vehicul cu id: " << this->id <<std::endl;
    out << "Culoare: " << this->culoare <<std::endl;
    out << "Brand " << this->brand << std::endl;
    out << "An Fabricatie: " << this->anFabricatie << std::endl;

    return out;
}

std::ostream &operator<<(std::ostream& out, const Vehicul& obj) {
    return obj.print(out);
}

