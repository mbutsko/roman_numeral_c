#include <stdio.h>
#include "roman.h"

#test add_one_to_one_to_get_two
        ck_assert_str_eq(addRoman("I", "I"), "II");

#test add_multiple_single_numerals_to_get_a_subtractive
        ck_assert_str_eq(addRoman("II", "II"), "IV");

#test add_multiple_large_numerals
        ck_assert_str_eq(addRoman("CXXIV", "MIX"), "MCXXXIII");

#test subtract_one_from_two
        ck_assert_str_eq(subtractRoman("II", "I"), "I");
