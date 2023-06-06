//
// Created by JoachimWagner on 06.06.2023.
//

#include "personen_service_impl_test.h"

TEST_F(personen_service_impl_test, speichern__vorname_too_short__throws_personen_service_exception){
    try {
        person invalidPerson{"j", "doe"};
        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Vorname zu kurz");
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_too_short__throws_personen_service_exception){
    try {
        person invalidPerson{"john", "d"};
        object_under_test.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Nachname zu kurz");
    }
}

TEST_F(personen_service_impl_test, speichern__unerwuenschte_person__throws_personen_service_exception){
    try {
        person blacklistedPerson{"John", "Doe"};
        EXPECT_CALL(blacklistMock, is_blacklisted(blacklistedPerson)).WillOnce(Return(true));
        object_under_test.speichern(blacklistedPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Unerwuenschte Person");
    }
}

TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_blacklist_service__throws_personen_service_exception){
    try {
        person validPerson{};
        EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Throw(std::invalid_argument{"War schon!"}));

        object_under_test.speichern(validPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Fehler im Service");
        auto nested = ex.getNestedException();
        EXPECT_NE(nested, nullptr);
    }
}

TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_repo_service__throws_personen_service_exception){
    try {
        person validPerson{};
        ON_CALL(blacklistMock, is_blacklisted(_)).WillByDefault(Return(false));
        EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::out_of_range{"Upps"}));
        object_under_test.speichern(validPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), "Fehler im Service");
        auto nested = ex.getNestedException();
        EXPECT_NE(nested, nullptr);
    }
}

TEST_F(personen_service_impl_test, speichern__HappyDay__person_passed_to_repo){

        Sequence s;
        person validPerson{};
        EXPECT_CALL(blacklistMock, is_blacklisted(_)).InSequence(s).WillOnce(Return(false));
        EXPECT_CALL(repoMock, save_or_update(validPerson)).InSequence(s);

        object_under_test.speichern(validPerson);

}