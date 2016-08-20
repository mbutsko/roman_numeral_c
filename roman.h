/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#ifndef ROMAN_H
#define ROMAN_H

/* Constants */
extern const char* NON_REPEATING[];
extern const char* NUMERALS[];
extern const int NUMBERS[];
extern const int MAX_ROMAN;
extern const int NUMERAL_COUNT;
extern const int INVALID_ROMAN_CODE;
extern const char *INVALID_ARABIC_CODE;

/* Conversion functions */
char *toRoman(int);
int toArabic(char*);
int isNON_REPEATING(const char*);
int isSubtractive(const char*);

/* Arithmetic functions */
char *addRoman(char*, char*);
char *subtractRoman(char*, char*);

#endif /* ROMAN_H */
