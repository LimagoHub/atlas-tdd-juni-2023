//
// Created by JoachimWagner on 05.06.2023.
//

#include "SchweinTest.h"
//#include "gmock/gmock.h"
TEST_F(SchweinTest, ctor__default__correctInitializied) {
    EXPECT_EQ(objectUnderTest.getName(), "Nobody");
    EXPECT_EQ(objectUnderTest.getGewicht(), 10);
}

TEST_F(SchweinTest, ctor__overloadedWithInvalidNameElsa__throwsInvalidArgumentException) {
    try {
        const std::string invalid_name = "Elsa";
        Schwein objectUnderTest{invalid_name};
        FAIL() << "Exception expected";
    } catch (const std::invalid_argument &ex) {
        EXPECT_STREQ(ex.what(), "Name ist nicht erlaubt");
    }
}

TEST_F(SchweinTest, ctor__overloadedWithValidNamePiggy__correctInitializied) {

    const std::string valid_name = "Piggy";
    Schwein objectUnderTest{valid_name};
    EXPECT_EQ(objectUnderTest.getName(), "Piggy");
    EXPECT_EQ(objectUnderTest.getGewicht(), 10);
}

TEST_F(SchweinTest, fuettern__happyDay__weight_increased) {
    const auto expectedWeight = 11;
    objectUnderTest.fuettern();
    EXPECT_EQ(objectUnderTest.getGewicht(), expectedWeight);
    //EXPECT_THAT(objectUnderTest.getGewicht(),Not(Eq(11)));
}