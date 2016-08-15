#include <stdio.h>
#include "libroman.h"

#test converts_one_to_I
        ck_assert_str_eq("I", rom_ToRoman(1));

#test converts_three_to_III
        ck_assert_str_eq("III", rom_ToRoman(3));

#test converts_four_to_IV
        ck_assert_str_eq("IV", rom_ToRoman(4));

#test converts_five_to_V
        ck_assert_str_eq("V", rom_ToRoman(5));

#test converts_forty_four_to_XCIV
        ck_assert_str_eq("XLIV", rom_ToRoman(44));
