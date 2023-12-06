//
// Created by popma on 12/6/2023.
//

#ifndef UNTITLED2_OPTIUNEINVALIDA_H
#define UNTITLED2_OPTIUNEINVALIDA_H

#include <exception>

class OptiuneInvalida : public std::exception{
public:
    const char* what() const throw(){
        return "Optiune invalida!";
    }
};

#endif //UNTITLED2_OPTIUNEINVALIDA_H
