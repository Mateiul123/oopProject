//
// Created by popma on 12/6/2023.
//

#ifndef UNTITLED2_MENIU_H
#define UNTITLED2_MENIU_H

#include "OPTIUNEINVALIDA.h"
#include "DEALERSHIP.h"
#include "MASINAHIBRID.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <typeinfo>

class Meniu {
private:
    vector<Dealership*> masini;
    Meniu() { }
    ~Meniu() {
        for (int i=0; i<masini.size(); i++) {
            if (masini[i] != NULL)
                delete masini[i];
        }

        masini.clear();
    }
public:
    Meniu(Meniu const&) = delete;
    void operator=(Meniu const&) = delete;

    static Meniu& getInstance() {
        static Meniu instance;
        return instance;
    }

    bool verificaIndex(int index) const;
    void afiseazaMeniu() const;
    void startMeniu();
};

#endif //UNTITLED2_MENIU_H
