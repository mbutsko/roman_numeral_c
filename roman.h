/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#ifndef ROMAN_H
#define ROMAN_H

char *toRoman(int);
int toArabic(char*);

char *addRoman(char*, char*);
char *subtractRoman(char*, char*);

static const char* numerals[] =
    {  "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

static const int numbers[] =
    { 1000, 900, 500, 400,  100,   90,  50,   40,  10,    9,   5,    4,  1 };

static const int numeral_count = sizeof(numbers)/sizeof(int);

static const int max_roman = 3999;

#endif /* ROMAN_H */
