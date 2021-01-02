/**************************************************************************************************
 *  File:    pzs_join.h
 *  Purpose: Concatenate a string array into a single string, separated by another string
 *  Author:  Moritz Molch <mail@moritzmolch.de>
 *  Created: 01.01.2021
 *  License: Public Domain
 *************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PZS_PREFIX
#define PZS_PREFIX(function) pzs_##function
#endif

#ifndef PZS_JOIN_H
#define PZS_JOIN_H

/**
 * @brief Joins an array of strings into a single, NUL terminated string
 *
 * @example
 * int joinedString_size = pzs_join(NULL, " ", num_strings, strings);
 * char args[joinedString_size];
 * joinedString_size = pzs_join((char*)&joinedString, " ", num_strings, strings);
 * if (joinedString_size < 0) {
 *     // ERROR
 * }
 *
 * @param outString destination buffer, set to NULL to only get the size
 * @param separator the string which is put between the strings
 * @param num_strings the number of strings that the strings array contains
 * @param strings an array of strings, NULL strings are ignored
 *
 * @return the size of the resulting string (including a terminal NUL * character), -1 on error
 */
int PZS_PREFIX(join)(char *outString, const char *separator, int num_strings, const char const *strings[]);

#endif /* PZS_JOIN_H */

/**************************************************************************************************
 * Implementation
 *************************************************************************************************/

#ifdef PZS_IMPLEMENTATION

#include <string.h>

int PZS_PREFIX(join)(char *outString, const char *separator, int num_strings, const char const *strings[])
{
    if ((separator == NULL) || (strings==NULL) || (num_strings<0)) {
        return -1;
    }

    if (num_strings == 0) {
        if (outString != NULL) {
            outString = '\0';
        }
        return 1;
    }

    if (num_strings == 1) {
        if (strings[0] == NULL) {
            if (outString != NULL) {
                outString = '\0';
            }
            return 1;
        }

        size_t outString_size = strlen(strings[0])+1;
        if (outString != NULL) {
            memcpy(outString, strings[0], outString_size);
            outString[outString_size-1] = '\0';
        }
        return outString_size;
    }

    int separator_length = strlen(separator);
    int outString_size = separator_length*(num_strings-1)+1;

    int i;

    for (i=0; i<num_strings; i++) {
        outString_size += strlen(strings[i]);
    }

    if (outString == NULL) {
        return outString_size;
    }

    char* pos = outString;
    for (i=0; i<num_strings; i++) {
        if (strings[i] == NULL) {
            continue;
        }
        size_t length = strlen(strings[i]);
        memcpy(pos, strings[i], length);
        pos += length;

        if (i<num_strings-1) {
            memcpy(pos, separator, separator_length);
            pos += separator_length;
        }
    }
    pos[0] = '\0';

    return outString_size;
}

#endif  /* PZS_IMPLEMENTATION */

#ifdef __cplusplus
}
#endif
