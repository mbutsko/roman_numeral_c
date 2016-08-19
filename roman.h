/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#ifndef ROMAN_H
#define ROMAN_H

/* Constants */
extern const char* numerals[];
extern const int numbers[];
extern const int numeral_count;
extern const int max_roman;

/* Conversion functions */
char *toRoman(int);
int toArabic(char*);

/* Arithmetic functions */
char *addRoman(char*, char*);
char *subtractRoman(char*, char*);

#endif /* ROMAN_H */
