//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once
#include <string>

class Dependency {
public:
    Dependency() = default;
    ~Dependency() = default;

    virtual void foo(std::string message )const  = 0;
    virtual int bar( )const  = 0;
    virtual size_t foobar(std::string message )const  = 0;
};
