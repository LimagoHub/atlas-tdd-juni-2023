//
// Created by JoachimWagner on 06.06.2023.
//

#pragma once


#include <algorithm>
#include "Multiplizierer.h"

class MultipliziererImpl: public Multiplizierer {
public:
    unsigned long long int mult(unsigned int a, unsigned int b) const override {
        auto result = 0ULL;

        for (unsigned i = 0; i < a; ++i) {
            result += b;
        }
        return result;
    }
};
