#include <iostream>
#include "MultipliziererImpl.h"
#include "MultipliziererOptimierer.h"
#include "MathClient.h"
int main() {
    MultipliziererImpl impl;
    MultipliziererOptimierer optimierer{impl};
    MathClient client{optimierer};
    client.go();

    return 0;
}
