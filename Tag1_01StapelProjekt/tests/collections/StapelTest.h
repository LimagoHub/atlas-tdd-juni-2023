//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once
#include "gtest/gtest.h"
#include "../../source/collections/Stapel.h"
#include "../../source/collections/StapelException.h"
using namespace testing;

namespace collections {

    class StapelTest: public Test {
    protected:
        Stapel objectUnderTest;

        void fill_up_to_limit_without_exception();
    };



} // collections
