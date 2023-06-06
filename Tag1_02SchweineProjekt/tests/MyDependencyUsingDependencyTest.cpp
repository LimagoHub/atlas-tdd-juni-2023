//
// Created by JoachimWagner on 05.06.2023.
//

#include "MyDependencyUsingDependencyTest.h"

TEST_F(MyDependencyUsingDependencyTest, MockdemoFunc) {

    // Recordmode
    EXPECT_CALL(dependencyMock,bar())
        .WillOnce(Return(4771))
        .WillOnce(Return(4772))
        ;

    // Replaymode
    std::cout << dependencyMock.bar() << std::endl;
    std::cout << dependencyMock.bar() << std::endl;

}

TEST_F(MyDependencyUsingDependencyTest, f_Upper) {

    // Recordmode
    EXPECT_CALL(dependencyMock,foo("HALLO"));
    // Replaymode

    objectUnderTest.f("hallo");

}
TEST_F(MyDependencyUsingDependencyTest, f_Murks) {

    // Recordmode
    EXPECT_CALL(dependencyMock,foobar("Hallo Welt")).WillOnce(Return(100));
    EXPECT_CALL(dependencyMock,foobar("Hello Welt")).WillOnce(Return(2000));



    auto result = objectUnderTest.g("Hallo");
    EXPECT_THAT(result, 105);
}
TEST_F(MyDependencyUsingDependencyTest, h_demo) {

    // Recordmode
    EXPECT_CALL(dependencyMock,bar).Times(AtLeast(1)).WillRepeatedly(Return(100));

    auto result = objectUnderTest.h();
    EXPECT_THAT(result, 10000);
}