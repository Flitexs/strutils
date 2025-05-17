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
    return (char*) malloc(size * sizeof(char));
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
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return false;
    }
    else {
        return true;
    }
}
