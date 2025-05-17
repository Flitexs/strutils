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
    CHECK( result == expected );
    CHECK(strtoint("-15", 4) == -15);
    CHECK(strtoint("+15", 4) == 15);
}

TEST_CASE("strtoint edge cases", "[str],[strtoint]") {
    SECTION("Empty string returns 0") {
        char input[] = "";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("String with only whitespace returns 0") {
        char input[] = "   ";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("Number with leading and trailing spaces") {
        char input[] = "  42  ";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 42 );
    }
    SECTION("Zero as string returns 0") {
        char input[] = "0";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("Negative zero returns 0") {
        char input[] = "-0";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("Leading zeros are ignored") {
        char input[] = "0000123";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 123 );
    }
    SECTION("Explicit plus sign returns positive number") {
        char input[] = "+987";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 987 );
    }
    SECTION("Conversion stops at non-digit characters") {
        char input[] = "456abc";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 456 );
    }
    SECTION("Trailing spaces after number") {
        char input[] = "789   ";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 789 );
    }
    SECTION("Partial buffer size cuts off extra characters") {
        char input[] = "12345extra";
        // Only "12345" and the null terminator are considered.
        int size = 6;
        CHECK( strtoint(input, size) == 12345 );
    }
    SECTION("INT_MAX as a string returns INT_MAX") {
        char input[] = "2147483647";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 2147483647 );
    }
    SECTION("INT_MIN as a string returns INT_MIN") {
        char input[] = "-2147483648";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == -2147483648 );
    }
    SECTION("String with only plus sign returns 0") {
        char input[] = "+";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("String with only minus sign returns 0") {
        char input[] = "-";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("Invalid starting character returns 0") {
        char input[] = "abc123";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("Spaces with leading zeros and minus sign") {
        char input[] = "   -00123";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == -123 );
    }
    SECTION("Multiple zeros return 0") {
        char input[] = "0000";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("Plus sign with zeros returns 0") {
        char input[] = "+0000";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == 0 );
    }
    SECTION("Number exceeding int range (overflow) saturates to INT_MAX") {
        char input[] = "99999999999999999999";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == INT_MAX );
    }
    SECTION("Negative number exceeding int range (underflow) saturates to INT_MIN") {
        char input[] = "-99999999999999999999";
        int size = sizeof(input);
        CHECK( strtoint(input, size) == INT_MIN );
    }
}

