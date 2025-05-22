#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Computes the length of the string up to a maximum of bufferSize characters.
 *
 * This function safely computes the length of the input string while ensuring that 
 * it does not exceed the provided bufferSize.
 *
 * @param str The input null-terminated string.
 * @param bufferSize The maximum number of characters to examine.
 * @return The length of the string, or a negative value if an error occurs.
 */
int th_strlen(const char* str, int bufferSize);

/**
 * @brief Computes the length of the string without any buffer size limit.
 *
 * This function calculates the length of the input null-terminated string without 
 * imposing any upper bound on the number of characters processed.
 *
 * @param str The input null-terminated string.
 * @return The length of the string.
 */
int th_strlen_unsafe(const char* str);

/**
 * @brief Checks if the provided character is an alphabetic letter.
 *
 * This function determines whether the given character is a letter (either uppercase 
 * or lowercase).
 *
 * @param c The character to check.
 * @return true if c is an alphabetic letter; false otherwise.
 */
bool th_isalpha(char c);

/**
 * @brief Checks if the provided character is a digit.
 *
 * This function determines whether the given character is a decimal digit ('0' - '9').
 *
 * @param c The character to check.
 * @return true if c is a digit; false otherwise.
 */
bool th_isdigit(char c);

/**
 * @brief Checks if the provided character is a whitespace character.
 *
 * This function determines whether the given character is a whitespace character (space, 
 * tab, newline, etc.).
 *  (c == 32 || c == '\t' || c == '\n' 
 *	|| c == '\v' || c == '\r' || c == '\f')
 * @param c The character to check.
 * @return true if c is a whitespace character; false otherwise.
 */
bool th_isspace(char c);

/**
 * @brief Checks if the provided character is a lowercase letter.
 * 
 * @param c The character to check.
 * @return true if c is a lowercase letter; false otherwise.
 */
bool th_islower(char c);

/**
 * @brief Checks if the provided character is an uppercase letter.
 * 
 * @param c The character to check.
 * @return true if c is an uppercase letter; false otherwise.
 */
bool th_ishigher(char c);

/**
 * @brief Converts a string to an integer.
 *
 * This function processes the input string and returns its integer representation.
 * The conversion respects the provided bufferSize to avoid reading out-of-bounds.
 *
 * @param str The input string containing the integer representation.
 * @param bufferSize The maximum number of characters to consider.
 * @return The integer value computed from the string.
 */
int strtoint(const char* str, int bufferSize);

/**
 * @brief Duplicates the input string.
 *
 * This function creates a duplicate of the input string ensuring that no more than 
 * bufferSize characters are duplicated.
 *
 * @param str The input null-terminated string.
 * @param bufferSize The maximum number of characters to duplicate.
 * @return A pointer to the newly allocated duplicate of the string, or NULL on failure.
 */
char *th_strdup(const char* str, int bufferSize);

/**
 * @brief Duplicates up to n characters of the input string.
 *
 * This function creates a duplicate of the first n characters of the input string, 
 * ensuring that no more than bufferSize characters are processed.
 *
 * @param str The input null-terminated string.
 * @param n The maximum number of characters to duplicate, -1 is used to indicate
 *          that the entire string should be duplicated.
 * @param bufferSize The maximum number of characters to process.
 * @return A pointer to the newly allocated duplicate of the substring, or NULL on failure.
 */
char *th_strndup(const char* str, int n, int bufferSize);

/**
 * @brief Concatenates two strings.
 *
 * This function appends the source string to the destination string, ensuring that 
 * neither the destination buffer (bufferSize1) nor the source buffer (bufferSize2) are overrun.
 *
 * @param dest The destination string buffer.
 * @param src The source string to append.
 * @param bufferSize1 The size of the destination buffer.
 * @param bufferSize2 The size of the source buffer.
 * @return A pointer to the destination string.
 */
char *th_strcat(char* dest, const char* src, int bufferSize1, int bufferSize2);

/**
 * @brief Concatenates up to n characters of the source string to the destination string.
 *
 * This function appends at most n characters from the source string to the destination string,
 * ensuring that neither the destination buffer (bufferSize1) nor 
 * the source buffer (bufferSize2) is overrun.
 *
 * @param dest The destination string buffer.
 * @param src The source string.
 * @param n The maximum number of characters to concatenate from src, -1 is used to indicate
 *          that the entire string should be concatenated.
 * @param bufferSize1 The size of the destination buffer.
 * @param bufferSize2 The size of the source buffer.
 * @return A pointer to the destination string.
 */
char *th_strncat(char* dest, const char* src, int n, int bufferSize1, int bufferSize2);

