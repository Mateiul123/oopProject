//
// Created by popma on 12/6/2023.
//

#ifndef UNTITLED2_MASINACOMBUSTIBIL_H
#define UNTITLED2_MASINACOMBUSTIBIL_H
#include "MASINA.h"


class MasinaCombustibil: virtual public Masina{
protected:
    float capacitateRezervor;
    float consum;

public:

    MasinaCombustibil(std::string, std::string, int, float, float, int, float, float);
    MasinaCombustibil(const MasinaCombustibil&);
    MasinaCombustibil& operator=(const MasinaCombustibil& m);

    std::istream& read(std::istream& in);
    std::ostream& print(std::ostream& out) const;

    void findRange();

    virtual ~MasinaCombustibil();
};


#endif //UNTITLED2_MASINACOMBUSTIBIL_H
