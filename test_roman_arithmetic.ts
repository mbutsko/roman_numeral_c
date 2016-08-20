#include <stdio.h>
#include "roman.h"

#test add_one_to_one_to_get_two
        ck_assert_str_eq(addRoman("I", "I"), "II");

#test add_multiple_single_NUMERALS_to_get_a_subtractive
        ck_assert_str_eq(addRoman("II", "II"), "IV");

#test add_multiple_large_NUMERALS_less_than_max
        ck_assert_str_eq(addRoman("CXXIV", "MIX"), "MCXXXIII");

#test sum_above_max_returns_empty_string
        ck_assert_str_eq(addRoman("MMM", "MMM"), "ERROR");

#test one_invalid_numeral_addition_results_in_error
        ck_assert_str_eq(subtractRoman("I", "PROBLEM"), INVALID_ARABIC_CODE);

#test invalid_NUMERALS_addition_results_in_error
        ck_assert_str_eq(subtractRoman("IAM", "PROBLEM"), INVALID_ARABIC_CODE);

#test subtract_one_from_two
        ck_assert_str_eq(subtractRoman("II", "I"), "I");

#test subtract_subtractive_from_its_base
        ck_assert_str_eq(subtractRoman("V", "IV"), "I");

#test subtract_subtractive_from_larger_number
        ck_assert_str_eq(subtractRoman("X", "IV"), "VI");

#test smaller_minuend_results_in_error
        ck_assert_str_eq(subtractRoman("I", "II"), INVALID_ARABIC_CODE);

#test one_invalid_numeral_subtraction_results_in_error
        ck_assert_str_eq(subtractRoman("I", "PROBLEM"), INVALID_ARABIC_CODE);

#test invalid_NUMERALS_subtraction_results_in_error
        ck_assert_str_eq(subtractRoman("IAM", "PROBLEM"), INVALID_ARABIC_CODE);
