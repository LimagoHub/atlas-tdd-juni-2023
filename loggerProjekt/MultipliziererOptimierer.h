//
// Created by JoachimWagner on 06.06.2023.
//

#pragma once


#include "Multiplizierer.h"

class MultipliziererOptimierer: public  Multiplizierer{

    Multiplizierer &multiplizier;
public:
    explicit MultipliziererOptimierer(Multiplizierer &multiplizier) : multiplizier(multiplizier) {}

    unsigned long long int mult(unsigned int a, unsigned int b) const override {
        if(a > b)
            return multiplizier.mult(b,a);
        return multiplizier.mult(a,b);
    }
};
