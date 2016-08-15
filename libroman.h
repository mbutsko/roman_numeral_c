#ifndef ROMAN_H
#define ROMAN_H

char* rom_ToRoman(int);

static const char* rom_numerals[] = {  "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
static const int rom_numbers[] =    { 1000, 900, 500, 400,  100,   90,  50,   40,  10,    9,   5,    4,  1 };

#endif /* ROMAN_H */
