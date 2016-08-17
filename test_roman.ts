#include <stdio.h>
#include "roman.h"

#test converts_zero_to_empty_string
        ck_assert_str_eq("", rom_ToRoman(0));

#test converts_one_to_I
        ck_assert_str_eq("I", rom_ToRoman(1));

#test converts_string_of_numerals_to_arabic
        ck_assert_str_eq("III", rom_ToRoman(3));

#test converts_multiple_digit_numerals_to_arabic
        ck_assert_str_eq("IV", rom_ToRoman(4));

#test converts_five_to_V
        ck_assert_str_eq("V", rom_ToRoman(5));

#test converts_forty_four_to_XCIV
        ck_assert_str_eq("XLIV", rom_ToRoman(44));

#test converts_empty_to_zero
        ck_assert_int_eq(0, rom_ToArabic(""));

#test converts_I_to_one
        ck_assert_int_eq(1, rom_ToArabic("I"));

#test converts_two_of_same_numeral_in_a_row
        ck_assert_int_eq(2, rom_ToArabic("II"));

#test converts_single_term_roman_to_arabic
        ck_assert_int_eq(100, rom_ToArabic("C"));

#test converts_two_digit_single_term_roman_to_arabic
        ck_assert_int_eq(9, rom_ToArabic("IX"));

#test converts_multiple_two_digit_terms_roman_to_arabic
        ck_assert_int_eq(29, rom_ToArabic("XXIX"));
