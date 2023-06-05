//
// Created by JoachimWagner on 05.06.2023.
//

#include "StapelTest.h"

namespace collections {

    const int expectedSize = 10;

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
    TEST_F(StapelTest, push__fill_up_to_limit__noExceptionIsThrown) {
        // Arrange + Act + Assert
        fill_up_to_limit_without_exception();

    }

    TEST_F(StapelTest, push__overflow__throwsStapelException) {
        // Arrange + Act

        EXPECT_THROW(objectUnderTest.push(1), StapelException);

    }

    TEST_F(StapelTest, push__overflow__throwsStapelException_Alternative) {

        try {
            // Arrange + Act
            fill_up_to_limit_without_exception();
            objectUnderTest.push(1);
            FAIL() << "Exception erwartet";
        } catch (const StapelException &ex) {
            EXPECT_STREQ("Overflow", ex.what());
        }


    }


    void StapelTest::fill_up_to_limit_without_exception() {
        for (int i = 0; i < expectedSize; ++i) {
            EXPECT_NO_THROW(objectUnderTest.push(1));
        }
    }
} // collections