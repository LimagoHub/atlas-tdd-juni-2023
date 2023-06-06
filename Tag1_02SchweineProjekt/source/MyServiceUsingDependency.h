//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once
#include <algorithm>
#include "Dependency.h"

class MyServiceUsingDependency {
    Dependency &dependency_;

public:
    // ConstructorInjection
    explicit MyServiceUsingDependency(Dependency &dependency) : dependency_(dependency) {}

    void f(std::string value) {
        transform(value.begin(), value.end(), value.begin(), ::toupper);
        dependency_.foo(value);
    }

    size_t g(std::string value) {
        value += " Welt";
        std::cout <<
            dependency_.foobar("Hello Welt") << std::endl;
        return dependency_.foobar(value) + 5;
    }

    long h() {
        //auto value = dependency_.bar();
        return dependency_.bar() * dependency_.bar();
    }
};
