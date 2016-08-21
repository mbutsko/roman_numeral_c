/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#include <string.h>
#include <stdio.h>
#include "roman.h"

static char* NON_REPEATING[] = { "D", "L", "V" };
static char* NUMERALS[] =
      {  "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
static int NUMBERS[] =
      { 1000, 900, 500, 400,  100,   90,  50,   40,  10,    9,   5,    4,  1 };

static int NUMERAL_COUNT = sizeof(NUMBERS)/sizeof(int);
const int INVALID_ROMAN_CODE = 4000;
const char *INVALID_ARABIC_CODE = "ERROR";

/* Convert integer to Roman Numeral to integer. */
int toArabic(const char* numeral)
{
    int arabic, i, j, lastMatchIndex = 0;
    size_t current_pos = 0;

    arabic = 0;

    for (i=0; i < NUMERAL_COUNT; i++) {

        if (current_pos >= strlen(numeral)) { break; }

        for (j=0; j < 3; ++j) {
            if (strncmp(NUMERALS[i], numeral + current_pos, strlen(NUMERALS[i])) == 0) {
                if (isSubtractive(NUMERALS[i]) == 1 && isNON_REPEATING(NUMERALS[i-1]) == 1 && lastMatchIndex == i - 1) {    break;    }
                arabic += NUMBERS[i];
                current_pos += strlen(NUMERALS[i]);
                lastMatchIndex = i;
                /* Non-repeating NUMERALS */
                if (isNON_REPEATING(NUMERALS[i]) == 1) {    break;    }
            }
        }
    }

    /* If we have not processed the last character, then the numeral was invalid.
     * Return error code. */
    if (current_pos != strlen(numeral)) { arabic = INVALID_ROMAN_CODE; }

    return arabic;
}

/* Convert integer to Roman Numeral */
char* toRoman(int x)
{
    int i;
    char numeral[16];
    memset(numeral, 0, 16);

    for (i=0; i < NUMERAL_COUNT; i++) {
        while (x >= NUMBERS[i]) {
            strcat(numeral, NUMERALS[i]);
            x -= NUMBERS[i];
        }
    }
    if (strlen(numeral) == 0) { strcpy(numeral, INVALID_ARABIC_CODE); }
    return strdup(numeral);
}

int isNON_REPEATING(const char *roman) {
    size_t i;
    for (i=0; i < sizeof(NON_REPEATING)/sizeof(NON_REPEATING[0]); i++) {
        /* Non-repeating numeral or any subtractive */
        if (strcmp(roman, NON_REPEATING[i]) == 0 || isSubtractive(roman)) {
            return 1;
        }
    }
    return 0;
}

int isSubtractive(const char *roman) {
    if (strlen(roman) > 1) {
        return 1;
    }
    return 0;
}
