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
  arabicSum = toArabic(augend) + toArabic(addend);
  return toRoman(arabicSum);
}

/* Subtract two roman numerals */
char* subtractRoman(char* minuend, char* subtrahend)
{
  int arabicDifference;
  arabicDifference = toArabic(minuend) - toArabic(subtrahend);
  return toRoman(arabicDifference);
}
