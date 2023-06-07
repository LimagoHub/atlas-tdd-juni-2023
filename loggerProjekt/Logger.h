//
// Created by JoachimWagner on 06.06.2023.
//

#pragma once
#include <string>
#include <iostream>
#include "Writer.h"

class Logger {

    Writer & writer;
public:
    explicit Logger(Writer &writer) : writer(writer) {}

public:
    void log(std::string message) {
        const std::string prefix = "Komplizierter Prefix: ";
        writer.write(prefix + message);
    }

};
