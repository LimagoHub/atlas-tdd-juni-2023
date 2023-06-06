//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once

#include "Dependency.h"
class DemoDepenency: public Dependency{
public:
    void foo(std::string message) const override {

    }

    int bar() const override {
        return 0;
    }

    size_t foobar(std::string message) const override {
        return 0;
    }
};
