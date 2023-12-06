//
// Created by popma on 12/6/2023.
//

#ifndef UNTITLED2_MASINAHIBRID_H
#define UNTITLED2_MASINAHIBRID_H
#include "MASINAHIBRID.h"
#include "ELECTRICA.h"
#include "MASINACOMBUSTIBIL.h"

class MasinaHibrid: public MasinaCombustibil, public Electrica {
public:
    MasinaHibrid(std::string, std::string, int,
                 float, float , int ,
                 float, float,
                 float, float);
    MasinaHibrid(const MasinaHibrid&);
    MasinaHibrid& operator=(const MasinaHibrid&);

    std::istream& read(std::istream& in);
    std::ostream& print(std::ostream& out) const;

    void findRange();
    void functieMasinaHibrid1(){
        std::cout<<"Asta e o functie proprie si doar masinile de tip hibrid o pot apela\n";
    }
    int functieMasinaHibrid2(){
        return this->capacitateBaterie;
    }
    ~MasinaHibrid();
};

#endif //UNTITLED2_MASINAHIBRID_H
