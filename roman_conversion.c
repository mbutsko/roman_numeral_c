/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#include <string.h>
#include <stdio.h>
#include "roman.h"

const char* nonRepeating[] = { "D", "L", "V" };
const char* numerals[] =
    {  "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

const int numbers[] =
    { 1000, 900, 500, 400,  100,   90,  50,   40,  10,    9,   5,    4,  1 };


const int numeral_count = sizeof(numbers)/sizeof(int);
const int max_roman = 3999;
const int invalid_roman_code = 4000;
const char *invalid_arabic_code = "ERROR";

/* Convert integer to Roman Numeral to integer. */
int toArabic(char* numeral)
{
  int arabic, i, j;
  size_t current_pos = 0;

  arabic = 0;

  for (i=0; i < numeral_count; i++) {

    if (current_pos >= strlen(numeral)) { break; }

    for (j=0; j < 3; ++j) {
      if (strncmp(numerals[i], numeral + current_pos, strlen(numerals[i])) == 0) {
        arabic += numbers[i];
        current_pos += strlen(numerals[i]);
        /* Non-repeating numerals */
        if (isNonRepeating(numerals[i]) == 1) { 
          break; 
        }
      }
    }
  }
  /* If we have not processed the last character, then the numeral was invalid. 
   * Return error code. */
  if (current_pos != strlen(numeral)) { arabic = invalid_roman_code; }

  return arabic;
}

/* Convert integer to Roman Numeral */
char* toRoman(int x) 
{
  int i;
  char numeral[16];
  memset(numeral, 0, 16);

  for (i=0; i < numeral_count; i++) {
    while (x >= numbers[i]) { 
      strcat(numeral, numerals[i]);
      x -= numbers[i];
    }
  }
  if (strlen(numeral) == 0) { strcpy(numeral, invalid_arabic_code); }
  return strdup(numeral);
}

int isNonRepeating(const char *roman) {
  size_t i;
  for (i=0; i < sizeof(nonRepeating)/sizeof(nonRepeating[0]); i++) {
    /* Non-repeating numeral or any subtractive */
    if (strcmp(roman, nonRepeating[i]) == 0 || isSubtractive(roman)) {
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
