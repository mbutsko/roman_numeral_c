#include <stdio.h>
#include "roman.h"

#test converts_zero_to_empty_string
        ck_assert_str_eq(toRoman(0), "");

#test converts_one_to_I
        ck_assert_str_eq(toRoman(1), "I");

#test negative_number_converts_to_empty_string
        ck_assert_str_eq(toRoman(-1), "");

#test converts_string_of_numerals_to_arabic
        ck_assert_str_eq(toRoman(3), "III");

#test converts_multiple_digit_numerals_to_arabic
        ck_assert_str_eq("IV", toRoman(4));

#test converts_five_to_V
        ck_assert_str_eq("V", toRoman(5));

#test converts_forty_four_to_XCIV
        ck_assert_str_eq("XLIV", toRoman(44));

#test converts_empty_to_zero
        ck_assert_int_eq(0, toArabic(""));

#test converts_I_to_one
        ck_assert_int_eq(1, toArabic("I"));

#test converts_two_of_same_numeral_in_a_row
        ck_assert_int_eq(2, toArabic("II"));

#test converts_single_term_roman_to_arabic
        ck_assert_int_eq(100, toArabic("C"));

#test converts_two_digit_single_term_roman_to_arabic
        ck_assert_int_eq(9, toArabic("IX"));

#test converts_multiple_two_digit_terms_roman_to_arabic
        ck_assert_int_eq(29, toArabic("XXIX"));
