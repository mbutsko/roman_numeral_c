/**************************************************************************
 * Roman Numeral Conversion
 *************************************************************************/

#ifndef ROMAN_CONVERSION_H
#define ROMAN_CONVERSION_H

/* Constants */
extern const int INVALID_ROMAN_CODE;
extern const char *INVALID_ARABIC_CODE;

/* Conversion functions */
char *toRoman(int);
int toArabic(const char*);

#endif /* ROMAN_CONVERSION_H */
