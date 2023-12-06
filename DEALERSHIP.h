//
// Created by Matei Pop on 12/6/2023.
//

#ifndef DEALERSHIP_H
#define DEALERSHIP_H
#include <iostream>
#include <vector>
#include "MASINA.h"
#include "MASINAHIBRID.h"

using namespace std;


class Dealership {
private:
    Masina* masina;
public:
    Dealership() { this->masina = NULL; }
    Masina* getMasina() { return this->masina; }

    friend istream& operator>>(istream& in, Dealership& obj);
    friend ostream& operator<<(ostream& out, const Dealership& obj);
};

#endif // DEALERSHIP_H
