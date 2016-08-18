/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#include <string.h>
#include <stdio.h>
#include <roman_conversion.h>

/* Convert integer to Roman Numeral to integer. */
int toArabic(char* numeral)
{
  int arabic, i, j, current_pos;

  arabic = 0;
  current_pos = 0;

  for (i=0; i < numeral_count; i++) {
    if (current_pos >= strlen(numeral)) {
      break;
    }
    if (strlen(numerals[i]) == 2) {
      /* Two character numeral check */
      if (strncmp(numerals[i], numeral + current_pos, 2) == 0) {
        arabic += numbers[i];
        current_pos += 2;
      }
    } else {
      /* Up to three single character numeral check */
      for (j=0; j < 3; ++j) {
        if (strncmp(numerals[i], numeral + current_pos, 1) == 0) {
          arabic += numbers[i];
          current_pos += 1;
        }
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
      x = x - numbers[i];
    }
  }
  return strdup(numeral);
}
