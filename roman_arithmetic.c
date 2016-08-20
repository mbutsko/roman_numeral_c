/**************************************************************************
 * Roman Numeral Arithmetic
 *************************************************************************/

#include <string.h>
#include <stdio.h>
#include "roman.h"

/* Add two roman NUMERALS
 *
 * Returns zero length string if sum is greater than max numeral */
char* addRoman(char* augend, char* addend)
{
    int arabicSum = toArabic(augend) + toArabic(addend);;
    char *romanSum;

    if (arabicSum > MAX_ROMAN) {
        romanSum = strdup(INVALID_ARABIC_CODE);
    }
    else {
        romanSum = toRoman(arabicSum);
    }

    return romanSum;
}

/* Subtract two roman numerals;  Returns error if minuend < subtrahend */
char* subtractRoman(char* minuend, char* subtrahend)
{
    int arabicDifference = toArabic(minuend) - toArabic(subtrahend);
    char *romanDifference;

    if (arabicDifference > 0) {
        romanDifference = toRoman(arabicDifference);
    }
    else {
        romanDifference = strdup(INVALID_ARABIC_CODE);
    }

    return romanDifference;
}
