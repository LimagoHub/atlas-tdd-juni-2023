//
// Created by JoachimWagner on 06.06.2023.
//

#pragma once

#include <iostream>
#include "Multiplizierer.h"

class MathClient {
    Multiplizierer &multiplizierer;
public:
    explicit MathClient(Multiplizierer &multiplizierer) : multiplizierer(multiplizierer) {}

    void go() {
        std::cout << multiplizierer.mult(3,2) << std::endl;
    }
};
