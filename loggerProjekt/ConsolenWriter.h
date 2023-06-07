//
// Created by JoachimWagner on 06.06.2023.
//

#pragma once


#include <iostream>
#include "Writer.h"

class ConsolenWriter: public Writer {
public:
    void write(std::string message) const override {
        std::cout << message << std::endl;
    }
};
