//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once
#include "gmock/gmock.h"
#include "MockDependency.h"
#include "../source/MyServiceUsingDependency.h"
using namespace testing;

class MyDependencyUsingDependencyTest : public Test{
protected:
    MockDependency dependencyMock;
    MyServiceUsingDependency objectUnderTest{dependencyMock};
};
