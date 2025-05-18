#include <catch2/catch_test_macros.hpp>

#include "strutils.h"

TEST_CASE ("strlen", "[str],[strlen]") {
    char someLeters [] = "30492363634";
    int sizeForsomeLeters = sizeof(someLeters);
    CHECK(th_strlen(someLeters, sizeForsomeLeters) == sizeof(someLeters) - 1);
}

TEST_CASE ("strlen_unsafe", "[str],[strlen_unsafe]") {
    char someChar [] = "12345";
    CHECK (th_strlen_unsafe(someChar) == 5);
    CHECK (th_strlen_unsafe(someChar) == sizeof(someChar) - 1);
}

TEST_CASE ("isalpha", "[str],[isalpha]") {
    char uppercase = 'A';
    for (int i = 'A'; i < 'Z'; i++) {
        uppercase += 1;
        CHECK (th_isalpha(uppercase) == true);
    }
    uppercase = 'a';
    for (int i = 'a'; i < 'z'; i++) {
        uppercase += 1;
        CHECK (th_isalpha(uppercase) == true);
    }
    uppercase = '0';
    for (int i = 0; i <= 9; i++) {
        uppercase += 1;
        CHECK (th_isalpha(uppercase) == false);
    }
}

TEST_CASE ("isdigit", "[str],[isdigit]") {
    char number = '0';
    for (int i = 0; i < 9; i++) {
        number += 1;
        CHECK (th_isdigit(number) == true);
    }
}

TEST_CASE ("isspace", "[str],[isspace]") {
    char h = ' ';
    CHECK (th_isspace(h) == true);
    for (int i = 9; i <= 13; i++) {
        h = i;
        CHECK (th_isspace(h) == true);
    }
}

TEST_CASE ("strdup", "[str],[strdup]") {
    char str [] = "12345";
    int bufferSize = sizeof(str) / sizeof(str[0]);
    char *str1 = th_strdup(str, bufferSize);
    for (int i = 0; i < bufferSize; i++) {
        CHECK (str[i] == str1[i]);
    }
}

TEST_CASE ("strndup", "[str],[strndup]") {
    char h [] = "12345";
    int bufferSize = sizeof(h) / sizeof(h[0]);
    char* h1 = th_strndup(h, 3, bufferSize);
    for (int i = 0; i < 3; i++) {
        CHECK (h[i] == h1[i]);
    }
}
