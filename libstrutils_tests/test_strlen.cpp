#include <catch2/catch_test_macros.hpp>

#include "strutils.h"

TEST_CASE ( "strlen", "[str],[strlen]") {
    char someLeters [] = "30492363634";
    int sizeForsomeLeters = sizeof(someLeters);
    CHECK(th_strlen(someLeters, sizeForsomeLeters) == sizeof(someLeters) - 1);
}

TEST_CASE ( "strlen_unsafe", "[str],[strlen_unsafe]") {
    char someChar [] = "12345";
    CHECK (th_strlen_unsafe(someChar) == 5);
    CHECK (th_strlen_unsafe(someChar) == sizeof(someChar) - 1);
}
