/**************************************************************************************************
 *  File:    pzs_copy.h
 *  Purpose: Copies a string, ensuring that the resulting string is NUL terminated
 *  Author:  Moritz Molch <mail@moritzmolch.de>
 *  Created: 02.01.2021
 *  License: Public Domain
 *************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PZS_COPY_H
#define PZS_COPY_H

/**
 * @brief Copies a string, ensuring that the resulting string is NUL terminated
 *
 * @example
 * char text[] = "Hello World";
 * int text_copy_size = pzs_copy(NULL, text);
 * char text_copy[text_copy_size];
 * text_copy_size = pzs_copy((char*)&text_copy, text);
 * if (text_copy_size < 0) {
 *     // ERROR
 * }
 * // text_copy: "Hello World"
 *
 * @param outString destination buffer, set to NULL to only get the size
 *
 * @return the size of the resulting string (including a terminal NUL * character), -1 on error
 */
int pzs_copy(char *outString, char *otherString);

#endif /* PZS_COPY_H */

/**************************************************************************************************
 * Implementation
 *************************************************************************************************/

#ifdef PZS_IMPLEMENTATION

#include <string.h>

int pzs_copy(char *outString, char *otherString)
{
    if (otherString == NULL) {
        if (outString != NULL) {
            outString[0] = '\0';
        }
        return 1;
    }

    int outString_size = strlen(otherString)+1;

    if (outString != NULL) {
        memcpy(outString, otherString, outString_size-1);
        outString[outString_size-1] = '\0';
    }

    return outString_size;
}

#endif  /* PZS_IMPLEMENTATION */

#ifdef __cplusplus
}
#endif
