//
// Created by JoachimWagner on 05.06.2023.
//

#include "StapelTest.h"

namespace collections {
    TEST_F(StapelTest, is_empty__empty_stack__returnsTrue) {
        // Arrange

        // Act
        auto result = objectUnderTest.is_empty();

        // Assert
        EXPECT_TRUE(result);
    }
    TEST_F(StapelTest, is_empty__not_empty_stack__returnsFalse) {
        // Arrange

        objectUnderTest.push(1);

        // Act
        auto result = objectUnderTest.is_empty();

        // Assert
        EXPECT_FALSE(result);
    }



} // collections