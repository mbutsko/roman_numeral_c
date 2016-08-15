#ifndef ROMAN_H
#define ROMAN_H

const char* rom_ToRoman(int);

static const char* rom_numerals[] = { 
  "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
static const int rom_numbers[] = { 1, 4, 5, 9, 10, 50, 100, 500, 1000 };

#endif /* ROMAN_H */
