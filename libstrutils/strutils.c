#include "include/strutils.h"
#include <stddef.h>

int strtoint(const char *str, int bufferSize)  {
    if (str == NULL) {
        return *str;
    }

    int result = 0;

    // Convert the string to an integer
    for (int i = 0; i < bufferSize && str[i] != '\0'; ++i) {
        // Every C string is null-terminated, so we can stop at the first null character '\0'
        // Convert the character to an integer and add it to the result
        // Use the ASCII value of the character to convert it to an integer
        // '0' is 48 in ASCII, so we subtract 48 to get the integer value
        // Example: '5' - '0' = 5
        char b = str[i];
        if (b < '0' || b > '9') {
            continue;
        }
        int f = (int)b;
        int a = f - '0';
        result = result * 10 + a;
    }
    if (str[0] == '-') {
        result = result * (-1);
    }
    return result;
}

int th_strlen(const char* str, int bufferSize) {
    if (str == NULL) {
        return *str;
    }

    int i = 0;

    for(; i < bufferSize && str[i] != '\0'; i++);

    return i;
}

void th_strfree(char* str) {
    free(str);
}

char *th_stralloc(int size) {
    return (char*)malloc(size * sizeof(char));
}

int th_strlen_unsafe(const char* str) {
    if (str == NULL) {
        return *str;
    }

    int length = 0;

    for (; length < str[length] != '\0'; length++);
    return length;
}

bool th_isalpha(char c) {
    return th_islower(c) || th_ishigher(c); //TODO: use th_islower and th_ishigher (Y)
}

bool th_isdigit(char c) {
    return (c >= '0' && c <= '9');
}

bool th_isspace(char c) {
    return (c == 32 || c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f');
}

char *th_strdup(const char* str, int bufferSize) {
    if (str == NULL || bufferSize <= 0) {
        return NULL;
    }
    // TODO: allocate not by buffersize but by th_strlen+1 (Y)
    // TODO: use th_stralloc instead of malloc everywhere in this file (Y)
    char* string = th_stralloc(th_strlen(str, bufferSize) + 1);
    // TODO: Check if memory allocation was successful everywhere in this file (Y)
    if (string == NULL) {
        return NULL;
    }
    int i = 0;
    for (; i < bufferSize && str[i] != '\0'; i++) {
        string[i] = str[i];
    }
    string[i] = '\0';
    return string;
}

char *th_strndup(const char* str, int n, int bufferSize) {
    if (str == NULL || bufferSize <= 0) {
        return NULL;
    }

    if (n < 0 || n > bufferSize) {
        return th_strdup(str, bufferSize);
    }

    char* string = th_stralloc(n + 1);
    int i = 0;
    for (; i < n && str[i] != '\0'; i++) {
        string[i] = str[i];
    }
    string[i] = '\0';
    return string;
}

char *th_strcat(char* dest, const char* src, int bufferSize1, int bufferSize2) { //TODO: add tests
    if (dest == NULL || src == NULL) {
        return NULL;
    }

    int j = th_strlen(dest, bufferSize1);

    if (j + th_strlen(src, bufferSize2) + 1 > bufferSize1) {
        return NULL;
    }

    int i = 0;


    for (; i < src[i] != '\0'; i++) {
        dest[j + i] = src[i];
    }
    dest[j + i] = '\0';
    return dest;
}

bool th_islower(char c) { //TODO: add tests (Y)
    return (c >= 'a' && c <= 'z');
}

bool th_ishigher(char c) { //TODO: add tests (Y)
    return (c >= 'A' && c <= 'Z');
}

char th_tolower(const char c) { //TODO: add tests
    if (true == (c >= 'A' && c <= 'Z')) {
        return c + 32;
    }
    else {
        return c;
    }
}

//TODO: Implement th_tohigher

char *th_strtolower(const char* str, int bufferSize) {
    if (str == NULL || bufferSize <= 0) {
        return NULL;
    }

    char *str1 = th_stralloc(bufferSize + 1);
    int i = 0;
    for (; i < bufferSize && str[i] != '\0'; i++) {
        str1[i] = th_tolower(str[i]);
    }
    str1[i] = '\0';
    return str1;
}

char *th_strstr(const char* str1, const char* str2, int bufferSize1, int bufferSize2) {
    if (str1 == NULL || bufferSize1 <= 0 || str2 == NULL || bufferSize2 == 0) {
        return NULL;
    }

    int i = 0;
    int j = 0;
    for (; i < bufferSize1 && str1[i]; i++) {
        if (str1[i] == str2[i]) {
            for (j = i; j < bufferSize2 && str2[j] != '\0'; j++) {
                if (str1[j] != str2[j]) {
                    break;
                }
                if (j == bufferSize2 - 1) {
                    return (char *)&str1[i];
                }
                if (str1[j] == str2[j]) {
                    continue;
                }
            }
            j = 0;
            continue;
        }
    }
    return NULL;
}

int th_strcmp(const char* str1, const char* str2, int bufferSize1, int bufferSize2) {
    int i = 0;
    for (; i < bufferSize1 && i < bufferSize2 && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; i++);
    if (i == bufferSize1 && i == bufferSize2) {
        return 0;
    } 
    else if (i == bufferSize1 && str1[i] == '\0' && i < bufferSize2 && str2[i] == '\0') {
        return 0;
    }
    if (i < bufferSize1 && str1[i] == '\0' && (i >= bufferSize2 || str2[i] != '\0')) {
        return -1;
    }
    if (i < bufferSize2 && str2[i] == '\0' && (i >= bufferSize1 || str1[i] != '\0')) {
        return 1;
    }
    if (i == bufferSize1 && i < bufferSize2 && str2[i] != '\0') {
        return -1;
    }
    if (i == bufferSize2 && i < bufferSize1 && str1[i] != '\0') {
        return 1;
    }
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}
