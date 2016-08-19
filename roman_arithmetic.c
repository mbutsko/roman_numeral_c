/**************************************************************************
 * Roman Numeral Arithmetic
 *************************************************************************/

#include <string.h>
#include <stdio.h>
#include <roman.h>

/* Add two roman numerals */
char* addRoman(char* augend, char* addend)
{
  int arabicSum;
  char *romanSum;
  arabicSum = toArabic(augend) + toArabic(addend);

  if (arabicSum > max_roman) { 
    romanSum = "";
  } else {
    romanSum = toRoman(arabicSum);
  }

  return romanSum;
}

/* Subtract two roman numerals 
 *
 * Returns zero length string if minuend is less than subtrahend */
char* subtractRoman(char* minuend, char* subtrahend)
{
  int arabicDifference;
  arabicDifference = toArabic(minuend) - toArabic(subtrahend);
  return toRoman(arabicDifference);
}
