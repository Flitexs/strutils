#include <catch2/catch_test_macros.hpp>

#include "strutils.h"

TEST_CASE ("strlen", "[str],[strlen]") {
    char someLeters [] = "30492363634";
    int sizeForsomeLeters = sizeof(someLeters);
    CHECK(th_strlen(someLeters, sizeForsomeLeters) == sizeof(someLeters) - 1);
    // Test with an empty string
    char empty[] = "";
    int emptySize = sizeof(empty);
    CHECK(th_strlen(empty, emptySize) == 0);

    // Test with a string that contains an embedded null character
    // Only characters before the first null should be counted.
    char embeddedNull[] = {'a', 'b', 'c', '\0', 'd', 'e', 'f'};
    int embeddedSize = sizeof(embeddedNull);
    CHECK(th_strlen(embeddedNull, embeddedSize) == 3);

    // Test when the provided buffer size is zero (should safely return 0)
    char hello[] = "hello";
    CHECK(th_strlen(hello, 0) == 0);
}

TEST_CASE ("strlen_unsafe", "[str],[strlen_unsafe]") {
    char someChar [] = "12345";
    CHECK (th_strlen_unsafe(someChar) == 5);
    CHECK (th_strlen_unsafe(someChar) == sizeof(someChar) - 1);
    // Test with an empty string
    char empty[] = "";
    CHECK(th_strlen_unsafe(empty) == 0);

    // Test with a string that contains an embedded null character.
    // Only characters before the first null should be counted.
    char embeddedNull[] = {'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0'};
    CHECK(th_strlen_unsafe(embeddedNull) == 3);
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
    const char nonDigits[] = " abcXYZ!@#";
    for (char c : nonDigits) {
        CHECK(th_isdigit(c) == false);
    }
}

TEST_CASE ("isspace", "[str],[isspace]") {
    char h = ' ';
    CHECK (th_isspace(h) == true);
    for (int i = 9; i <= 13; i++) {
        h = i;
        CHECK (th_isspace(h) == true);
    }
    CHECK(th_isspace('A') == false);
    CHECK(th_isspace('1') == false);
}

TEST_CASE ("strdup", "[str],[strdup]") {
    char str [] = "12345";
    int bufferSize = sizeof(str) / sizeof(str[0]);
    char *str1 = th_strdup(str, bufferSize);
    for (int i = 0; i < bufferSize; i++) {
        CHECK (str[i] == str1[i]);
    }
    // Edge: Duplicate an empty string.
    char empty[] = "";
    char *dupEmpty = th_strdup(empty, sizeof(empty));
    CHECK(dupEmpty[0] == '\0');

    // Edge: Duplicate a string with an embedded null
    // Expect: Only characters up to the first null are copied.
    char withEmbeddedNull[] = {'h','e','l','\0','l','o','\0'};
    // Provide full buffer size.
    int bufSize = sizeof(withEmbeddedNull);
    char *dupEmbedded = th_strdup(withEmbeddedNull, bufSize);
    // Only "hel" should be duplicated.
    CHECK(dupEmbedded[0] == 'h');
    CHECK(dupEmbedded[1] == 'e');
    CHECK(dupEmbedded[2] == 'l');
    CHECK(dupEmbedded[3] == '\0');
    // Free the allocated memory
    th_strfree(dupEmbedded);
    dupEmbedded = NULL;
    th_strfree(str1);
    str1 = NULL;
    th_strfree(dupEmpty);
    dupEmpty = NULL;
}

