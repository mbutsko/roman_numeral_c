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
extern const int invalid_roman_code;
extern const char *invalid_arabic_code;

/* Conversion functions */
char *toRoman(int);
int toArabic(char*);
int isNonRepeating(const char*);

/* Arithmetic functions */
char *addRoman(char*, char*);
char *subtractRoman(char*, char*);

#endif /* ROMAN_H */
