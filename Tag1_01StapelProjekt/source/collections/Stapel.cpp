//
// Created by JoachimWagner on 05.06.2023.
//

#include "Stapel.h"
#include "StapelException.h"

collections::Stapel::Stapel():index{0} {}

bool collections::Stapel::is_empty() const {
    return index == 0;
}

bool collections::Stapel::is_full() const {
    return index == 10;
}

void collections::Stapel::push(int value) {
    if(is_full()) throw StapelException("Overflow");
    data[index++] = value;
}

int collections::Stapel::pop() {
    if (is_empty()) throw StapelException("Underflow");
    return data[--index];
}
