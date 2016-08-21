/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#ifndef ROMAN_H
#define ROMAN_H

/* Constants */
extern const int INVALID_ROMAN_CODE;
extern const char *INVALID_ARABIC_CODE;

/* Conversion functions */
char *toRoman(int);
int toArabic(const char*);
int isNON_REPEATING(const char*);
int isSubtractive(const char*);

/* Arithmetic functions */
char *addRoman(const char*, const char*);
char *subtractRoman(const char*, const char*);

#endif /* ROMAN_H */