/**
 * @brief Compares two strings.
 *
 * This function compares characters of two strings, making sure that it does not read beyond
 * the provided buffer sizes for either string.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param bufferSize1 The size of the first string's buffer.
 * @param bufferSize2 The size of the second string's buffer.
 * @return An integer less than, equal to, or greater than zero if str1 is found, 
 * respectively, to be less than, equal to, or greater than str2.
 */
// int th_strcmp(const char* str1, const char* str2, int bufferSize1, int bufferSize2);

/**
 * @brief Compares two strings up to n characters.
 *
 * This function compares at most n characters of two strings, making sure that it 
 * does not read beyond the provided buffer sizes for either string.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param n The maximum number of characters to compare, -1 is used to indicate
 *          that the entire string should be compared.
 * @param bufferSize1 The size of the first string's buffer.
 * @param bufferSize2 The size of the second string's buffer.
 * @return An integer less than, equal to, or greater than zero if str1 is found, 
 * respectively, to be less than, equal to, or greater than str2.
 */
// int th_strncmp(const char* str1, const char* str2, int n, int bufferSize1, int bufferSize2);

/**
 * @brief Searches for a substring within a string.
 *
 * This function locates the first occurrence of the substring (str2) within 
 * the string (str1), ensuring safe operation by not exceeding the given buffer sizes.
 *
 * @param str1 The string to be searched.
 * @param str2 The substring to find.
 * @param bufferSize1 The size of str1's buffer.
 * @param bufferSize2 The size of str2's buffer.
 * @return A pointer to the beginning of the found substring within str1, or NULL if not found.
 */
char *th_strstr(const char* str1, const char* str2, int bufferSize1, int bufferSize2);

/**
 * @brief Splits a string using a specified delimiter.
 *
 * This function splits the input string into tokens separated by the specified delimiter
 * while making sure not to read beyond the provided buffer sizes.
 *
 * @param str The input string to split.
 * @param delim The delimiter string used for splitting.
 * @param bufferSize1 The size of the input string's buffer.
 * @param bufferSize2 The size of the delimiter's buffer.
 * @return A NULL-terminated array of tokens, or NULL if memory allocation fails.
 */
// char **th_strsplit(const char* str, const char* delim, int bufferSize1, int bufferSize2);

/**
 * @brief Converts a character to lowercase.
 * 
 * This function converts the provided character to its lowercase equivalent.
 * If the character is not an uppercase letter, it is returned unchanged.
 * 
 * @param c The character to convert.
 * @return The lowercase equivalent of the character, or the original character 
 * if not applicable.
 */
char th_tolower(const char c);

/**
 * @brief Converts a string to lowercase.
 *
 * This function creates a new string that is the lowercase version of the input string,
 * ensuring that no more than bufferSize characters are processed.
 *
 * @param str The input null-terminated string.
 * @param bufferSize The maximum number of characters to process in the string.
 * @return A pointer to the newly allocated lowercase string, or NULL on failure.
 */
char *th_strtolower(const char* str, int bufferSize);


/**
 * @brief Converts a string to uppercase.
 *
 * This function creates a new string that is the uppercase version of the input string,
 * ensuring that no more than bufferSize characters are processed.
 *
 * @param str The input null-terminated string.
 * @param bufferSize The maximum number of characters to process in the string.
 * @return A pointer to the newly allocated uppercase string, or NULL on failure.
 */
// char *strtoupper(const char* str, int bufferSize);

/**
 * @brief Prints the string to the standard output.
 *
 * This function outputs the provided string to the standard output, ensuring that 
 * not more than bufferSize characters are printed.
 *
 * @param str The string to print.
 * @param bufferSize The maximum number of characters to print.
 */
// void printstr(const char* str, int bufferSize);

/**
 * @brief Prints the string to the standard error output.
 *
 * This function outputs the provided string to the standard error output, ensuring 
 * that not more than bufferSize characters are printed.
 *
 * @param str The string to print.
 * @param bufferSize The maximum number of characters to print.
 */
// void printstr_err(const char* str, int bufferSize);

/**
 * @brief Prints an integer to the standard output.
 * 
 * This function outputs the provided integer value to the standard output.
 * 
 * @param value The integer value to print.
 */
// void printint(int value);

/**
 * @brief Prints an integer to the standard error output.
 * 
 * This function outputs the provided integer value to the standard error output.
 * 
 * @param value The integer value to print.
 */
// void printint_err(int value);

/**
 * @brief Frees the memory allocated for a string.
 *
 * This function deallocates the memory used by the input string.
 *
 * @param str The string to free.
 */
void th_strfree(char* str);

/**
 * @brief Allocates memory for a string of a specified size.
 * 
 * This function allocates memory for a string of the specified size.
 * The allocated memory should be freed using strfree() when no longer needed.
 * 
 * @param size The size of the string to allocate.
 * @return A pointer to the allocated string, or NULL if allocation fails.
 */
char *th_stralloc(int size);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H

