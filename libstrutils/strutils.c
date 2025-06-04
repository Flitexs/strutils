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

    char* string = th_stralloc(th_strlen(str, bufferSize) + 1);

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
    int coefficient = th_strlen(str2, bufferSize2);

    for (; i < bufferSize1 && str1[i] != '\0'; i++) {
        for (j = 0; j < coefficient && j + i < bufferSize1 && str1[j + i] == str2[j]; j++) {
            if (j == coefficient - 1) {
                return (char *)&str1[i];
            }
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

int th_strncmp(const char* str1, const char* str2, int n, int bufferSize1, int bufferSize2) {
    int i = 0;
    for (; i < n && bufferSize1 && i < bufferSize2 && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; i++);
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

char **th_strsplit(const char* str, const char* delim, int bufferSize1, int bufferSize2) {
    if (str == NULL || bufferSize1 <= 0 || delim == NULL || bufferSize2 <= 0) {
        return NULL;
    }
    
    int strlenStr = th_strlen(str, bufferSize1);
    int strlenDelim = th_strlen(delim, bufferSize2);
    int delimCount = 0;
    bool exitAllLoops = false;

    for (int i = 0; i < strlenStr; i++) {
        if (str[i] == delim[0]) {
            for (int j = 1; j < strlenDelim; j++) {
                if (str[i + j] == delim[j] && j == strlenDelim - 1) {
                    delimCount++;
                    i += strlenDelim - 1;
                    break;
                }
                else if (str[i + j] != delim[j]) {
                    break;
                }
            }
        }
    }

   int* delimStart = (int*) malloc(delimCount * sizeof(int));
   int* delimEnd = (int*) malloc(delimCount * sizeof(int));
   int indexDelim = -1;

    for (int i = 0; i < strlenStr; i++) {
        if (str[i] == delim[0]) {
            indexDelim++;
            delimStart[indexDelim] = i;
            for (int j = 1; j < strlenDelim; j++) {
                if (str[i + j] == delim[j] && j == strlenDelim - 1) {
                    delimEnd[indexDelim] = i + j;
                    i += strlenDelim - 1;
                    break;
                }
                else if (str[i + j] != delim[j]) {
                    delimStart[indexDelim] = 0;
                    indexDelim--;
                    break;
                }
            }
        }
    }
    indexDelim = -1;

    int tokenCount = 0;

    for (int i = 0; i < strlenStr; i++) {
        if (i != delimStart[indexDelim] && i != delimEnd[indexDelim]) {
            indexDelim++;
            for (int j = 1; j < strlenStr && delimEnd[indexDelim]; j++) {
                if (delimStart[indexDelim] == i + j ) {
                    tokenCount++;
                    i = delimEnd[indexDelim];
                    break;
                }
                if (i + j == strlenStr - 1) {
                    indexDelim = indexDelim - delimCount - 1;
                    tokenCount++;
                    exitAllLoops = true;
                    break;
                }
            }
            if (exitAllLoops == true) {
                exitAllLoops = false;
                break;
            }
        }
    }
    indexDelim = -1;

   int* tokenStart = (int*) malloc(tokenCount * sizeof(int));
   int* tokenEnd = (int*) malloc(tokenCount * sizeof(int));
   int indexToken = -1;

    for (int i = 0; i < strlenStr; i++) {
        if (i != delimStart[indexDelim] || i != delimEnd[indexDelim] || i < strlenStr) {
            indexDelim++;
            indexToken++;
            tokenStart[indexToken] = i;
            for (int j = 1; j < strlenStr || delimStart[indexDelim]; j++) {
                if (i + j == delimStart[indexDelim] - 1) {
                    tokenEnd[indexToken] = i + j;
                    if (indexDelim < delimCount) {
                        i = delimEnd[indexDelim];
                    }
                    else {
                        i += j;
                    }
                    break;
                }
                else if (i + j == strlenStr - 1) {
                    tokenEnd[indexToken] = i + j;
                    exitAllLoops = true;
                    break;
                }
            }
            if (exitAllLoops == true) {
                exitAllLoops = false;
                break;
            }
        }
    }
    indexDelim = -1;
    indexToken = -1;
    
    char** res = (char**) malloc((tokenCount + 1) * sizeof(char*));

    if (res == NULL) {
        return NULL;
    }

    for (int i = 0; i < tokenCount; i++) { 
        res[i] = th_strndup(&str[tokenStart[i]], tokenEnd[i] + 1 - tokenStart[i], strlenStr);
    }
    
    res[tokenCount] = NULL;
    
    return res;
}
