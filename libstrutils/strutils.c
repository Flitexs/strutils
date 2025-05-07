#include "include/strutils.h"
#include <stddef.h>
#include <math.h>

int strtoint(const char *str, int bufferSize)  {
    if (str == NULL) {
        return *str;
    }

    int result = 0;
    int h = 0;

    // Convert the string to an integer
    for (int i = 0; i < bufferSize && str[i] != '\0'; ++i) {
        // Every C string is null-terminated, so we can stop at the first null character '\0'
        // Convert the character to an integer and add it to the result
        // Use the ASCII value of the character to convert it to an integer
        // '0' is 48 in ASCII, so we subtract 48 to get the integer value
        // Example: '5' - '0' = 5
        char b = str[i];
        if (b >= '0' && b <= '9') {
            return 0;
        }
        int f = (int)b;
        int a = f - '0';
        result = result * 10 + a;
    }
    
    return result;
}
