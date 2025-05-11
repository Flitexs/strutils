#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Converts a string to an integer.
 *
 * This function converts the provided string into an integer value, 
 * using the specified buffer size to ensure safe conversion.
 * It stops converting when it reaches the null terminator or the buffer size limit.
 *
 * @param str The string to convert.
 * @param bufferSize The size of the buffer.
 *
 * @return The converted integer value.
 */

int strtoint(const char* str, int bufferSize);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H

