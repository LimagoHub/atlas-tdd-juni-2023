//
// Created by JoachimWagner on 05.06.2023.
//

#include "StapelTest.h"

TEST_F(StapelTest, t1) {
    bool result = objectUnderTest.is_empty();
    EXPECT_TRUE(result);
}

TEST_F(StapelTest, t2) {
    objectUnderTest.push(1);
    bool result = objectUnderTest.is_empty();
    EXPECT_FALSE(result);
}