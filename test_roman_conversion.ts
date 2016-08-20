#include <stdio.h>
#include "roman.h"

#test converting_negative_number_results_in_error
        ck_assert_str_eq(toRoman(-1), INVALID_ARABIC_CODE);

#test converts_zero_to_empty_string
        ck_assert_str_eq(toRoman(0), INVALID_ARABIC_CODE);

#test converts_one_to_I
        ck_assert_str_eq(toRoman(1), "I");

#test converts_string_of_NUMERALS_to_arabic
        ck_assert_str_eq(toRoman(3), "III");

#test converts_multiple_digit_NUMERALS_to_arabic
        ck_assert_str_eq(toRoman(4), "IV");

#test converts_five_to_V
        ck_assert_str_eq(toRoman(5), "V");

#test converts_forty_four_to_XCIV
        ck_assert_str_eq(toRoman(44), "XLIV");

#test converts_empty_to_error
        ck_assert_int_eq(toArabic(""), 0);

#test converts_I_to_one
        ck_assert_int_eq(toArabic("I"), 1);

#test converts_two_of_same_numeral_in_a_row
        ck_assert_int_eq(toArabic("II"), 2);

#test converts_subtractive_of_non_repeating
        ck_assert_int_eq(toArabic("IV"), 4);

#test converts_non_repeating
        ck_assert_int_eq(toArabic("V"), 5);

#test converts_single_term_roman_to_arabic
        ck_assert_int_eq(toArabic("C"), 100);

#test converts_two_digit_single_term_roman_to_arabic
        ck_assert_int_eq(toArabic("IX"), 9);

#test converts_multiple_two_digit_terms_roman_to_arabic
        ck_assert_int_eq(toArabic("XXIX"), 29);

#test does_not_convert_invalid_numeral
        ck_assert_int_eq(toArabic("XXIXX"), INVALID_ROMAN_CODE);

#test does_not_convert_more_than_three_repeating_to_numeral
        ck_assert_int_eq(toArabic("IIII"), INVALID_ROMAN_CODE);

#test does_not_convert_sequence_of_non_repeating_NUMERALS
        ck_assert_int_eq(toArabic("VV"), INVALID_ROMAN_CODE);

#test does_not_convert_sequence_of_non_repeating_NUMERALS_subtractive
        ck_assert_int_eq(toArabic("IVIV"), INVALID_ROMAN_CODE);

#test does_not_convert_sequence_of_a_NON_REPEATING_numeral_and_its_subtractive
        ck_assert_int_eq(toArabic("VIV"), INVALID_ROMAN_CODE);