TEST_CASE ("strndup", "[str],[strndup]") {
    char h [] = "12345";
    int bufferSize = sizeof(h) / sizeof(h[0]);
    char* h1 = th_strndup(h, 3, bufferSize);
    for (int i = 0; i < 3; i++) {
        CHECK (h[i] == h1[i]);
    }
    // Edge: Duplicate zero characters should return an empty string.
    char testStr[] = "hello";
    char* dupZero = th_strndup(testStr, 0, sizeof(testStr));
    CHECK(dupZero[0] == '\0');

    // Edge: When requested length exceeds the actual string length,
    // the function should only copy up to the null terminator.
    char* dupOver = th_strndup(testStr, 10, sizeof(testStr));
    for (int i = 0; testStr[i] != '\0'; i++) {
        CHECK(testStr[i] == dupOver[i]);
    }
    // Edge: Duplicate a string with an embedded null.
    // Only characters before the first null should be copied.
    char embedded[] = {'a','b','c','\0','x','y','z','\0'};
    int embSize = sizeof(embedded);
    char* dupEmb = th_strndup(embedded, 5, embSize);
    // Even though we requested 5 characters, duplication stops at first null.
    CHECK(dupEmb[0] == 'a');
    CHECK(dupEmb[1] == 'b');
    CHECK(dupEmb[2] == 'c');
    CHECK(dupEmb[3] == '\0');
    // Free the allocated memory   
    th_strfree(dupEmb);
    dupEmb = NULL;
    th_strfree(dupOver);
    dupOver = NULL;
    th_strfree(dupZero);
    dupZero = NULL;
    th_strfree(h1);
    h1 = NULL;
}

TEST_CASE ("strstr", "[str],[strstr]") {
    {
        char str1 [] = "Aa Ab Ac";
        char str2 [] = "Ab";
        int bufferSize1 = sizeof(str1) / sizeof(str1[0]);
        int bufferSize2 = sizeof(str2) / sizeof(str2[0]);
        CHECK (th_strstr(str1, str2, bufferSize1, bufferSize2) == &str1[3]);
    }
    {
        char str1 [] = "Aa Ac Abc";
        char str2 [] = "Abc";
        int bufferSize1 = sizeof(str1) / sizeof(str1[0]) - 3;
        int bufferSize2 = sizeof(str2) / sizeof(str2[0]);
        CHECK (th_strstr(str1, str2, bufferSize1, bufferSize2) == NULL);
    }
    {
        char str1 [] = "Aa Ac Abd";
        char str2 [] = "Abc";
        int bufferSize1 = sizeof(str1) / sizeof(str1[0]);
        int bufferSize2 = sizeof(str2) / sizeof(str2[0]) - 1;
        CHECK (th_strstr(str1, str2, bufferSize1, bufferSize2) == NULL);
    }
    {
        char str1 [] = "Aa Ac Abd";
        char str2 [] = "Abc";
        int bufferSize1 = sizeof(str1) / sizeof(str1[0]);
        int bufferSize2 = sizeof(str2) / sizeof(str2[0]) - 2;
        CHECK (th_strstr(str1, str2, bufferSize1, bufferSize2) == NULL);
    }
    {
        char str1 [] = "Aa Abc Abd";
        char str2 [] = "Abc";
        int bufferSize1 = sizeof(str1) / sizeof(str1[0]);
        int bufferSize2 = sizeof(str2) / sizeof(str2[0]) - 3;
        CHECK (th_strstr(str1, str2, bufferSize1, bufferSize2) == NULL);
    }
    {
        char str1 [] = "Aa Abc Abd";
        char str2 [] = "Abc";
        int bufferSize1 = sizeof(str1) / sizeof(str1[0]) - 5;
        int bufferSize2 = sizeof(str2) / sizeof(str2[0]);
        CHECK (th_strstr(str1, str2, bufferSize1, bufferSize2) == &str1[3]);
    }
}

TEST_CASE ("islower", "[str],[islower]") {
    char c = 'a';
    CHECK (th_islower(c) == true);
    for (int i = c; i < 122; i++) {
        c++;
        CHECK (th_islower(c) == true);
    }
}

TEST_CASE ("ishigher", "[str],[ishigher]") {
    char c = 'A';
    CHECK (th_ishigher(c) == true);
    for (int i = c; i < 90; i++) {
        c++;
        CHECK (th_ishigher(c) == true);
    }
}

TEST_CASE ("strcmp", "[str],[strcmp]") {
    char str1 [] = "12345";
    char str2 [] = "12345";
    int bufferSize1 = sizeof(str1) / sizeof(str1[0]);
    int bufferSize2 = sizeof(str2) / sizeof(str2[0]);
    CHECK (th_strcmp(str1, str2, bufferSize1, bufferSize2) == 0);
    CHECK (th_strcmp(th_strndup(str1, 4, bufferSize1), str2, bufferSize1, bufferSize2) == -1);
    CHECK (th_strcmp(str1, th_strndup(str2, 4, bufferSize2), bufferSize1, bufferSize2) == 1);
}
