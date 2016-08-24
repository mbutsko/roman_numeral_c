/**************************************************************************
 * Roman Numeral Arithmetic
 *************************************************************************/

#include <string.h>
#include <stdio.h>
#include "roman_arithmetic.h"
#include "roman_conversion.h"

const int MAX_ROMAN = 3999;

/* Add two roman NUMERALS; returns ERROR if sum is greater than max numeral */
char* addRoman(const char* augend, const char* addend)
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
char* subtractRoman(const char* minuend, const char* subtrahend)
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
