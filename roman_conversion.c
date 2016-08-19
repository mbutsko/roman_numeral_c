/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#include <string.h>
#include <stdio.h>
#include "roman.h"

const char* numerals[] =
    {  "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

const int numbers[] =
    { 1000, 900, 500, 400,  100,   90,  50,   40,  10,    9,   5,    4,  1 };

const int numeral_count = sizeof(numbers)/sizeof(int);

const int max_roman = 3999;

/* Convert integer to Roman Numeral to integer. */
int toArabic(char* numeral)
{
  int arabic, i, j;
  size_t current_pos;

  arabic = 0;
  current_pos = 0;

  for (i=0; i < numeral_count; i++) {

    if (current_pos >= strlen(numeral)) { break; }

    for (j=0; j < 3; ++j) {
      if (strncmp(numerals[i], numeral + current_pos, strlen(numerals[i])) == 0) {
        arabic += numbers[i];
        current_pos += strlen(numerals[i]);
      }
    }
  }
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
  return strdup(numeral);
}
