//
// Created by popma on 12/6/2023.
//

#ifndef UNTITLED2_IOINTERFACE_H
#define UNTITLED2_IOINTERFACE_H
#include_next <iostream>

class IOInterface {
public:
    virtual std::istream& read(std::istream& in) = 0;
    virtual std::ostream& print(std::ostream& out) const = 0;
};

#endif //UNTITLED2_IOINTERFACE_H
