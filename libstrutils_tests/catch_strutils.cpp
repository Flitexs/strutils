#include <catch2/catch_test_macros.hpp>

#include "strutils.h"

TEST_CASE( "strtoint", "[str],[strtoint]" ) {
    char input[] = "12345"; // " 12345'\0' " 6 bait
    int bufferSize = sizeof(input) / sizeof(input[0]);
    /*
    Explanation:
    sizeof (input) gives the total size of the array in bytes.
    sizeof (input[0]) gives the size of a single character in bytes.
    So, sizeof(input) / sizeof(input[0]) gives the number of characters in the array.
    In this case, the size of the array is 6 bytes (5 characters + 1 null terminator),
    and the size of a single character is 1 byte.
    Therefore, the bufferSize is 6.
    */
    int expected = 12345;
    int result = strtoint(input, bufferSize);
    REQUIRE( result == expected );
}